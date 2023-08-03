/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * rpcdds_LICENSE file included in this rpcdds distribution.
 *
 *************************************************************************
 * 
 * @file ucarProxy.h
 * This header file contains the declaration of the proxy for all interfaces.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _ucar_PROXY_H_
#define _ucar_PROXY_H_

#include <rpcdds/client/Proxy.h>
#include "ucar.h"
#include "ucarProxyImpl.h"

#include "ucarAsyncCallbackHandlers.h"


namespace eprosima
{
    namespace rpc
    {
        namespace protocol
        {
            class ucarProtocol;
        }
    }
}









/*!
 * @brief This class implements a specific server's proxy for the defined interface UCar.
 * @ingroup UCAR
 */
class RPCUSERDllExport UCarProxy : public eprosima::rpc::proxy::Proxy, public UCar
{
    public:
   
        /*!
         * @brief This constructor sets the transport that will be used by the server's proxy.
         *
         * @param transport The network transport that server's proxy has to use.
         *        This transport's object is not deleted by this class in its destructor. Cannot be NULL.
         * @param protocol The protocol used to send the information over the transport.
         *        This protocol's object is not deleted by this class in its destructor. Cannot be NULL.
         * @exception eprosima::rpc::exception::InitializeException This exception is thrown when the initialization was wrong.
         */
        UCarProxy(eprosima::rpc::strategy::ServerStrategy &strategy, eprosima::rpc::transport::ProxyTransport &transport,
            eprosima::rpc::protocol::ucarProtocol &protocol, UCarProxyImpl &servant);

        //! @brief Destructor.
        virtual ~UCarProxy();

                //! @brief Proxy method for the operation sendTouchEvent.
                bool sendTouchEvent(/*in*/ int32_t action, /*in*/ int32_t width, /*in*/ int32_t height, /*in*/ int32_t count, /*in*/ const LongArray& trackID, /*in*/ const LongArray& x, /*in*/ const LongArray& y);

                //! @brief Proxy asynchronous method for the operation sendTouchEvent.
                void sendTouchEvent_async(UCar_sendTouchEventCallbackHandler &obj, /*in*/ int32_t action, /*in*/ int32_t width, /*in*/ int32_t height, /*in*/ int32_t count, /*in*/ const LongArray& trackID, /*in*/ const LongArray& x, /*in*/ const LongArray& y);

                
                //! @brief Proxy method for the operation sendMicRecordData.
                bool sendMicRecordData(/*in*/ int32_t i, /*in*/ const ShortArray& shorts, /*in*/ int32_t l);

                //! @brief Proxy asynchronous method for the operation sendMicRecordData.
                void sendMicRecordData_async(UCar_sendMicRecordDataCallbackHandler &obj, /*in*/ int32_t i, /*in*/ const ShortArray& shorts, /*in*/ int32_t l);

                
                //! @brief Proxy method for the operation sendKeyEvent.
                bool sendKeyEvent(/*in*/ int32_t keyEventActionType, /*in*/ int32_t keyCodeType, /*in*/ int32_t i);

                //! @brief Proxy asynchronous method for the operation sendKeyEvent.
                void sendKeyEvent_async(UCar_sendKeyEventCallbackHandler &obj, /*in*/ int32_t keyEventActionType, /*in*/ int32_t keyCodeType, /*in*/ int32_t i);

                
                //! @brief Proxy method for the operation sendGotoForeground.
                bool sendGotoForeground();

                //! @brief Proxy asynchronous method for the operation sendGotoForeground.
                void sendGotoForeground_async(UCar_sendGotoForegroundCallbackHandler &obj);

                
                //! @brief Proxy method for the operation sendGotoBackground.
                bool sendGotoBackground();

                //! @brief Proxy asynchronous method for the operation sendGotoBackground.
                void sendGotoBackground_async(UCar_sendGotoBackgroundCallbackHandler &obj);

                
                //! @brief Proxy method for the operation sendVRCMD.
                bool sendVRCMD(/*in*/ int32_t vrcmdType, /*in*/ const std::string& s);

                //! @brief Proxy asynchronous method for the operation sendVRCMD.
                void sendVRCMD_async(UCar_sendVRCMDCallbackHandler &obj, /*in*/ int32_t vrcmdType, /*in*/ const std::string& s);

                
                //! @brief Proxy method for the operation notifyIsCallHungUp.
                bool notifyIsCallHungUp();

                //! @brief Proxy asynchronous method for the operation notifyIsCallHungUp.
                void notifyIsCallHungUp_async(UCar_notifyIsCallHungUpCallbackHandler &obj);

                
                //! @brief Proxy method for the operation notifySwitchDayOrNight.
                bool notifySwitchDayOrNight(/*in*/ int32_t dayNightMode);

                //! @brief Proxy asynchronous method for the operation notifySwitchDayOrNight.
                void notifySwitchDayOrNight_async(UCar_notifySwitchDayOrNightCallbackHandler &obj, /*in*/ int32_t dayNightMode);

                
                //! @brief Proxy method for the operation awakenVoiceAssistant.
                bool awakenVoiceAssistant(/*in*/ const ByteArray& bytes, /*in*/ const AudioFormat& audioFormat);

                //! @brief Proxy asynchronous method for the operation awakenVoiceAssistant.
                void awakenVoiceAssistant_async(UCar_awakenVoiceAssistantCallbackHandler &obj, /*in*/ const ByteArray& bytes, /*in*/ const AudioFormat& audioFormat);

                
                //! @brief Proxy method for the operation presetVendorCustomFields.
                bool presetVendorCustomFields(/*in*/ const ByteArray& bytes);

                //! @brief Proxy asynchronous method for the operation presetVendorCustomFields.
                void presetVendorCustomFields_async(UCar_presetVendorCustomFieldsCallbackHandler &obj, /*in*/ const ByteArray& bytes);

                
                //! @brief Proxy method for the operation presetConnectMode.
                bool presetConnectMode(/*in*/ int32_t connectMode);

                //! @brief Proxy asynchronous method for the operation presetConnectMode.
                void presetConnectMode_async(UCar_presetConnectModeCallbackHandler &obj, /*in*/ int32_t connectMode);

                

                

                

                

                

                

                

                

                

                

                
        






















        private:

            //! \brief Pointer to the server's servant implemented by the user.
            UCarProxyImpl &_impl;
};


#endif // _ucar_PROXY_H_