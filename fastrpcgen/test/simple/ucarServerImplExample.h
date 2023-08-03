/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * rpcdds_LICENSE file included in this rpcdds distribution.
 *
 *************************************************************************
 * 
 * @file ucarServerImplExample.h
 * This header file contains an example of the declaration of a servant.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _ucarSERVER_IMPL_EXAMPLE_H_
#define _ucarSERVER_IMPL_EXAMPLE_H_

#include "ucarServerImpl.h"









/*!
 * @brief This class is an example of a servant and it implements the remote procedures of the servant.
 * @ingroup UCAR
 */
class UCarServerImplExample : public UCarServerImpl
{
    public:

        //! @brief The default constructor.
        UCarServerImplExample(){}

        //! @brief Destructor.
        virtual ~UCarServerImplExample(){}
 
                //! @brief Implementation of the remote procedure sendTouchEvent
                bool sendTouchEventHandle(/*in*/ int32_t action, /*in*/ int32_t width, /*in*/ int32_t height, /*in*/ int32_t count, /*in*/ const LongArray& trackID, /*in*/ const LongArray& x, /*in*/ const LongArray& y);
                
                //! @brief Implementation of the remote procedure sendMicRecordData
                bool sendMicRecordDataHandle(/*in*/ int32_t i, /*in*/ const ShortArray& shorts, /*in*/ int32_t l);
                
                //! @brief Implementation of the remote procedure sendKeyEvent
                bool sendKeyEventHandle(/*in*/ int32_t keyEventActionType, /*in*/ int32_t keyCodeType, /*in*/ int32_t i);
                
                //! @brief Implementation of the remote procedure sendGotoForeground
                bool sendGotoForegroundHandle();
                
                //! @brief Implementation of the remote procedure sendGotoBackground
                bool sendGotoBackgroundHandle();
                
                //! @brief Implementation of the remote procedure sendVRCMD
                bool sendVRCMDHandle(/*in*/ int32_t vrcmdType, /*in*/ const std::string& s);
                
                //! @brief Implementation of the remote procedure notifyIsCallHungUp
                bool notifyIsCallHungUpHandle();
                
                //! @brief Implementation of the remote procedure notifySwitchDayOrNight
                bool notifySwitchDayOrNightHandle(/*in*/ int32_t dayNightMode);
                
                //! @brief Implementation of the remote procedure awakenVoiceAssistant
                bool awakenVoiceAssistantHandle(/*in*/ const ByteArray& bytes, /*in*/ const AudioFormat& audioFormat);
                
                //! @brief Implementation of the remote procedure presetVendorCustomFields
                bool presetVendorCustomFieldsHandle(/*in*/ const ByteArray& bytes);
                
                //! @brief Implementation of the remote procedure presetConnectMode
                bool presetConnectModeHandle(/*in*/ int32_t connectMode);
                
                
                
                
                
                
                
                
                
                
                





















;
};


#endif // _ucarSERVER_IMPL_EXAMPLE_H_