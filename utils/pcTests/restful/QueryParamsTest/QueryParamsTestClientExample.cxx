/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * FASTRPC_LICENSE file included in this FASTRPC distribution.
 *
 *************************************************************************
 * 
 * @file QueryParamsClientExample.cxx
 * This source file shows a simple example of how to create a proxy for an interface.
 *
 * This file was generated by the tool rpcrestgen.
 */

#include "QueryParamsTestProxy.h"
#include "QueryParamsTest.h"
#include "QueryParamsTestRESTProtocol.h"
#include "fastrpc/transports/HttpProxyTransport.h"
#include "fastrpc/exceptions/Exceptions.h"

#include <iostream>

using namespace eprosima::rpc;
using namespace eprosima::rpc::exception;
using namespace eprosima::rpc::transport;
using namespace eprosima::rpc::protocol::rest;

using namespace std;
using namespace QueryParamsTest;
using namespace ::queryParamsResource;

int main(int argc, char **argv)
{
    QueryParamsTestProtocol *protocol = NULL;
    ProxyTransport *transport = NULL;
    queryParamsResourceProxy *proxy = NULL;

    // Creation of the proxy for interface "queryParamsResource".
    try
    {
        protocol = new QueryParamsTestProtocol();
        transport = new HttpProxyTransport("127.0.0.1:8080");
        proxy = new queryParamsResourceProxy(*transport, *protocol);
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }

    /*********** STRING ***********/

    // Create and initialize parameters.
    string stringP = "sample_string";

    // Create and initialize return value.
    GetStringResponse getString_ret;

    // Call to remote procedure "getString".
    try
    {
        cout << "getString" << endl;
        getString_ret = proxy->getString(stringP);

        if(getString_ret._d() == 1)
        {
            if(getString_ret.xmlGetStringResponse().status() == 200 &&
                    getString_ret.xmlGetStringResponse().xmlRepresentation().compare("<Response>sample_string</Response>") == 0)
            {
                cout << "\tTEST PASSED" << endl;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
    catch(SystemException &ex)
    {
        std::cout << ex.what() << std::endl;
        return 1;
    }
    /******************************/

    /*********** BYTE ***********/

    // Create and initialize parameters.
    char byteP = 'r';

    // Create and initialize return value.
    GetByteResponse getByte_ret;

    // Call to remote procedure "getByte".
    try
    {
        cout << "getByte" << endl;
        getByte_ret = proxy->getByte(byteP);

        if(getByte_ret._d() == 1)
        {
            if(getByte_ret.xmlGetByteResponse().status() == 200 &&
                    getByte_ret.xmlGetByteResponse().xmlRepresentation().compare("<Response>r</Response>") == 0)
            {
                cout << "\tTEST PASSED" << endl;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
    catch(SystemException &ex)
    {
        std::cout << ex.what() << std::endl;
        return 1;
    }
    /******************************/

    /*********** UNSIGNED BYTE ***********/

    // Create and initialize parameters.
    uint8_t unsignedByteP = 's';

    // Create and initialize return value.
    GetUnsignedByteResponse getUnsignedByte_ret;

    // Call to remote procedure "getUnsignedByte".
    try
    {
        cout << "getUnsignedByte" << endl;
        getUnsignedByte_ret = proxy->getUnsignedByte(unsignedByteP);

        if(getUnsignedByte_ret._d() == 1)
        {
            if(getUnsignedByte_ret.xmlGetUnsignedByteResponse().status() == 200 &&
                    getUnsignedByte_ret.xmlGetUnsignedByteResponse().xmlRepresentation().compare("<Response>s</Response>") == 0)
            {
                cout << "\tTEST PASSED" << endl;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
    catch(SystemException &ex)
    {
        std::cout << ex.what() << std::endl;
        return 1;
    }
    /******************************/

    /*********** SHORT ***********/

    // Create and initialize parameters.
    int16_t shortP = -13;

    // Create and initialize return value.
    GetShortResponse getShort_ret;

    // Call to remote procedure "getShort".
    try
    {
        cout << "getShort" << endl;
        getShort_ret = proxy->getShort(shortP);

        if(getShort_ret._d() == 1)
        {
            if(getShort_ret.xmlGetShortResponse().status() == 200 &&
                    getShort_ret.xmlGetShortResponse().xmlRepresentation().compare("<Response>-13</Response>") == 0)
            {
                cout << "\tTEST PASSED" << endl;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
    catch(SystemException &ex)
    {
        std::cout << ex.what() << std::endl;
        return 1;
    }
    /******************************/

    /*********** UNSIGNED SHORT ***********/

    // Create and initialize parameters.
    uint16_t unsignedShortP = 13;

    // Create and initialize return value.
    GetUnsignedShortResponse getUnsignedShort_ret;

    // Call to remote procedure "getUnsignedShort".
    try
    {
        cout << "getUnsignedShort" << endl;
        getUnsignedShort_ret = proxy->getUnsignedShort(unsignedShortP);

        if(getUnsignedShort_ret._d() == 1)
        {
            if(getUnsignedShort_ret.xmlGetUnsignedShortResponse().status() == 200 &&
                    getUnsignedShort_ret.xmlGetUnsignedShortResponse().xmlRepresentation().compare("<Response>13</Response>") == 0)
            {
                cout << "\tTEST PASSED" << endl;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
    catch(SystemException &ex)
    {
        std::cout << ex.what() << std::endl;
        return 1;
    }
    /******************************/

    /*********** INT ***********/

    // Create and initialize parameters.
    int32_t intP = -14;

    // Create and initialize return value.
    GetIntResponse getInt_ret;

    // Call to remote procedure "getInt".
    try
    {
        cout << "getInt" << endl;
        getInt_ret = proxy->getInt(intP);

        if(getInt_ret._d() == 1)
        {
            if(getInt_ret.xmlGetIntResponse().status() == 200 &&
                    getInt_ret.xmlGetIntResponse().xmlRepresentation().compare("<Response>-14</Response>") == 0)
            {
                cout << "\tTEST PASSED" << endl;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
    catch(SystemException &ex)
    {
        std::cout << ex.what() << std::endl;
        return 1;
    }
    /******************************/

    /*********** UNSIGNED INT ***********/

    // Create and initialize parameters.
    uint32_t unsignedIntP = 14;

    // Create and initialize return value.
    GetUnsignedIntResponse getUnsignedInt_ret;

    // Call to remote procedure "getUnsignedInt".
    try
    {
        cout << "getUnsignedInt" << endl;
        getUnsignedInt_ret = proxy->getUnsignedInt(unsignedIntP);

        if(getUnsignedInt_ret._d() == 1)
        {
            if(getUnsignedInt_ret.xmlGetUnsignedIntResponse().status() == 200 &&
                    getUnsignedInt_ret.xmlGetUnsignedIntResponse().xmlRepresentation().compare("<Response>14</Response>") == 0)
            {
                cout << "\tTEST PASSED" << endl;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
    catch(SystemException &ex)
    {
        std::cout << ex.what() << std::endl;
        return 1;
    }
    /******************************/


    /*********** LONG ***********/

    // Create and initialize parameters.
    int64_t longP = -15;

    // Create and initialize return value.
    GetLongResponse getLong_ret;

    // Call to remote procedure "getLong".
    try
    {
        cout << "getLong" << endl;
        getLong_ret = proxy->getLong(longP);

        if(getLong_ret._d() == 1)
        {
            if(getLong_ret.xmlGetLongResponse().status() == 200 &&
                    getLong_ret.xmlGetLongResponse().xmlRepresentation().compare("<Response>-15</Response>") == 0)
            {
                cout << "\tTEST PASSED" << endl;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
    catch(SystemException &ex)
    {
        std::cout << ex.what() << std::endl;
        return 1;
    }
    /******************************/

    /*********** UNSIGNED LONG ***********/

    // Create and initialize parameters.
    uint64_t unsignedLongP = 15;

    // Create and initialize return value.
    GetUnsignedLongResponse getUnsignedLong_ret;

    // Call to remote procedure "getUnsignedLong".
    try
    {
        cout << "getUnsignedLong" << endl;
        getUnsignedLong_ret = proxy->getUnsignedLong(unsignedLongP);

        if(getUnsignedInt_ret._d() == 1)
        {
            if(getUnsignedLong_ret.xmlGetUnsignedLongResponse().status() == 200 &&
                    getUnsignedLong_ret.xmlGetUnsignedLongResponse().xmlRepresentation().compare("<Response>15</Response>") == 0)
            {
                cout << "\tTEST PASSED" << endl;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
    catch(SystemException &ex)
    {
        std::cout << ex.what() << std::endl;
        return 1;
    }
    /******************************/   

    /*********** FLOAT ***********/

    // Create and initialize parameters.
    float floatP = -15.5;

    // Create and initialize return value.
    GetFloatResponse getFloat_ret;

    // Call to remote procedure "getFloat".
    try
    {
        cout << "getFloat" << endl;
        getFloat_ret = proxy->getFloat(floatP);

        if(getLong_ret._d() == 1)
        {
            if(getFloat_ret.xmlGetFloatResponse().status() == 200 &&
                    getFloat_ret.xmlGetFloatResponse().xmlRepresentation().compare("<Response>-15.5</Response>") == 0)
            {
                cout << "\tTEST PASSED" << endl;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
    catch(SystemException &ex)
    {
        std::cout << ex.what() << std::endl;
        return 1;
    }
    /******************************/ 

    /*********** DOUBLE ***********/

    // Create and initialize parameters.
    double doubleP = -16.5;

    // Create and initialize return value.
    GetDoubleResponse getDouble_ret;

    // Call to remote procedure "getDouble".
    try
    {
        cout << "getDouble" << endl;
        getDouble_ret = proxy->getDouble(doubleP);

        if(getDouble_ret._d() == 1)
        {
            if(getDouble_ret.xmlGetDoubleResponse().status() == 200 &&
                    getDouble_ret.xmlGetDoubleResponse().xmlRepresentation().compare("<Response>-16.5</Response>") == 0)
            {
                cout << "\tTEST PASSED" << endl;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
    catch(SystemException &ex)
    {
        std::cout << ex.what() << std::endl;
        return 1;
    }
    /******************************/ 

    /*********** BOOLEAN ***********/

    // Create and initialize parameters.
    bool booleanP = true;

    // Create and initialize return value.
    GetBooleanResponse getBoolean_ret;

    // Call to remote procedure "getBoolean".
    try
    {
        cout << "getBoolean" << endl;
        getBoolean_ret = proxy->getBoolean(booleanP);

        if(getBoolean_ret._d() == 1)
        {
            if(getBoolean_ret.xmlGetBooleanResponse().status() == 200 &&
                    getBoolean_ret.xmlGetBooleanResponse().xmlRepresentation().compare("<Response>true</Response>") == 0)
            {
                cout << "\tTEST PASSED" << endl;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
    catch(SystemException &ex)
    {
        std::cout << ex.what() << std::endl;
        return 1;
    }
    /******************************/ 

    delete(proxy);
    delete(transport);
    delete(protocol);

    return 0;
}



































