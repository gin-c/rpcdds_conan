/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * rpcdds_LICENSE file included in this rpcdds distribution.
 *
 *************************************************************************
 * 
 * @file ucarTopicsPlugin.cpp
 * TODO This header file contains the declaration of topics generated using operations in the IDL file.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "ucarTopicsPlugin.h"

#include <fastcdr/Cdr.h>

using namespace eprosima::fastrtps;
using namespace ::rtps;































UCar_RequestPlugin::UCar_RequestPlugin() 
{
    setName("UCar_Request");
    m_typeSize = (uint32_t)UCar_Request::getMaxCdrSerializedSize() + 4 /*encapsulation*/;
    m_isGetKeyDefined = false;
}

UCar_RequestPlugin::~UCar_RequestPlugin() 
{
}

bool UCar_RequestPlugin::getKey(void*, InstanceHandle_t*, bool)
{
    return false;
}

bool UCar_RequestPlugin::serialize(void *data, SerializedPayload_t *payload) 
{
    UCar_Request *p_type = (UCar_Request*) data;

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer((char*) payload->data, payload->max_size);
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
            eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
    payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
    // Serialize encapsulation
    ser.serialize_encapsulation();

    try
    {
        // Serialize the object:
        p_type->serialize(ser);
    }
    catch(eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    //Get the serialized length
    payload->length = (uint16_t)ser.getSerializedDataLength();

    return true;
}

bool UCar_RequestPlugin::deserialize(SerializedPayload_t* payload, void* data)
{
    //CONVERT DATA to pointer of your type
    UCar_Request* p_type = (UCar_Request*) data;

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer((char*)payload->data, payload->length);
    eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
            eprosima::fastcdr::Cdr::DDS_CDR); // Object that deserializes the data.
    // Deserialize encapsulation.
    deser.read_encapsulation();
    payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

    try
    {
        //deserialize the object:
        p_type->deserialize(deser);
    }
    catch(eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    return true;
}

std::function<uint32_t()> UCar_RequestPlugin::getSerializedSizeProvider(void* data)
{
    return [data]() -> uint32_t {
        return UCar_Request::getCdrSerializedSize(*static_cast<UCar_Request*>(data));
    };
}

void* UCar_RequestPlugin::createData()
{
    return (void*)new UCar_Request();
}

void* UCar_RequestPlugin::create_data()
{
    return (void*)new UCar_Request();
}

void UCar_RequestPlugin::deleteData(void* data)
{
    delete((UCar_Request*)data);
}

void UCar_RequestPlugin::delete_data(void* data)
{
    delete((UCar_Request*)data);
}

void UCar_RequestPlugin::copy_data(
        UCar_Request *dst,
        const UCar_Request *src)
{
    *dst = *src;
}

// Reply interfaces
UCar_ReplyPlugin::UCar_ReplyPlugin() 
{
    setName("UCar_Reply");
    m_typeSize = (uint32_t)UCar_Reply::getMaxCdrSerializedSize() + 4 /*encapsulation*/;
    m_isGetKeyDefined = false;
}

UCar_ReplyPlugin::~UCar_ReplyPlugin() 
{
}

bool UCar_ReplyPlugin::getKey(void*, InstanceHandle_t*, bool)
{
    return false;
}

bool UCar_ReplyPlugin::serialize(void *data, SerializedPayload_t *payload) 
{
    UCar_Reply *p_type = (UCar_Reply*) data;

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer((char*) payload->data, payload->max_size);
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
            eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
    payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
    // Serialize encapsulation
    ser.serialize_encapsulation();

    try
    {
        // Serialize the object:
        p_type->serialize(ser);
    }
    catch(eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    //Get the serialized length
    payload->length = (uint16_t)ser.getSerializedDataLength();

    return true;
}

bool UCar_ReplyPlugin::deserialize(SerializedPayload_t* payload, void* data)
{
    //CONVERT DATA to pointer of your type
    UCar_Reply* p_type = (UCar_Reply*) data;

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer((char*)payload->data, payload->length);
    eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
            eprosima::fastcdr::Cdr::DDS_CDR); // Object that deserializes the data.
    // Deserialize encapsulation.
    deser.read_encapsulation();
    payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

    try
    {
        //deserialize the object:
        p_type->deserialize(deser);
    }
    catch(eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    return true;
}

std::function<uint32_t()> UCar_ReplyPlugin::getSerializedSizeProvider(void* data)
{
    return [data]() -> uint32_t {
        return UCar_Reply::getCdrSerializedSize(*static_cast<UCar_Reply*>(data));
    };
}

void* UCar_ReplyPlugin::createData()
{
    return (void*)new UCar_Reply();
}

void* UCar_ReplyPlugin::create_data()
{
    return (void*)new UCar_Reply();
}

void UCar_ReplyPlugin::deleteData(void* data)
{
    delete((UCar_Reply*)data);
}

void UCar_ReplyPlugin::delete_data(void* data)
{
    delete((UCar_Reply*)data);
}

void UCar_ReplyPlugin::copy_data(
        UCar_Reply *dst,
        const UCar_Reply *src)
{
    *dst = *src;
}
