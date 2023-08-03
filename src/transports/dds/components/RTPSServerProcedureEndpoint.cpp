/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This copy of FASTRPC is licensed to you under the terms described in the
 * FASTRPC_LICENSE file included in this distribution.
 *
 *************************************************************************/
#include <config.h>

#if RPC_WITH_FASTRTPS

#include "../../../strategies/ServerStrategyImpl.h"
#include "protocols/dds/MessageHeader.h"
#include "utils/dds/Middleware.h"
#include <strategies/ServerStrategy.h>
#include <transports/dds/components/RTPSServerProcedureEndpoint.h>
#include <utils/macros/snprintf.h>

#include <fastrtps/Domain.h>
#include <fastrtps/attributes/PublisherAttributes.h>
#include <fastrtps/attributes/SubscriberAttributes.h>
#include <fastrtps/publisher/Publisher.h>
#include <fastrtps/subscriber/SampleInfo.h>
#include <fastrtps/subscriber/Subscriber.h>

#include <boost/bind/bind.hpp>
#include <boost/config/user.hpp>
#include <boost/thread/mutex.hpp>

using namespace eprosima::rpc;
using namespace ::transport::dds;
using namespace ::protocol::dds;

const char *const CLASS_NAME = "eprosima::rpc::transport::dds::RTPSServerProcedureEndpoint";

RTPSServerProcedureEndpoint::RTPSServerProcedureEndpoint(RTPSServerTransport &transport)
    : m_transport(transport),
      m_writer(NULL),
      m_reader(NULL),
      m_create_data(NULL),
      m_destroy_data(NULL),
      m_process_func(NULL),
      m_dataSize(0),
      m_mutex(NULL),
      m_started(0) {}

RTPSServerProcedureEndpoint::~RTPSServerProcedureEndpoint() { finalize(); }

int RTPSServerProcedureEndpoint::initialize(const char *name, const char *writertypename, const char *writertopicname,
                                            const char *readertypename, const char *readertopicname,
                                            RTPSTransport::Create_data create_data,
                                            RTPSTransport::Destroy_data destroy_data,
                                            RTPSTransport::ProcessFunc processFunc, size_t dataSize) {
    if (name != NULL && readertypename != NULL && create_data != NULL && destroy_data != NULL && processFunc != NULL &&
        dataSize > 0) {
        m_mutex = new boost::mutex();

        if (m_mutex != NULL) {
            m_name = name;
            if (writertypename != NULL) {
                m_writerTypeName = writertypename;
                m_writerTopicName = writertopicname;
            }
            m_readerTypeName = readertypename;
            m_readerTopicName = readertopicname;
            m_create_data = create_data;
            m_destroy_data = destroy_data;
            m_process_func = processFunc;
            m_dataSize = dataSize;
            return 0;
        }
    }

    return -1;
}

void RTPSServerProcedureEndpoint::finalize() {
    if (m_reader != nullptr) {
        eprosima::fastrtps::Domain::removeSubscriber(m_reader);
    }

    if (m_writer != nullptr)
        eprosima::fastrtps::Domain::removePublisher(m_writer);

    if (m_mutex != NULL) {
        delete m_mutex;
        m_mutex = NULL;
    }
}

int RTPSServerProcedureEndpoint::start(const char *const &serviceName, const char *const &instanceName) {
    const char *const METHOD_NAME = "start";
    int returnedValue = -1;

    m_mutex->lock();
    if (m_started++ == 0) {
        if ((returnedValue = createEntities(std::string(serviceName), std::string(instanceName))) != 0) {
            printf("ERROR<%s::%s>: Cannot create the DDS entities\n", CLASS_NAME, METHOD_NAME);
            // TODO Borrar en caso de error los endpo8ints.
            --m_started;
        }
    } else
        returnedValue = 0;

    m_mutex->unlock();

    return returnedValue;
}

void RTPSServerProcedureEndpoint::stop() {
    m_mutex->lock();
    if (--m_started == 0) {
        if (m_writer != NULL) {
            eprosima::fastrtps::Domain::removePublisher(m_writer);
            m_writer = NULL;
        }
        if (m_reader != NULL) {
            eprosima::fastrtps::Domain::removeSubscriber(m_reader);
            m_reader = NULL;
        }
    }

    m_mutex->unlock();
}

int RTPSServerProcedureEndpoint::createEntities(const std::string & /*serviceName*/,
                                                const std::string & /*instanceName*/) {
    const char *const METHOD_NAME = "createEntities";

    eprosima::fastrtps::SubscriberAttributes rQos;

    rQos.topic.topicName = m_readerTopicName;
    rQos.topic.topicDataType = m_readerTypeName.c_str();
    rQos.qos.m_reliability.kind = eprosima::fastrtps::RELIABLE_RELIABILITY_QOS;

    m_reader = eprosima::fastrtps::Domain::createSubscriber(m_transport.getParticipant(), rQos, this);

    if (m_reader != nullptr) {
        if (!m_writerTypeName.empty()) {
            eprosima::fastrtps::PublisherAttributes wQos;

            wQos.topic.topicName = m_writerTopicName;
            wQos.topic.topicDataType = m_writerTypeName;
            wQos.qos.m_reliability.kind = eprosima::fastrtps::RELIABLE_RELIABILITY_QOS;
            wQos.topic.historyQos.depth = 100;

            m_writer = eprosima::fastrtps::Domain::createPublisher(m_transport.getParticipant(), wQos, nullptr);

            if (m_writer != nullptr) {
                // Obtain clientServiceId.
                eprosima::fastrtps::rtps::GUID_t guid = m_writer->getGuid();
                m_proxyId.guidPrefix()[0] = guid.guidPrefix.value[0];
                m_proxyId.guidPrefix()[1] = guid.guidPrefix.value[1];
                m_proxyId.guidPrefix()[2] = guid.guidPrefix.value[2];
                m_proxyId.guidPrefix()[3] = guid.guidPrefix.value[3];
                m_proxyId.guidPrefix()[4] = guid.guidPrefix.value[4];
                m_proxyId.guidPrefix()[5] = guid.guidPrefix.value[5];
                m_proxyId.guidPrefix()[6] = guid.guidPrefix.value[6];
                m_proxyId.guidPrefix()[7] = guid.guidPrefix.value[7];
                m_proxyId.guidPrefix()[8] = guid.guidPrefix.value[8];
                m_proxyId.guidPrefix()[9] = guid.guidPrefix.value[9];
                m_proxyId.guidPrefix()[10] = guid.guidPrefix.value[10];
                m_proxyId.guidPrefix()[11] = guid.guidPrefix.value[11];
                m_proxyId.entityId().entityKey()[0] = guid.entityId.value[0];
                m_proxyId.entityId().entityKey()[1] = guid.entityId.value[1];
                m_proxyId.entityId().entityKey()[2] = guid.entityId.value[2];

                return 0;
            } else {
                printf("ERROR<%s::%s: Cannot create the reply data writer\n", CLASS_NAME, METHOD_NAME);
            }
        } else {
            return 0;
        }

        eprosima::fastrtps::Domain::removeSubscriber(m_reader);
    } else {
        printf("ERROR<%s::%s: Cannot create the request data reader\n", CLASS_NAME, METHOD_NAME);
    }

    return -1;
}

int RTPSServerProcedureEndpoint::sendReply(void *data) {
    const char *const METHOD_NAME = "sendReply";
    //    printf("INFO<%s::%s>:data:%p\n", CLASS_NAME, METHOD_NAME,data);
    int returnedValue = -1;

    if (data != NULL) {
        if (m_writer != nullptr) {
            if (m_writer->write(data)) {
                returnedValue = 0;
            } else {
                printf("ERROR<%s::%s>: Cannot send the reply. Datawriter error.\n", CLASS_NAME, METHOD_NAME);
            }
        } else {
            printf("ERROR<%s::%s>: DataWrite was not created. Maybe this is a oneway procedure.\n", CLASS_NAME,
                   METHOD_NAME);
        }
    } else {
        printf("ERROR<%s::%s>: Bad parameter (requestData)\n", CLASS_NAME, METHOD_NAME);
    }

    return returnedValue;
}

int RTPSServerProcedureEndpoint::broadcast(void *reply) {
    const char *const METHOD_NAME = "broadcast";
    //    printf("INFO<%s::%s>:\n", CLASS_NAME, METHOD_NAME);
    int returnedValue = -1;
    eprosima::rpc::protocol::dds::rpc::ReplyHeader *replyHeader = NULL;

    if (reply != NULL) {
        replyHeader = reinterpret_cast<eprosima::rpc::protocol::dds::rpc::ReplyHeader *>(reply);
        replyHeader->relatedRequestId().writer_guid().entityId().entityKind() = EntityKind_t::ENTITY_KIND_BROADCAST;
        memcpy(replyHeader->relatedRequestId().writer_guid().guidPrefix(), m_proxyId.guidPrefix(), 12);
        memcpy(replyHeader->relatedRequestId().writer_guid().entityId().entityKey(), m_proxyId.entityId().entityKey(), 3);

        bool retWrite = m_writer->write(reply);
        if (retWrite) {
            returnedValue = OK;
        } else {
            printf("ERROR<%s::%s>: Cannot send the broadcast. Datawriter error.\n", CLASS_NAME, METHOD_NAME);
        }
    } else {
        printf("ERROR<%s::%s>: Bad parameter(data)\n", CLASS_NAME, METHOD_NAME);
    }

    return returnedValue;
}

void RTPSServerProcedureEndpoint::onNewDataMessage(eprosima::fastrtps::Subscriber *sub) {
    const char *const METHOD_NAME = "onNewDataMessage";
    //    printf("INFO<%s::%s>:\n", CLASS_NAME, METHOD_NAME);

    eprosima::fastrtps::SampleInfo_t info;
    void *data = m_create_data(m_dataSize);

    while (data != NULL && sub->takeNextData(data, &info)) {
        if (info.sampleKind == eprosima::fastrtps::rtps::ALIVE) {
            m_transport.getStrategy().getImpl()->schedule([ObjectPtr = &m_transport, this, data] {
                ObjectPtr->process(this, data, m_destroy_data);
            });

            // 小心内存泄露，while循环内的data，释放在process中
            data = m_create_data(m_dataSize);
        }
    }

    if (data != NULL) {
        // 只释放while(false)下的data
        m_destroy_data(data);
    }
}

#endif  // RPC_WITH_FASTRTPS
