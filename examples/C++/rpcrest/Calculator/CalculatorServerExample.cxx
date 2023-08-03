/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * rpcrest_LICENSE file included in this rpcrest distribution.
 *
 *************************************************************************
 * 
 * @file CalculatorServerExample.cxx
 * This source file shows a simple example of how to create a server for an interface.
 *
 * This file was generated by the tool rpcrestgen.
 */

#include "CalculatorServer.h"
#include "rpcrest/strategies/ThreadPoolStrategy.h"
#include "CalculatorRESTProtocol.h"
#include "rpcrest/transports/HttpServerTransport.h"
#include "rpcrest/exceptions/Exceptions.h"
#include "rpcrest/utils/Utilities.h"
#include "CalculatorServerImplExample.h"

#include <iostream>

using namespace eprosima::rpc;
using namespace eprosima::rpc::exception;
using namespace eprosima::rpc::strategy;
using namespace eprosima::rpc::transport;
using namespace eprosima::rpc::protocol::rest;

int main(int argc, char **argv)
{
    unsigned int threadPoolSize = 5;
    ThreadPoolStrategy *pool = NULL;
    CalculatorProtocol *protocol = NULL;
    HttpServerTransport *transport = NULL;

    Calculator::addResourceServer *addServer = NULL;
	Calculator::substractResourceServer *substractServer = NULL;
	Calculator::multiplyResourceServer *multiplyServer = NULL;
	Calculator::divideResourceServer *divideServer = NULL;

    addResourceServerImplExample addServant;
	substractResourceServerImplExample substractServant;
	multiplyResourceServerImplExample multiplyServant;
	divideResourceServerImplExample divideServant;
    
    // Create and initialize the server for interface "Calculator::addResource".
    try
    {
        pool = new ThreadPoolStrategy(threadPoolSize);
        protocol = new CalculatorProtocol();
        transport = new HttpServerTransport("127.0.0.1:8080");
        addServer = new Calculator::addResourceServer(*pool, *transport, *protocol, addServant);
        addServer->serve();
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }

	// Create and initialize the server for interface "Calculator::substractResource".
    try
    {
        substractServer = new Calculator::substractResourceServer(*pool, *transport, *protocol, substractServant);
        substractServer->serve();
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }

	// Create and initialize the server for interface "Calculator::multiplyResourceServer".
    try
    {
		multiplyServer = new Calculator::multiplyResourceServer(*pool, *transport, *protocol, multiplyServant);
        multiplyServer->serve();
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }

	// Create and initialize the server for interface "Calculator::divideResourceServer".

    try
    {
		divideServer = new Calculator::divideResourceServer(*pool, *transport, *protocol, divideServant);
        divideServer->serve();
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }
    
    while(1)
    {
        eprosima::rpc::sleep(10000);
    }
    
    // Stop and delete the server.
	addServer->stop();
    delete addServer;
	substractServer->stop();
    delete substractServer;
	multiplyServer->stop();
    delete multiplyServer;
	divideServer->stop();
    delete divideServer;
    delete protocol;
    delete transport;
    delete pool;
    
    return 0;
}
















