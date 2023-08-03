/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of FASTRPC is licensed to you under the terms described in the
 * FASTRPC_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file $ctx.filename$ClientExample.cxx
 * This source file shows a simple example of how to create a proxy for an interface.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "WANTestProxy.h"
#include "WANTest.h"
#include "WANTestDDSProtocol.h"
#include <transports/dds/TCPProxyTransport.h>
#include <exceptions/Exceptions.h>

#include <iostream>

using namespace eprosima::rpc;
using namespace ::exception;
using namespace ::transport::dds;
using namespace ::protocol::dds;

int main(int argc, char **argv)
{
    WANTestProtocol *protocol = NULL;
    TCPProxyTransport *transport = NULL;
    WANTestProxy *proxy = NULL;
    
    // Creation of the proxy for interface "WANTest".
    try
    {
        protocol = new WANTestProtocol();
        transport = new TCPProxyTransport("127.0.0.1:7600", "WANTestService", "Instance");
        proxy = new WANTestProxy(*transport, *protocol);
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }
    
    DDS_Octet  oc1 = oc1_value;    
    DDS_Octet  oc2 = WANTest::oc2_value;    
    DDS_Octet  oc3 = 0;    
    DDS_Octet  getOctetRetValue = 0;       

    try
    {
        getOctetRetValue = proxy->getOctet(oc1, oc2, oc3);

        if(oc3 != 2 ||
                getOctetRetValue != 1 ||
                oc2 != 3 ||
                oc1 != 1)
        {
            std::cout << "TEST FAILED<getOctet>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getOctet>: " <<  ex.what() << std::endl;
        _exit(-1);
    }

    DDS_Char  ch1 = ch1_value;
    DDS_Char  ch2 = WANTest::ch2_value;
    DDS_Char  ch3 = 0; 
    DDS_Char  getCharRetValue = 0;       

    try
    {
        getCharRetValue = proxy->getChar(ch1, ch2, ch3);   

        if(ch3 != 2 ||
                getCharRetValue != 1 ||
                ch2 != 3 ||
                ch1 != 1)
        {
            std::cout << "TEST FAILED<getChar>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getChar>: " << ex.what() << std::endl;
        _exit(-1);
    }

    DDS_Wchar  wch1 = wch1_value;       
    DDS_Wchar  wch2 = WANTest::wch2_value;
    DDS_Wchar  wch3 = 0; 
    DDS_Wchar  getWCharRetValue = 0;       

    try
    {
        getWCharRetValue = proxy->getWChar(wch1, wch2, wch3);

        if(wch3 != 2 ||
                getWCharRetValue != 1 ||
                wch2 != 3 ||
                wch1 != 1)
        {
            std::cout << "TEST FAILED<getWChar>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getWChar>: %s" << ex.what() << std::endl;
        _exit(-1);
    }

    DDS_Short  sh1 = sh1_value;
    DDS_Short  sh2 = WANTest::sh2_value; 
    DDS_Short  sh3 = 0;    
    DDS_Short  getShortRetValue = 0;       

    try
    {
        getShortRetValue = proxy->getShort(sh1, sh2, sh3);

        if(sh3 != 2 ||
                getShortRetValue != 1 ||
                sh2 != 3 ||
                sh1 != 1)
        {
            std::cout << "TEST FAILED<getShort>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getShort>: " << ex.what() << std::endl;
        _exit(-1);
    }

    DDS_UnsignedShort  ush1 = ush1_value;
    DDS_UnsignedShort  ush2 = WANTest::ush2_value;
    DDS_UnsignedShort  ush3 = 0;    
    DDS_UnsignedShort  getUShortRetValue = 0;       

    try
    {
        getUShortRetValue = proxy->getUShort(ush1, ush2, ush3);

        if(ush3 != 2 ||
                getUShortRetValue != 1 ||
                ush2 != 3 ||
                ush1 != 1)
        {
            std::cout << "TEST FAILED<getUShort>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getUShort>: " << ex.what() << std::endl;
        _exit(-1);
    }

    DDS_Long  lo1 = lo1_value;
    DDS_Long  lo2 = WANTest::lo2_value;
    DDS_Long  lo3 = 0;    
    DDS_Long  getLongRetValue = 0;       

    try
    {
        getLongRetValue = proxy->getLong(lo1, lo2, lo3);

        if(lo3 != 2 ||
                getLongRetValue != 1 ||
                lo2 != 3 ||
                lo1 != 1)
        {
            std::cout << "TEST FAILED<getLong>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getLong>: " << ex.what() << std::endl;
        _exit(-1);
    }

    DDS_UnsignedLong  ulo1 = ulo1_value;       
    DDS_UnsignedLong  ulo2 = WANTest::ulo2_value; 
    DDS_UnsignedLong  ulo3 = 0;    
    DDS_UnsignedLong  getULongRetValue = 0;       

    try
    {
        getULongRetValue = proxy->getULong(ulo1, ulo2, ulo3);

        if(ulo3 != 2 ||
                getULongRetValue != 1 ||
                ulo2 != 3 ||
                ulo1 != 1)
        {
            std::cout << "TEST FAILED<getULong>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getULong>: " << ex.what() << std::endl;
        _exit(-1);
    }

    DDS_LongLong  llo1 = llo1_value;
    DDS_LongLong  llo2 = WANTest::llo2_value;
    DDS_LongLong  llo3 = 0;    
    DDS_LongLong  getLLongRetValue = 0;       

    try
    {
        getLLongRetValue = proxy->getLLong(llo1, llo2, llo3);

        if(llo3 != 2 ||
                getLLongRetValue != 1 ||
                llo2 != 3 ||
                llo1 != 1)
        {
            std::cout << "TEST FAILED<getLLong>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getLLong>: " << ex.what() << std::endl;
        _exit(-1);
    }

    DDS_UnsignedLongLong  ullo1 = ullo1_value;
    DDS_UnsignedLongLong  ullo2 = WANTest::ullo2_value;
    DDS_UnsignedLongLong  ullo3 = 0;    
    DDS_UnsignedLongLong  getULLongRetValue = 0;       

    try
    {
        getULLongRetValue = proxy->getULLong(ullo1, ullo2, ullo3);

        if(ullo3 != 2 ||
                getULLongRetValue != 1 ||
                ullo2 != 3 ||
                ullo1 != 1)
        {
            std::cout << "TEST FAILED<getULLong>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getULLong>: " << ex.what() << std::endl;
        _exit(-1);
    }

    DDS_Float  fl1 = fl1_value;
    DDS_Float  fl2 = WANTest::fl2_value; 
    DDS_Float  fl3 = 0;    
    DDS_Float  getFloatRetValue = 0;       

    try
    {
        getFloatRetValue = proxy->getFloat(fl1, fl2, fl3);

        if(fl3 != 2.0 ||
                getFloatRetValue != 1.0 ||
                fl2 != 3.0 ||
                fl1 != 1.0)
        {
            std::cout << "TEST FAILED<getFloat>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getFloat>: " << ex.what() << std::endl;
        _exit(-1);
    }

    DDS_Double  do1 = do1_value;
    DDS_Double  do2 = WANTest::do2_value; 
    DDS_Double  do3 = 0;    
    DDS_Double  getDoubleRetValue = 0;       

    try
    {
        getDoubleRetValue = proxy->getDouble(do1, do2, do3);

        if(do3 != 2.0 ||
                getDoubleRetValue != 1.0 ||
                do2 != 3.0 ||
                do1 != 1.0)
        {
            std::cout << "TEST FAILED<getDouble>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getDouble>: " << ex.what() << std::endl;
        _exit(-1);
    }

    DDS_Boolean  bo1 = bo1_value;
    DDS_Boolean  bo2 = WANTest::bo2_value;
    DDS_Boolean  bo3 = RTI_FALSE;    
    DDS_Boolean  getBooleanRetValue = RTI_FALSE;       

    try
    {
        getBooleanRetValue = proxy->getBoolean(bo1, bo2, bo3);

        if(bo3 != RTI_FALSE ||
                getBooleanRetValue != RTI_TRUE ||
                bo2 != RTI_TRUE ||
                bo1 != RTI_TRUE)
        {
            std::cout << "TEST FAILED<getBoolean>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getBoolean>: " << ex.what() << std::endl;
        _exit(-1);
    }

    std::cout << "TEST SUCCESFULLY" << std::endl;

    delete(proxy);
    delete(transport);
    delete(protocol);

    _exit(0);
    return 0;
}
