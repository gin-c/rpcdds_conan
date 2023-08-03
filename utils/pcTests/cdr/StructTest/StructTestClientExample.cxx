/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * FASTRPC_LICENSE file included in this FASTRPC distribution.
 *
 *************************************************************************
 * 
 * @file BasicTypeTestClientExample.cxx
 * This source file shows a simple example of how to create a proxy for an interface.
 *
 * This file was generated by the tool fastrpcgen.
 */

#include "StructTestProxy.h"
#include "StructTest.h"
#include "StructTestCDRProtocol.h"
#include "fastrpc/transports/TCPProxyTransport.h"
#include "fastrpc/exceptions/Exceptions.h"

#include <iostream>
#ifdef __linux
#include <unistd.h>
#endif

using namespace eprosima::rpc;
using namespace ::exception;
using namespace ::transport;
using namespace ::protocol::fastcdr;

int main(int argc, char **argv)
{
    StructTestProtocol *protocol = NULL;
    TCPProxyTransport *transport = NULL;
    StructTestProxy *proxy = NULL;
    
    // Creation of the proxy for interface "StructTest".
    try
    {
        protocol = new StructTestProtocol();
        transport = new TCPProxyTransport("127.0.0.1:8080");
        proxy = new StructTestProxy(*transport, *protocol);
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }
    
    // Create and initialize parameters.
    Envio ev;
    // Create and initialize return value.
    Recepcion duplicate_ret;
        
    ev.dato(10);
    ev.message("HOLA");

    try
    {
        duplicate_ret = proxy->duplicate(ev);

        if(duplicate_ret.devolucion() != 10 ||
                duplicate_ret.message().compare("HOLA") != 0 ||
                ev.dato() != 10 ||
                ev.message().compare("HOLA") != 0)
        {
            std::cout << "TEST FAILED<duplicate>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<duplicate>: " << ex.what() << std::endl;
        _exit(-1);
    }

	Envio ev1;    
	Envio ev2;       
	Recepcion suma_ret;

	ev1.dato(10);
	ev1.message("HOLA");
	ev2.dato(20);
	ev2.message("ADIOS");

    try
    {
        suma_ret = proxy->suma(ev1, ev2);

        if(suma_ret.devolucion() != 30 ||
                suma_ret.message().compare("HOLAADIOS") != 0 ||
                ev1.dato() != 10 ||
                ev1.message().compare("HOLA") != 0 ||
                ev2.dato() != 20 ||
                ev2.message().compare("ADIOS") != 0)
        {
            std::cout << "TEST FAILED<suma>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<suma>: " << ex.what() << std::endl;
        _exit(-1);
    }

    StructTest::InnerStruct inn;
    StructTest::InnerStruct inn_res;

    inn.count(43);
    inn.message("PAPITO");

    try
    {
        inn_res = proxy->inner(inn);

        if(inn.count() != 43 ||
                inn_res.message().compare("PAPITO") != 0)
        {
            std::cout << "TEST FAILED<inner>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<inner>: " << ex.what() << std::endl;
        _exit(-1);
    }

    std::cout << "TEST SUCCESFULLY" << std::endl;

	delete(proxy);
    delete(transport);
    delete(protocol);

	_exit(0);
	return 0;
}
