/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * rpcdds_LICENSE file included in this rpcdds distribution.
 *
 *************************************************************************
 *
 * @file CalculatorProxyImplExample.cxx
 * This source file contains an example of the declaration of a servant.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "CalculatorProxyImplExample.h"
#include "iostream"
#include <iomanip>

void CalculatorProxyImplExample::videoInitialized(VideoType type, const VideoFormat& videFormat) {
    std::cout << "===== videoInitialized =====" << std::endl;
    std::cout << "VideoType:" << type << std::endl;
    std::cout << "videFormat.height:" << videFormat.height() << std::endl;
    std::cout << "videFormat.width:" << videFormat.width() << std::endl;
    std::cout << "videFormat.mimeType:" << videFormat.mimeType() << std::endl;
    std::cout << std::endl;
}

void CalculatorProxyImplExample::videoDataReceived(VideoType type, int32_t size, const ByteArray& byte) {
    std::cout << "===== videoDataReceived =====" << std::endl;
    std::cout << "param size:" << size << " byte.size()=" << byte.size() << std::endl;
    if (size > 1) {
        std::cout << "byteArray::" << std::setiosflags(std::ios::uppercase) << std::hex << int(byte[0]) << "..."
                  << std::hex << int(byte[size - 1]) << std::dec << std::endl;
    }
    std::cout << std::endl;
}
