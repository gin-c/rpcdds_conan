/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * rpcdds_LICENSE file included in this rpcdds distribution.
 *
 *************************************************************************
 * 
 * @file ucarProxyImplExample.h
 * This header file contains an example of the declaration of a servant.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _ucarPROXY_IMPL_EXAMPLE_H_
#define _ucarPROXY_IMPL_EXAMPLE_H_

#include "ucarProxyImpl.h"









/*!
 * @brief This class is an example of a servant and it implements the remote procedures of the servant.
 * @ingroup UCAR
 */
class UCarProxyImplExample : public UCarProxyImpl
{
    public:

        //! @brief The default constructor.
        UCarProxyImplExample(){}

        //! @brief Destructor.
        virtual ~UCarProxyImplExample(){}
 
                
                
                
                
                
                
                
                
                
                
                
                //! @brief Implementation of the remote procedure videoInitialized
                void videoInitializedHandle(/*in*/ int32_t type, /*in*/ const VideoFormat& videFormat);
                
                //! @brief Implementation of the remote procedure videoDataReceived
                void videoDataReceivedHandle(/*in*/ int32_t type, /*in*/ int32_t size, /*in*/ const ByteArray& byte);
                
                //! @brief Implementation of the remote procedure requestGotoHUDesktop
                void requestGotoHUDesktopHandle();
                
                //! @brief Implementation of the remote procedure audioStateChanged
                void audioStateChangedHandle(/*in*/ int32_t var2, /*in*/ const AudioFormat& audioFormat, /*in*/ int32_t playerState);
                
                //! @brief Implementation of the remote procedure audioDataReceived
                void audioDataReceivedHandle(/*in*/ int32_t var2, /*in*/ int32_t var3, /*in*/ const ByteArray& var4);
                
                //! @brief Implementation of the remote procedure musicInfoReceived
                void musicInfoReceivedHandle(/*in*/ const MusicInfo& var2);
                
                //! @brief Implementation of the remote procedure navigationInfoReceived
                void navigationInfoReceivedHandle(/*in*/ const NavigationInfo& var2);
                
                //! @brief Implementation of the remote procedure phoneStateInfoReceived
                void phoneStateInfoReceivedHandle(/*in*/ const PhoneStateInfo& var2);
                
                //! @brief Implementation of the remote procedure micRecordRequest
                void micRecordRequestHandle(/*in*/ const AudioFormat& var2, /*in*/ bool var3);
                
                //! @brief Implementation of the remote procedure userInterventionNeeded
                void userInterventionNeededHandle();
                





















;
};


#endif // _ucarPROXY_IMPL_EXAMPLE_H_