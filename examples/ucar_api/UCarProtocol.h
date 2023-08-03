/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * rpcdds_LICENSE file included in this rpcdds distribution.
 *
 *************************************************************************
 *
 * @file UCarProtocol.h
 * This header file contains the declaration of the interface for all protocols.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _UCar_PROTOCOL_H_
#define _UCar_PROTOCOL_H_

#include "UCar.h"
#include "UCarAsyncCallbackHandlers.h"
#include "UCarProxyImpl.h"
#include "UCarServerImpl.h"
#include <rpcdds/protocols/Protocol.h>
namespace eprosima {
namespace rpc {
namespace protocol {
/*!
 * @brief Protocol base class for the specific application
 * @ingroup UCAR
 */
class RPCUSERDllExport UCarProtocol : public Protocol {
public:
    /*!
     * @brief This method sets the transport for the communications. It has to be implemented by the children classes.
     * @param transport Transport to use.
     * @return True if the assignment is successful, false otherwise
     */
    virtual bool setTransport(eprosima::rpc::transport::Transport& transport) = 0;

    /*!
     * @brief In some protocols this function activates needed entities to use an interface.
     * @param interfaceName Interface name.
     * @return Whether the activation works successfully.
     */
    virtual bool activateInterface(const char* interfaceName) = 0;

    /*!
     * @brief This method links a specific servant with the protocol.
     * @param s_impl Servant implementation.
     */
    void linkUCarImpl(UCarServerImpl& s_impl) { _UCar_s_impl = &s_impl; }

    /*!
     * @brief This method links a specific proxy with the protocol.
     * @param p_impl Servant implementation.
     */
    void linkUCarNotifyImpl(UCarProxyImpl& p_impl) { _UCar_p_impl = &p_impl; }

    /*!
     * @brief This method implements the proxy part of the protocol for the operation sendTouchEvent.
     *        It has to be implemented by the child classes.
     */
    virtual bool UCar_sendTouchEvent(/*in*/ int32_t action, /*in*/ int32_t width, /*in*/ int32_t height,
                                     /*in*/ int32_t count, /*in*/ const LongArray& trackID, /*in*/ const LongArray& x,
                                     /*in*/ const LongArray& y) = 0;
    /*!
     * @brief This asynchronous method implements the proxy part of the protocol for the operation sendTouchEvent.
     *        It has to be implemented by the child classes.
     */
    virtual void UCar_sendTouchEvent_async(UCar_sendTouchEventCallbackHandler& obj, /*in*/ int32_t action,
                                           /*in*/ int32_t width, /*in*/ int32_t height, /*in*/ int32_t count,
                                           /*in*/ const LongArray& trackID, /*in*/ const LongArray& x,
                                           /*in*/ const LongArray& y) = 0;

    /*!
     * @brief This method implements the proxy part of the protocol for the operation sendMicRecordData.
     *        It has to be implemented by the child classes.
     */
    virtual bool UCar_sendMicRecordData(/*in*/ int32_t i, /*in*/ const ShortArray& shorts, /*in*/ int32_t l) = 0;
    /*!
     * @brief This asynchronous method implements the proxy part of the protocol for the operation sendMicRecordData.
     *        It has to be implemented by the child classes.
     */
    virtual void UCar_sendMicRecordData_async(UCar_sendMicRecordDataCallbackHandler& obj, /*in*/ int32_t i,
                                              /*in*/ const ShortArray& shorts, /*in*/ int32_t l) = 0;

    /*!
     * @brief This method implements the proxy part of the protocol for the operation sendKeyEvent.
     *        It has to be implemented by the child classes.
     */
    virtual bool UCar_sendKeyEvent(/*in*/ int32_t keyEventActionType, /*in*/ int32_t keyCodeType, /*in*/ int32_t i) = 0;
    /*!
     * @brief This asynchronous method implements the proxy part of the protocol for the operation sendKeyEvent.
     *        It has to be implemented by the child classes.
     */
    virtual void UCar_sendKeyEvent_async(UCar_sendKeyEventCallbackHandler& obj, /*in*/ int32_t keyEventActionType,
                                         /*in*/ int32_t keyCodeType, /*in*/ int32_t i) = 0;

    /*!
     * @brief This method implements the proxy part of the protocol for the operation sendGotoForeground.
     *        It has to be implemented by the child classes.
     */
    virtual bool UCar_sendGotoForeground() = 0;
    /*!
     * @brief This asynchronous method implements the proxy part of the protocol for the operation sendGotoForeground.
     *        It has to be implemented by the child classes.
     */
    virtual void UCar_sendGotoForeground_async(UCar_sendGotoForegroundCallbackHandler& obj) = 0;

    /*!
     * @brief This method implements the proxy part of the protocol for the operation sendGotoBackground.
     *        It has to be implemented by the child classes.
     */
    virtual bool UCar_sendGotoBackground() = 0;
    /*!
     * @brief This asynchronous method implements the proxy part of the protocol for the operation sendGotoBackground.
     *        It has to be implemented by the child classes.
     */
    virtual void UCar_sendGotoBackground_async(UCar_sendGotoBackgroundCallbackHandler& obj) = 0;

    /*!
     * @brief This method implements the proxy part of the protocol for the operation sendVRCMD.
     *        It has to be implemented by the child classes.
     */
    virtual bool UCar_sendVRCMD(/*in*/ int32_t vrcmdType, /*in*/ const std::string& s) = 0;
    /*!
     * @brief This asynchronous method implements the proxy part of the protocol for the operation sendVRCMD.
     *        It has to be implemented by the child classes.
     */
    virtual void UCar_sendVRCMD_async(UCar_sendVRCMDCallbackHandler& obj, /*in*/ int32_t vrcmdType,
                                      /*in*/ const std::string& s) = 0;

    /*!
     * @brief This method implements the proxy part of the protocol for the operation notifyIsCallHungUp.
     *        It has to be implemented by the child classes.
     */
    virtual bool UCar_notifyIsCallHungUp() = 0;
    /*!
     * @brief This asynchronous method implements the proxy part of the protocol for the operation notifyIsCallHungUp.
     *        It has to be implemented by the child classes.
     */
    virtual void UCar_notifyIsCallHungUp_async(UCar_notifyIsCallHungUpCallbackHandler& obj) = 0;

    /*!
     * @brief This method implements the proxy part of the protocol for the operation notifySwitchDayOrNight.
     *        It has to be implemented by the child classes.
     */
    virtual bool UCar_notifySwitchDayOrNight(/*in*/ int32_t dayNightMode) = 0;
    /*!
     * @brief This asynchronous method implements the proxy part of the protocol for the operation
     * notifySwitchDayOrNight. It has to be implemented by the child classes.
     */
    virtual void UCar_notifySwitchDayOrNight_async(UCar_notifySwitchDayOrNightCallbackHandler& obj,
                                                   /*in*/ int32_t dayNightMode) = 0;

    /*!
     * @brief This method implements the proxy part of the protocol for the operation awakenVoiceAssistant.
     *        It has to be implemented by the child classes.
     */
    virtual bool UCar_awakenVoiceAssistant(/*in*/ const ByteArray& bytes, /*in*/ const AudioFormat& audioFormat) = 0;
    /*!
     * @brief This asynchronous method implements the proxy part of the protocol for the operation awakenVoiceAssistant.
     *        It has to be implemented by the child classes.
     */
    virtual void UCar_awakenVoiceAssistant_async(UCar_awakenVoiceAssistantCallbackHandler& obj,
                                                 /*in*/ const ByteArray& bytes,
                                                 /*in*/ const AudioFormat& audioFormat) = 0;

    /*!
     * @brief This method implements the proxy part of the protocol for the operation presetVendorCustomFields.
     *        It has to be implemented by the child classes.
     */
    virtual bool UCar_presetVendorCustomFields(/*in*/ const ByteArray& bytes) = 0;
    /*!
     * @brief This asynchronous method implements the proxy part of the protocol for the operation
     * presetVendorCustomFields. It has to be implemented by the child classes.
     */
    virtual void UCar_presetVendorCustomFields_async(UCar_presetVendorCustomFieldsCallbackHandler& obj,
                                                     /*in*/ const ByteArray& bytes) = 0;

    /*!
     * @brief This method implements the proxy part of the protocol for the operation presetConnectMode.
     *        It has to be implemented by the child classes.
     */
    virtual bool UCar_presetConnectMode(/*in*/ int32_t connectMode) = 0;
    /*!
     * @brief This asynchronous method implements the proxy part of the protocol for the operation presetConnectMode.
     *        It has to be implemented by the child classes.
     */
    virtual void UCar_presetConnectMode_async(UCar_presetConnectModeCallbackHandler& obj,
                                              /*in*/ int32_t connectMode) = 0;

    /*!
     * @brief This method implements the proxy part of the protocol for the operation videoInitialized.
     *        It has to be implemented by the child classes.
     */
    virtual void UCar_videoInitialized(/*in*/ int32_t type, /*in*/ const VideoFormat& videFormat) = 0;

    /*!
     * @brief This method implements the proxy part of the protocol for the operation videoDataReceived.
     *        It has to be implemented by the child classes.
     */
    virtual void UCar_videoDataReceived(/*in*/ int32_t type, /*in*/ int32_t size, /*in*/ const ByteArray& byte) = 0;

    /*!
     * @brief This method implements the proxy part of the protocol for the operation requestGotoHUDesktop.
     *        It has to be implemented by the child classes.
     */
    virtual void UCar_requestGotoHUDesktop() = 0;

    /*!
     * @brief This method implements the proxy part of the protocol for the operation audioStateChanged.
     *        It has to be implemented by the child classes.
     */
    virtual void UCar_audioStateChanged(/*in*/ int32_t var2, /*in*/ const AudioFormat& audioFormat,
                                        /*in*/ int32_t playerState) = 0;

    /*!
     * @brief This method implements the proxy part of the protocol for the operation audioDataReceived.
     *        It has to be implemented by the child classes.
     */
    virtual void UCar_audioDataReceived(/*in*/ int32_t var2, /*in*/ int32_t var3, /*in*/ const ByteArray& var4) = 0;

    /*!
     * @brief This method implements the proxy part of the protocol for the operation musicInfoReceived.
     *        It has to be implemented by the child classes.
     */
    virtual void UCar_musicInfoReceived(/*in*/ const MusicInfo& var2) = 0;

    /*!
     * @brief This method implements the proxy part of the protocol for the operation navigationInfoReceived.
     *        It has to be implemented by the child classes.
     */
    virtual void UCar_navigationInfoReceived(/*in*/ const NavigationInfo& var2) = 0;

    /*!
     * @brief This method implements the proxy part of the protocol for the operation phoneStateInfoReceived.
     *        It has to be implemented by the child classes.
     */
    virtual void UCar_phoneStateInfoReceived(/*in*/ const PhoneStateInfo& var2) = 0;

    /*!
     * @brief This method implements the proxy part of the protocol for the operation micRecordRequest.
     *        It has to be implemented by the child classes.
     */
    virtual void UCar_micRecordRequest(/*in*/ const AudioFormat& var2, /*in*/ bool var3) = 0;

    /*!
     * @brief This method implements the proxy part of the protocol for the operation userInterventionNeeded.
     *        It has to be implemented by the child classes.
     */
    virtual void UCar_userInterventionNeeded() = 0;

protected:
    UCarProtocol()
        : Protocol()

          ,
          _UCar_s_impl(NULL)

          ,
          _UCar_p_impl(NULL)

    {}

    virtual ~UCarProtocol() {}

    UCarServerImpl* _UCar_s_impl;

    UCarProxyImpl* _UCar_p_impl;
};
}  // namespace protocol
}  // namespace rpc
}  // namespace eprosima

#endif  // _UCar_PROTOCOL_H_