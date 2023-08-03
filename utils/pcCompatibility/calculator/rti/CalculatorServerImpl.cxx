/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file CalculatorServerImpl.cxx
 * This source file contains the definition of the skeleton for interface Calculator. This definitions have to be implemented.
 *
 * This file was generated by the tool rpcddsgen.
 */
 
#include "CalculatorServerImpl.h"
#include "exceptions/ServerInternalException.h"
#include <iostream>

 
DDS_Long CalculatorServerImpl::addition(/*in*/ DDS_Long x, /*in*/ DDS_Long y) 
{
    DDS_Long  addition_ret = 0;

    addition_ret = x + y;
    std::cout << "\033[34mRTI Connext DDS server: \033[0m" << "addition(" << x << ", " << y << ")" << std::endl;
   
    return addition_ret;
} 
 
DDS_Long CalculatorServerImpl::substraction(/*in*/ DDS_Long x, /*in*/ DDS_Long y) 
{
    DDS_Long  substraction_ret = 0;

    substraction_ret = x - y;
    std::cout << "\033[34mRTI Connext DDS server: \033[0m" << "substraction(" << x << ", " << y << ")" << std::endl;
   
    return substraction_ret;
} 
 
DDS_Long CalculatorServerImpl::multiplication(/*in*/ DDS_Long x, /*in*/ DDS_Long y) 
{
    DDS_Long  multiplication_ret = 0;

    multiplication_ret = x * y;
    std::cout << "\033[34mRTI Connext DDS server: \033[0m" << "multiplication(" << x << ", " << y << ")" << std::endl;
   
    return multiplication_ret;
} 
 
DDS_Long CalculatorServerImpl::division(/*in*/ DDS_Long x, /*in*/ DDS_Long y) 
{
    DDS_Long  division_ret = 0;

    if(y == 0)
    {
        std::cout << "\033[34mRTI Connext DDS server: \033[0m" << "Throwing exception cause division by zero" << std::endl;
        throw eProsima::RPCDDS::ServerInternalException("Division by zero");
    }

    division_ret = x / y;
    std::cout << "\033[34mRTI Connext DDS server: \033[0m" << "division(" << x << ", " << y << ")" << std::endl;
   
    return division_ret;
} 
