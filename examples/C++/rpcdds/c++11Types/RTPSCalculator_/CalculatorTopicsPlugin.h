/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * rpcdds_LICENSE file included in this rpcdds distribution.
 *
 *************************************************************************
 * 
 * @file CalculatorTopicsPlugin.h
 * This header file contains the declaration of methods used by DDS middleware.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _Calculator_TOPICS_PLUGIN_H_
#define _Calculator_TOPICS_PLUGIN_H_

#include "CalculatorTopics.h"
#include <fastrtps/TopicDataType.h>


#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define user_cpp_DllExport __declspec( dllexport )
#else
#define user_cpp_DllExport
#endif
#else
#define user_cpp_DllExport
#endif





/*!
 * @brief This class encapsulates the methods used on DDS topics by DDS middleware.
 */
class Calculator_RequestPlugin : public eprosima::fastrtps::TopicDataType
{
    public:

        user_cpp_DllExport Calculator_RequestPlugin();

        virtual user_cpp_DllExport ~Calculator_RequestPlugin();

        user_cpp_DllExport bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t* ihandle, bool force_md5);

        user_cpp_DllExport bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload);

        user_cpp_DllExport bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data);

        user_cpp_DllExport std::function<uint32_t()> getSerializedSizeProvider(void* data);

        user_cpp_DllExport void* createData();

        user_cpp_DllExport static void* create_data();

        user_cpp_DllExport void deleteData(void *data);

        user_cpp_DllExport static void delete_data(void *data);

        user_cpp_DllExport static void copy_data(Calculator_Request *dst,
                const Calculator_Request *src);
};

/*!
 * @brief This class encapsulates the methods used on DDS topics by DDS middleware.
 */
class Calculator_ReplyPlugin : public eprosima::fastrtps::TopicDataType
{
    public:

        user_cpp_DllExport Calculator_ReplyPlugin();

        virtual user_cpp_DllExport ~Calculator_ReplyPlugin();

        user_cpp_DllExport bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t* ihandle, bool force_md5);

        user_cpp_DllExport bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload);

        user_cpp_DllExport bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data);

        user_cpp_DllExport std::function<uint32_t()> getSerializedSizeProvider(void* data);

        user_cpp_DllExport void* createData();

        user_cpp_DllExport static void* create_data();

        user_cpp_DllExport void deleteData(void *data);

        user_cpp_DllExport static void delete_data(void *data);

        user_cpp_DllExport static void copy_data(Calculator_Reply *dst,
                const Calculator_Reply *src);
};


#endif // _Calculator_TOPICS_PLUGIN_H_