/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of FASTRPC is licensed to you under the terms described in the
 * FASTRPC_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file ServerExceptionClientExample.cxx
 * This source file shows a simple example of how to create a proxy for an interface.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "ServerExceptionProxy.h"
#include "ServerException.h"
#include "ServerExceptionDDSProtocol.h"
#include "fastrpc/transports/dds/UDPProxyTransport.h"
#include "fastrpc/exceptions/Exceptions.h"

#include <iostream>

using namespace eprosima::rpc;
using namespace ::exception;
using namespace ::transport::dds;
using namespace ::protocol::dds;

int main(int argc, char **argv)
{
    ServerExceptionProtocol *protocol = NULL;
    UDPProxyTransport *transport = NULL;
    ServerExceptionProxy *proxy = NULL;
    
    // Creation of the proxy for interface "ServerException".
    try
    {
        protocol = new ServerExceptionProtocol();
        transport = new UDPProxyTransport("ServerExceptionService", "Instance");
        proxy = new ServerExceptionProxy(*transport, *protocol);
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }

    try
    {
        proxy->sendException();
        std::cout << "TEST FAILED<sendException>: No exception" << std::endl;
        _exit(-1);
    }
    catch(ServerInternalException &ex)
    {
        if(strcmp(ex.what(), "") != 0)
        {
            std::cout << "TEST FAILED<sendException>: Bad exception message" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<sendException>: " << ex.what() << std::endl;
        _exit(-1);
    }

    char*  s1  = DDS_String_dup("PRUEBA");       
    char*  s2  = DDS_String_dup("PRUEBA2");       
    char*  s3  = NULL;    
    char*  sendExceptionTwoRetValue = NULL;  

    try
    {
        sendExceptionTwoRetValue = proxy->sendExceptionTwo(s1, s2, s3);
        std::cout << "TEST FAILED<sendExceptionTwo>: No exception" << std::endl;
        _exit(-1);
    }
    catch(ServerInternalException &ex)
    {
        if(strcmp(ex.what(), "") != 0)
        {
            std::cout << "TEST FAILED<sendExceptionTwo>: Bad exception message" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<sendExceptionTwo>: " << ex.what() << std::endl;
        _exit(-1);
    }

    Estructura es1;
    Estructura es2;
    Estructura es3;
    Estructura sendExceptionThreeRetValue;

    Estructura_initialize(&es1);
    Estructura_initialize(&es2);

    try
    {
        sendExceptionThreeRetValue = proxy->sendExceptionThree(es1, es2, es3);
        std::cout << "TEST FAILED<sendExceptionThree>: No exception" << std::endl;
        _exit(-1);
    }
    catch(ServerInternalException &ex)
    {
        if(strcmp(ex.what(), "") != 0)
        {
            std::cout << "TEST FAILED<sendExceptionThree>: Bad exception message" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<sendExceptionThree>: " << ex.what() << std::endl;
        _exit(-1);
    }

    Estructura_finalize(&es1);
    Estructura_finalize(&es2);

    std::cout << "TEST SUCCESFULLY" << std::endl;

    delete proxy;
    delete transport;
    delete protocol;

	_exit(0);
    return 0;
}
