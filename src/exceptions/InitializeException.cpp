/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of FASTRPC is licensed to you under the terms described in the
 * FASTRPC_LICENSE file included in this distribution.
 *
 *************************************************************************/

#include <exceptions/InitializeException.h>

using namespace eprosima::rpc::exception;

InitializeException::InitializeException(const std::string &message) : SystemException(message.c_str(), 1)
{
}

InitializeException::InitializeException(const InitializeException &ex) : SystemException(ex)
{
}

InitializeException::InitializeException(InitializeException&& ex) : SystemException(std::move(ex))
{
}

InitializeException& InitializeException::operator=(const InitializeException &ex)
{
    if(this != &ex)
    {
        SystemException::operator=(ex);
    }

    return *this;
}

InitializeException& InitializeException::operator=(InitializeException&& ex)
{
    if(this != &ex)
    {
        SystemException::operator=(std::move(ex));
    }

    return *this;
}

InitializeException::~InitializeException() throw()
{
}

void InitializeException::raise() const
{
    throw *this;
}
