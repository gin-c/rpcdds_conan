/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of FASTRPC is licensed to you under the terms described in the
 * FASTRPC_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file UnionTestClientExample.cxx
 * This source file shows a simple example of how to create a proxy for an interface.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "UnionTestProxy.h"
#include "UnionTest.h"
#include "UnionTestDDSProtocol.h"
#include <transports/dds/RTPSProxyTransport.h>
#include <exceptions/Exceptions.h>

#include <iostream>
#ifdef __linux
#include <unistd.h>
#endif

using namespace eprosima::rpc;
using namespace ::exception;
using namespace ::transport::dds;
using namespace ::protocol::dds;

int main(int argc, char **argv)
{
    UnionTestProtocol *protocol = NULL;
    RTPSProxyTransport *transport = NULL;
    UnionTestProxy *proxy = NULL;
    
    // Creation of the proxy for interface "UnionTest".
    try
    {
        protocol = new UnionTestProtocol();
        transport = new RTPSProxyTransport("UnionTestService", "Instance");
        proxy = new UnionTestProxy(*transport, *protocol);
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }

    Empleado em1;
    Empleado em2;
    Empleado em3;
    Empleado getEmpleado_ret;

    em1.id(1);
    em2.name("PRUEBA");

    try
    {
        getEmpleado_ret = proxy->getEmpleado(em1, em2, em3);

        if(em3._d() != 2 || em3.name().compare("PRUEBA") != 0 ||
                getEmpleado_ret._d() != 1 || getEmpleado_ret.id() != 1 ||
                em2._d() != 1 || em2.id() != 1 ||
                em1._d() != 1 || em1.id() != 1)
        {
            std::cout << "TEST FAILED<getEmpleado>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout <<  "TEST FAILED<getEmpleado>: " << ex.what() << std::endl;
        _exit(-1);
    }

    UnionTest::Jefe je1;
    UnionTest::Jefe je2;
    UnionTest::Jefe je3;
    UnionTest::Jefe getJefe_ret;

    je1.name("PRUEBA");
    je2._d() = UnionTest::SATAN;
    je2.seq().push_back(1);
    je2.seq().push_back(2);

    try
    {
        getJefe_ret = proxy->getJefe(je1, je2, je3);

        if(je3._d() != UnionTest::SATAN || je3.seq().size() != 2 ||
                je3.seq()[0] != 1 || je3.seq()[1] != 2 ||
                getJefe_ret._d() != UnionTest::MALO || getJefe_ret.name().compare("PRUEBA") != 0 ||
                je2._d() != UnionTest::MALO || je2.name().compare("PRUEBA") != 0 ||
                je1._d() != UnionTest::MALO || je1.name().compare("PRUEBA") != 0)
        {
            std::cout << "TEST FAILED<getJefe>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout <<  "TEST FAILED<getJefe>: " << ex.what() << std::endl;
        _exit(-1);
    }

    std::cout << "TEST SUCCESFULLY" << std::endl;

    delete proxy;
    delete transport;
    delete protocol;

    _exit(0);
    return 0;
}
