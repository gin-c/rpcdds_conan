/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * _LICENSE file included in this  distribution.
 *
 *************************************************************************
 *
 * @file AIOpenApi.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}
#endif

#include "AIOpenApi.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

AI::Error::Error() {
    // m_errMsg com.eprosima.idl.parser.typecode.StringTypeCode@291ae
    m_errMsg = "";
    // m_errNo com.eprosima.idl.parser.typecode.PrimitiveTypeCode@16ec5519
    m_errNo = 0;
}

AI::Error::~Error() {}

AI::Error::Error(const Error &x) {
    m_errMsg = x.m_errMsg;
    m_errNo = x.m_errNo;
}

AI::Error::Error(Error &&x) {
    m_errMsg = std::move(x.m_errMsg);
    m_errNo = x.m_errNo;
}

AI::Error &AI::Error::operator=(const Error &x) {

    m_errMsg = x.m_errMsg;
    m_errNo = x.m_errNo;

    return *this;
}

AI::Error &AI::Error::operator=(Error &&x) {

    m_errMsg = std::move(x.m_errMsg);
    m_errNo = x.m_errNo;

    return *this;
}

size_t AI::Error::getMaxCdrSerializedSize(size_t current_alignment) {
    size_t initial_alignment = current_alignment;

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + 255 + 1;

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);

    return current_alignment - initial_alignment;
}

size_t AI::Error::getCdrSerializedSize(const AI::Error &data, size_t current_alignment) {
    (void)data;
    size_t initial_alignment = current_alignment;

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + data.errMsg().size() + 1;

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);

    return current_alignment - initial_alignment;
}

void AI::Error::serialize(eprosima::fastcdr::Cdr &scdr) const {

    scdr << m_errMsg;
    scdr << m_errNo;
}

void AI::Error::deserialize(eprosima::fastcdr::Cdr &dcdr) {

    dcdr >> m_errMsg;
    dcdr >> m_errNo;
}

/*!
 * @brief This function copies the value in member errMsg
 * @param _errMsg New value to be copied in member errMsg
 */
void AI::Error::errMsg(const std::string &_errMsg) { m_errMsg = _errMsg; }

/*!
 * @brief This function moves the value in member errMsg
 * @param _errMsg New value to be moved in member errMsg
 */
void AI::Error::errMsg(std::string &&_errMsg) { m_errMsg = std::move(_errMsg); }

/*!
 * @brief This function returns a constant reference to member errMsg
 * @return Constant reference to member errMsg
 */
const std::string &AI::Error::errMsg() const { return m_errMsg; }

/*!
 * @brief This function returns a reference to member errMsg
 * @return Reference to member errMsg
 */
std::string &AI::Error::errMsg() { return m_errMsg; }
/*!
 * @brief This function sets a value in member errNo
 * @param _errNo New value for member errNo
 */
void AI::Error::errNo(int32_t _errNo) { m_errNo = _errNo; }

/*!
 * @brief This function returns the value of member errNo
 * @return Value of member errNo
 */
int32_t AI::Error::errNo() const { return m_errNo; }

/*!
 * @brief This function returns a reference to member errNo
 * @return Reference to member errNo
 */
int32_t &AI::Error::errNo() { return m_errNo; }
