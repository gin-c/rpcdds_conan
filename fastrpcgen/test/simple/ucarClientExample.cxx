/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * rpcdds_LICENSE file included in this rpcdds distribution.
 *
 *************************************************************************
 * 
 * @file ucarClientExample.cxx
 * This source file shows a simple example of how to create a proxy for an interface.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "ucarProxy.h"
#include "ucar.h"
#include "ucarDDSProtocol.h"
#include <rpcdds/strategies/ThreadPoolStrategy.h>
#include <rpcdds/transports/dds/RTPSProxyTransport.h>
#include <rpcdds/exceptions/Exceptions.h>
#include <rpcdds/utils/Utilities.h>
#include "ucarProxyImplExample.h"

#include <iostream>

using namespace eprosima::rpc;
using namespace ::exception;
using namespace ::transport::dds;
using namespace ::protocol::dds;
using namespace ::strategy;

int main(int argc, char **argv)
{
    unsigned int threadPoolSize = 5;
    ThreadPoolStrategy *pool = NULL;
    ucarProtocol *protocol = NULL;
    RTPSProxyTransport *transport = NULL;
    UCarProxy *proxy = NULL;
    UCarProxyImplExample servant;
    
    // Creation of the proxy for interface "UCar".
    try
    {
        pool = new ThreadPoolStrategy(threadPoolSize);
        protocol = new ucarProtocol();
        transport = new RTPSProxyTransport("ucarService", "Instance");
        proxy = new UCarProxy(*pool, *transport, *protocol, servant);
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }
    
    // Create and initialize parameters.
    int32_t  action = 0;
    int32_t  width = 0;
    int32_t  height = 0;
    int32_t  count = 0;
    LongArray  trackID;
    LongArray  x;
    LongArray  y;
    // Create and initialize return value.
    bool  return_ = false;

    // Call to remote procedure "sendTouchEvent".
    try
    {
        return_ = proxy->sendTouchEvent(action, width, height, count, trackID, x, y);
    }
    catch(SystemException &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    
    delete proxy ;
    delete transport ;
    delete protocol ;
    delete pool;
   
    return 0;
}




























