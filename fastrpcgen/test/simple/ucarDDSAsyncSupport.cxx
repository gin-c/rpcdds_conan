/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * rpcdds_LICENSE file included in this rpcdds distribution.
 *
 *************************************************************************
 * 
 * @file ucarAsyncSupport.cxx
 * This source file contains functionality to use asynchronous calls for all interfaces.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "ucarDDSAsyncSupport.h"
#include <rpcdds/exceptions/ServerInternalException.h>
#include <rpcdds/exceptions/ClientInternalException.h>
#include <rpcdds/utils/Messages.h>

using namespace eprosima::rpc;
using namespace ::exception;









UCar_sendTouchEventTask::UCar_sendTouchEventTask(UCar_sendTouchEventCallbackHandler &obj) :
    RTPSAsyncTask(), m_obj(obj)
{
}

UCar_sendTouchEventTask::~UCar_sendTouchEventTask()
{
}

UCar_sendTouchEventCallbackHandler& UCar_sendTouchEventTask::getObject()
{
    return m_obj;
}

void* UCar_sendTouchEventTask::getReplyInstance()
{
    return &m_reply;
}

void UCar_sendTouchEventTask::execute()
{  
    bool  return_ = false;
    
    if(m_reply.header().remoteEx() == eprosima::rpc::protocol::dds::rpc::REMOTE_EX_OK)
    {
        switch (m_reply.data().sendTouchEvent()._d())
        {
            case 0:
                return_ = m_reply.data().sendTouchEvent().result().return_();
	    	    getObject().sendTouchEvent(return_);
                break;
            default:
                getObject().on_exception(ClientInternalException("Error extracting information from server"));
        }
    }
    else
        getObject().on_exception(ServerInternalException(""));
}

void UCar_sendTouchEventTask::on_exception(const SystemException &ex)
{
    getObject().on_exception(ex);
}


UCar_sendMicRecordDataTask::UCar_sendMicRecordDataTask(UCar_sendMicRecordDataCallbackHandler &obj) :
    RTPSAsyncTask(), m_obj(obj)
{
}

UCar_sendMicRecordDataTask::~UCar_sendMicRecordDataTask()
{
}

UCar_sendMicRecordDataCallbackHandler& UCar_sendMicRecordDataTask::getObject()
{
    return m_obj;
}

void* UCar_sendMicRecordDataTask::getReplyInstance()
{
    return &m_reply;
}

void UCar_sendMicRecordDataTask::execute()
{  
    bool  return_ = false;
    
    if(m_reply.header().remoteEx() == eprosima::rpc::protocol::dds::rpc::REMOTE_EX_OK)
    {
        switch (m_reply.data().sendMicRecordData()._d())
        {
            case 0:
                return_ = m_reply.data().sendMicRecordData().result().return_();
	    	    getObject().sendMicRecordData(return_);
                break;
            default:
                getObject().on_exception(ClientInternalException("Error extracting information from server"));
        }
    }
    else
        getObject().on_exception(ServerInternalException(""));
}

void UCar_sendMicRecordDataTask::on_exception(const SystemException &ex)
{
    getObject().on_exception(ex);
}


UCar_sendKeyEventTask::UCar_sendKeyEventTask(UCar_sendKeyEventCallbackHandler &obj) :
    RTPSAsyncTask(), m_obj(obj)
{
}

UCar_sendKeyEventTask::~UCar_sendKeyEventTask()
{
}

UCar_sendKeyEventCallbackHandler& UCar_sendKeyEventTask::getObject()
{
    return m_obj;
}

void* UCar_sendKeyEventTask::getReplyInstance()
{
    return &m_reply;
}

void UCar_sendKeyEventTask::execute()
{  
    bool  return_ = false;
    
    if(m_reply.header().remoteEx() == eprosima::rpc::protocol::dds::rpc::REMOTE_EX_OK)
    {
        switch (m_reply.data().sendKeyEvent()._d())
        {
            case 0:
                return_ = m_reply.data().sendKeyEvent().result().return_();
	    	    getObject().sendKeyEvent(return_);
                break;
            default:
                getObject().on_exception(ClientInternalException("Error extracting information from server"));
        }
    }
    else
        getObject().on_exception(ServerInternalException(""));
}

void UCar_sendKeyEventTask::on_exception(const SystemException &ex)
{
    getObject().on_exception(ex);
}


UCar_sendGotoForegroundTask::UCar_sendGotoForegroundTask(UCar_sendGotoForegroundCallbackHandler &obj) :
    RTPSAsyncTask(), m_obj(obj)
{
}

UCar_sendGotoForegroundTask::~UCar_sendGotoForegroundTask()
{
}

UCar_sendGotoForegroundCallbackHandler& UCar_sendGotoForegroundTask::getObject()
{
    return m_obj;
}

void* UCar_sendGotoForegroundTask::getReplyInstance()
{
    return &m_reply;
}

void UCar_sendGotoForegroundTask::execute()
{  
    bool  return_ = false;
    
    if(m_reply.header().remoteEx() == eprosima::rpc::protocol::dds::rpc::REMOTE_EX_OK)
    {
        switch (m_reply.data().sendGotoForeground()._d())
        {
            case 0:
                return_ = m_reply.data().sendGotoForeground().result().return_();
	    	    getObject().sendGotoForeground(return_);
                break;
            default:
                getObject().on_exception(ClientInternalException("Error extracting information from server"));
        }
    }
    else
        getObject().on_exception(ServerInternalException(""));
}

void UCar_sendGotoForegroundTask::on_exception(const SystemException &ex)
{
    getObject().on_exception(ex);
}


UCar_sendGotoBackgroundTask::UCar_sendGotoBackgroundTask(UCar_sendGotoBackgroundCallbackHandler &obj) :
    RTPSAsyncTask(), m_obj(obj)
{
}

UCar_sendGotoBackgroundTask::~UCar_sendGotoBackgroundTask()
{
}

UCar_sendGotoBackgroundCallbackHandler& UCar_sendGotoBackgroundTask::getObject()
{
    return m_obj;
}

void* UCar_sendGotoBackgroundTask::getReplyInstance()
{
    return &m_reply;
}

void UCar_sendGotoBackgroundTask::execute()
{  
    bool  return_ = false;
    
    if(m_reply.header().remoteEx() == eprosima::rpc::protocol::dds::rpc::REMOTE_EX_OK)
    {
        switch (m_reply.data().sendGotoBackground()._d())
        {
            case 0:
                return_ = m_reply.data().sendGotoBackground().result().return_();
	    	    getObject().sendGotoBackground(return_);
                break;
            default:
                getObject().on_exception(ClientInternalException("Error extracting information from server"));
        }
    }
    else
        getObject().on_exception(ServerInternalException(""));
}

void UCar_sendGotoBackgroundTask::on_exception(const SystemException &ex)
{
    getObject().on_exception(ex);
}


UCar_sendVRCMDTask::UCar_sendVRCMDTask(UCar_sendVRCMDCallbackHandler &obj) :
    RTPSAsyncTask(), m_obj(obj)
{
}

UCar_sendVRCMDTask::~UCar_sendVRCMDTask()
{
}

UCar_sendVRCMDCallbackHandler& UCar_sendVRCMDTask::getObject()
{
    return m_obj;
}

void* UCar_sendVRCMDTask::getReplyInstance()
{
    return &m_reply;
}

void UCar_sendVRCMDTask::execute()
{  
    bool  return_ = false;
    
    if(m_reply.header().remoteEx() == eprosima::rpc::protocol::dds::rpc::REMOTE_EX_OK)
    {
        switch (m_reply.data().sendVRCMD()._d())
        {
            case 0:
                return_ = m_reply.data().sendVRCMD().result().return_();
	    	    getObject().sendVRCMD(return_);
                break;
            default:
                getObject().on_exception(ClientInternalException("Error extracting information from server"));
        }
    }
    else
        getObject().on_exception(ServerInternalException(""));
}

void UCar_sendVRCMDTask::on_exception(const SystemException &ex)
{
    getObject().on_exception(ex);
}


UCar_notifyIsCallHungUpTask::UCar_notifyIsCallHungUpTask(UCar_notifyIsCallHungUpCallbackHandler &obj) :
    RTPSAsyncTask(), m_obj(obj)
{
}

UCar_notifyIsCallHungUpTask::~UCar_notifyIsCallHungUpTask()
{
}

UCar_notifyIsCallHungUpCallbackHandler& UCar_notifyIsCallHungUpTask::getObject()
{
    return m_obj;
}

void* UCar_notifyIsCallHungUpTask::getReplyInstance()
{
    return &m_reply;
}

void UCar_notifyIsCallHungUpTask::execute()
{  
    bool  return_ = false;
    
    if(m_reply.header().remoteEx() == eprosima::rpc::protocol::dds::rpc::REMOTE_EX_OK)
    {
        switch (m_reply.data().notifyIsCallHungUp()._d())
        {
            case 0:
                return_ = m_reply.data().notifyIsCallHungUp().result().return_();
	    	    getObject().notifyIsCallHungUp(return_);
                break;
            default:
                getObject().on_exception(ClientInternalException("Error extracting information from server"));
        }
    }
    else
        getObject().on_exception(ServerInternalException(""));
}

void UCar_notifyIsCallHungUpTask::on_exception(const SystemException &ex)
{
    getObject().on_exception(ex);
}


UCar_notifySwitchDayOrNightTask::UCar_notifySwitchDayOrNightTask(UCar_notifySwitchDayOrNightCallbackHandler &obj) :
    RTPSAsyncTask(), m_obj(obj)
{
}

UCar_notifySwitchDayOrNightTask::~UCar_notifySwitchDayOrNightTask()
{
}

UCar_notifySwitchDayOrNightCallbackHandler& UCar_notifySwitchDayOrNightTask::getObject()
{
    return m_obj;
}

void* UCar_notifySwitchDayOrNightTask::getReplyInstance()
{
    return &m_reply;
}

void UCar_notifySwitchDayOrNightTask::execute()
{  
    bool  return_ = false;
    
    if(m_reply.header().remoteEx() == eprosima::rpc::protocol::dds::rpc::REMOTE_EX_OK)
    {
        switch (m_reply.data().notifySwitchDayOrNight()._d())
        {
            case 0:
                return_ = m_reply.data().notifySwitchDayOrNight().result().return_();
	    	    getObject().notifySwitchDayOrNight(return_);
                break;
            default:
                getObject().on_exception(ClientInternalException("Error extracting information from server"));
        }
    }
    else
        getObject().on_exception(ServerInternalException(""));
}

void UCar_notifySwitchDayOrNightTask::on_exception(const SystemException &ex)
{
    getObject().on_exception(ex);
}


UCar_awakenVoiceAssistantTask::UCar_awakenVoiceAssistantTask(UCar_awakenVoiceAssistantCallbackHandler &obj) :
    RTPSAsyncTask(), m_obj(obj)
{
}

UCar_awakenVoiceAssistantTask::~UCar_awakenVoiceAssistantTask()
{
}

UCar_awakenVoiceAssistantCallbackHandler& UCar_awakenVoiceAssistantTask::getObject()
{
    return m_obj;
}

void* UCar_awakenVoiceAssistantTask::getReplyInstance()
{
    return &m_reply;
}

void UCar_awakenVoiceAssistantTask::execute()
{  
    bool  return_ = false;
    
    if(m_reply.header().remoteEx() == eprosima::rpc::protocol::dds::rpc::REMOTE_EX_OK)
    {
        switch (m_reply.data().awakenVoiceAssistant()._d())
        {
            case 0:
                return_ = m_reply.data().awakenVoiceAssistant().result().return_();
	    	    getObject().awakenVoiceAssistant(return_);
                break;
            default:
                getObject().on_exception(ClientInternalException("Error extracting information from server"));
        }
    }
    else
        getObject().on_exception(ServerInternalException(""));
}

void UCar_awakenVoiceAssistantTask::on_exception(const SystemException &ex)
{
    getObject().on_exception(ex);
}


UCar_presetVendorCustomFieldsTask::UCar_presetVendorCustomFieldsTask(UCar_presetVendorCustomFieldsCallbackHandler &obj) :
    RTPSAsyncTask(), m_obj(obj)
{
}

UCar_presetVendorCustomFieldsTask::~UCar_presetVendorCustomFieldsTask()
{
}

UCar_presetVendorCustomFieldsCallbackHandler& UCar_presetVendorCustomFieldsTask::getObject()
{
    return m_obj;
}

void* UCar_presetVendorCustomFieldsTask::getReplyInstance()
{
    return &m_reply;
}

void UCar_presetVendorCustomFieldsTask::execute()
{  
    bool  return_ = false;
    
    if(m_reply.header().remoteEx() == eprosima::rpc::protocol::dds::rpc::REMOTE_EX_OK)
    {
        switch (m_reply.data().presetVendorCustomFields()._d())
        {
            case 0:
                return_ = m_reply.data().presetVendorCustomFields().result().return_();
	    	    getObject().presetVendorCustomFields(return_);
                break;
            default:
                getObject().on_exception(ClientInternalException("Error extracting information from server"));
        }
    }
    else
        getObject().on_exception(ServerInternalException(""));
}

void UCar_presetVendorCustomFieldsTask::on_exception(const SystemException &ex)
{
    getObject().on_exception(ex);
}


UCar_presetConnectModeTask::UCar_presetConnectModeTask(UCar_presetConnectModeCallbackHandler &obj) :
    RTPSAsyncTask(), m_obj(obj)
{
}

UCar_presetConnectModeTask::~UCar_presetConnectModeTask()
{
}

UCar_presetConnectModeCallbackHandler& UCar_presetConnectModeTask::getObject()
{
    return m_obj;
}

void* UCar_presetConnectModeTask::getReplyInstance()
{
    return &m_reply;
}

void UCar_presetConnectModeTask::execute()
{  
    bool  return_ = false;
    
    if(m_reply.header().remoteEx() == eprosima::rpc::protocol::dds::rpc::REMOTE_EX_OK)
    {
        switch (m_reply.data().presetConnectMode()._d())
        {
            case 0:
                return_ = m_reply.data().presetConnectMode().result().return_();
	    	    getObject().presetConnectMode(return_);
                break;
            default:
                getObject().on_exception(ClientInternalException("Error extracting information from server"));
        }
    }
    else
        getObject().on_exception(ServerInternalException(""));
}

void UCar_presetConnectModeTask::on_exception(const SystemException &ex)
{
    getObject().on_exception(ex);
}
































