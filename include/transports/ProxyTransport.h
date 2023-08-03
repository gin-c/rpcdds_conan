/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This copy of FASTRPC is licensed to you under the terms described in the
 * FASTRPC_LICENSE file included in this distribution.
 *
 *************************************************************************/

#ifndef _TRANSPORTS_PROXYTRANSPORT_H_
#define _TRANSPORTS_PROXYTRANSPORT_H_

#include "../rpc_dll.h"
#include "Transport.h"
#include "components/Endpoint.h"

#include <cstddef>

namespace eprosima
{
    namespace rpc
    {
        namespace protocol
        {
        class Protocol;
        }


        namespace strategy
        {
        class ServerStrategy;
        }

        namespace transport
        {
            /*!
             * @brief This interface is the base of all classes that implement a transport
             *        that can be used by the proxy.
             * @ingroup TRANSPORTMODULE
             */
            class RPC_DllAPI ProxyTransport : public Transport
            {
                typedef size_t (*ProxyTransport_Callback)(eprosima::rpc::protocol::Protocol&, void*&, size_t&, size_t&, Endpoint*);

                public:

                    //! \brief Default constructor.
                    ProxyTransport(): m_strategy(NULL), m_protocol(NULL), m_callback(NULL)
                    {}

                    //! \brief Default destructor.
                    virtual ~ProxyTransport(){}

                    /*!
                     * @brief This function returns the type of the transport.
                     *        This function has to be implemented by the child classes.
                     */
                    virtual const char* getType() const = 0;
                    /*!
					 * @brief Sets the threading strategy.
					 * @param strategy Threading strategy.
                     */
                    inline
                        void setStrategy(eprosima::rpc::strategy::ServerStrategy &strategy)
                    {
                        m_strategy = &strategy;
                    }

                    /*!
					 * @brief Sets the communication protocol.
					 * @param protocol Communication protocol.
                     */
                    inline
                        void linkProtocol(eprosima::rpc::protocol::Protocol &protocol)
                    {
                        m_protocol = &protocol;
                    }

                    /*!
					 * @brief Gets the communication protocol.
					 * @return Communication protocol.
                     */
                    inline
                        eprosima::rpc::protocol::Protocol& getLinkedProtocol()
                    {
                        return *m_protocol;
                    }

                    /*!
					 * @brief Gets the threading strategy.
					 * @return Threading strategy.
                     */
                    inline
                        eprosima::rpc::strategy::ServerStrategy& getStrategy() const
                    {
                        return *m_strategy;
                    }

                    /*!
					 * @brief Gets the callback that will proccess the requests.
					 * @return Callback that will proccess the requests.
                     */
                    inline
                        ProxyTransport_Callback getCallback() const
                    {
                        return m_callback;
                    }

                    /*!
					 * @brief Gets the callback that will proccess the requests.
					 * @param Callback Callback that will proccess the requests.
                     */
                    void setCallback(ProxyTransport_Callback callback)
                    {
                        m_callback = callback;
                    }

                    /*!
                     * @brief This function returns the behaviour of the transport.
                     * @return The behaviour of the transport.
                     */
                    TransportBehaviour getBehaviour() const
                    {
                        return PROXY_BEHAVIOUR;
                    }

					/*!
					 * @brief Abstract method. It must start a connection with the server.
					 * @return true if the operation is successful, false otherwise.
					 */
                    virtual bool connect() = 0;

					/*!
					 * @brief Abstract method. It must send a request to the server.
					 * @param buffer Buffer containing the request
					 * @param bufferSize Buffer size
					 * @return true if the operation is successful, false otherwise.
					 */
                    virtual bool send(const void* buffer, const size_t bufferSize) = 0;

					/*!
					 * @brief Abstract method. It must receive a reply from the server.
					 * @param buffer Buffer that will contain the HTTP message.
					 * @param bufferSize Size of the buffer.
					 * @param dataToRead Number of bytes received.
					 * @return -1 if the operation fails.
					 */
                    virtual int receive(void *buffer, const size_t bufferSize, size_t &dataToRead) = 0;
                private:

                    eprosima::rpc::strategy::ServerStrategy *m_strategy;

                    eprosima::rpc::protocol::Protocol *m_protocol;

                    ProxyTransport_Callback m_callback;
            };
        }
        // namespace transport
    }// namespace rpc
} // namespace eprosima
#endif // _TRANSPORTS_PROXYTRANSPORT_H_
