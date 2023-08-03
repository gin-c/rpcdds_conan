/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * fastrpc_LICENSE file included in this fastrpc distribution.
 *
 *************************************************************************
 * 
 * @file CalculatorServerImpl.h
 * This header file contains the declaration of the skeleton for all interfaces.
 *
 * This file was generated by the tool fastrpcgen.
 */

#ifndef _CalculatorSERVER_IMPL_H_
#define _CalculatorSERVER_IMPL_H_

#include "fastrpc/utils/Messages.h"
#include "Calculator.h"

/*!
 * @brief This class is the skeleton of the servant and its remote procedures has to be implemented.
 * @ingroup CALCULATOR
 */
class CalculatorServerImpl
{
    public:

        //! @brief The default constructor.
        CalculatorServerImpl(){}

        //! @brief Destructor.
        virtual ~CalculatorServerImpl(){}

        //! @brief Skeleton of the operation addition.
        virtual int32_t addition(/*in*/ int32_t value1, /*in*/ int32_t value2) = 0;

        //! @brief Skeleton of the operation subtraction.
        virtual int32_t subtraction(/*in*/ int32_t value1, /*in*/ int32_t value2) = 0;
;
};


#endif // _CalculatorSERVER_IMPL_H_