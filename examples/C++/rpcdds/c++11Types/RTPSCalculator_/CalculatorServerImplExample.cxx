/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * rpcdds_LICENSE file included in this rpcdds distribution.
 *
 *************************************************************************
 *
 * @file CalculatorServerImplExample.cxx
 * This source file contains an example of the declaration of a servant.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "CalculatorServerImplExample.h"
#include "iostream"
bool CalculatorServerImplExample::sendTouchEvent(int32_t action, int32_t width, int32_t height, int32_t count,
                                                 const std::vector<int32_t>& trackID, const std::vector<int32_t>& x,
                                                 const std::vector<int32_t>& y) {
    std::cout << "===== sendTouchEvent =====" << std::endl;
    std::cout << "action:" << action << std::endl;
    std::cout << "width:" << width << std::endl;
    std::cout << "height:" << height << std::endl;
    std::cout << "count:" << count << std::endl;
    std::cout << "trackID:";
    for (auto& i : trackID) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "x:";
    for (auto& i : x) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "y:";
    for (auto& i : y) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return true;
}

bool CalculatorServerImplExample::sendGotoForeground() {
    std::cout << "===== sendTouchEvent =====" << std::endl;
    return true;
}