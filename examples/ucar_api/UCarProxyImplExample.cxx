/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * rpcdds_LICENSE file included in this rpcdds distribution.
 *
 *************************************************************************
 *
 * @file UCarProxyImplExample.cxx
 * This source file contains an example of the declaration of a servant.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "UCarProxyImplExample.h"

#include "iostream"
#include <iomanip>

void UCarProxyImplExample::videoInitializedHandle(const std::string& sendId, int32_t type,
                                                  const VideoFormat& videFormat) {
    std::cout << "===== onVideoInitialized =====" << std::endl;
    std::cout << "int32_t:" << type << std::endl;
    std::cout << "videFormat.height:" << videFormat.height() << std::endl;
    std::cout << "videFormat.width:" << videFormat.width() << std::endl;
    std::cout << "videFormat.mimeType:" << videFormat.mimeType() << std::endl;
    std::cout << std::endl;
}

void UCarProxyImplExample::videoDataReceivedHandle(const std::string& sendId, int32_t type, int32_t size,
                                                   const ByteArray& byte) {
    std::cout << "===== onVideoDataReceived =====" << std::endl;
    std::cout << "param size:" << size << " byte.size()=" << byte.size() << std::endl;
    if (size > 1) {
        std::cout << "byteArray::" << std::setiosflags(std::ios::uppercase) << std::hex << int(byte[0]) << "..."
                  << std::hex << int(byte[size - 1]) << std::dec << std::endl;
    }
    std::cout << std::endl;
}

void UCarProxyImplExample::requestGotoHUDesktopHandle(const std::string& sendId) {}
void UCarProxyImplExample::audioStateChangedHandle(const std::string& sendId, int32_t var2,
                                                   const AudioFormat& audioFormat, int32_t playerState) {}
void UCarProxyImplExample::audioDataReceivedHandle(const std::string& sendId, int32_t var2, int32_t var3,
                                                   const ByteArray& var4) {}
void UCarProxyImplExample::musicInfoReceivedHandle(const std::string& sendId, const MusicInfo& var2) {}
void UCarProxyImplExample::navigationInfoReceivedHandle(const std::string& sendId, const NavigationInfo& var2) {}
void UCarProxyImplExample::phoneStateInfoReceivedHandle(const std::string& sendId, const PhoneStateInfo& var2) {}
void UCarProxyImplExample::micRecordRequestHandle(const std::string& sendId, const AudioFormat& var2, bool var3) {}
void UCarProxyImplExample::userInterventionNeededHandle(const std::string& sendId) {}