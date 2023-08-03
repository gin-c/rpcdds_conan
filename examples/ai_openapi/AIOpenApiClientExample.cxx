/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * rpcdds_LICENSE file included in this rpcdds distribution.
 *
 *************************************************************************
 *
 * @file AIOpenApiClientExample.cxx
 * This source file shows a simple example of how to create a proxy for an interface.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "AIOpenApi.h"
#include "AIOpenApiDDSProtocol.h"
#include "AIOpenApiProxy.h"
#include "AIOpenApiProxyImplExample.h"
#include <rpcdds/exceptions/Exceptions.h>
#include <rpcdds/strategies/ThreadPoolStrategy.h>
#include <rpcdds/transports/dds/RTPSProxyTransport.h>
#include <rpcdds/utils/Utilities.h>

#include <iostream>

using namespace eprosima::rpc;
using namespace ::exception;
using namespace ::transport::dds;
using namespace ::protocol::dds;
using namespace ::strategy;

int main(int argc, char **argv) {
    unsigned int threadPoolSize = 5;
    ThreadPoolStrategy *pool = NULL;
    AIOpenApiProtocol *protocol = NULL;
    RTPSProxyTransport *transport = NULL;
    AI::OpenApi::VSPProxy *proxy = NULL;
    VSPProxyImplExample servant;

    // Creation of the proxy for interface "AI::OpenApi::VSP".
    try {
        pool = new ThreadPoolStrategy(threadPoolSize);
        protocol = new AIOpenApiProtocol();
        transport = new RTPSProxyTransport("AIOpenApiService", "Instance");
        proxy = new AI::OpenApi::VSPProxy(*pool, *transport, *protocol, servant);
    } catch (InitializeException &ex) {
        std::cout << ex.what() << std::endl;
        return -1;
    }

    // Create and initialize parameters.
    // Create and initialize return value.
    bool return_ = false;

    // Call to remote procedure "beginVoice".
    try {
        return_ = proxy->beginVoice();
    } catch (SystemException &ex) {
        std::cout << ex.what() << std::endl;
    }

    delete proxy;
    delete transport;
    delete protocol;
    delete pool;

    return 0;
}