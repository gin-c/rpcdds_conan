/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file Server.cxx
 * This source file shows a simple example of how to create a server for interface Calculator.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "CalculatorServer.h"
#include "strategies/ThreadPoolStrategy.h"
#include "exceptions/Exceptions.h"
#include "utils/Utilities.h"

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    unsigned int threadPoolSize = 5;
    eProsima::RPCDDS::ThreadPoolStrategy *pool = NULL;
    CalculatorServer *server = NULL;
    int domainId = 13;

    if(argc >= 2)
        domainId = atoi(argv[1]);
    
    // Create and initialize the server for interface "Calculator".
    try
    {
        pool = new eProsima::RPCDDS::ThreadPoolStrategy(threadPoolSize);
        server = new CalculatorServer("OpenDDSCalculatorService", pool, domainId);
        server->serve();
    }
    catch(eProsima::RPCDDS::InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }
    
    std::cout << "\033[32mPress a key + ENTER to exit the server\033[0m" << std::endl;
    std::string line;
    std::cin >> line;
    
    // Stop and delete the server.
    server->stop();
    delete server;
    delete pool;
    
    return 0;
}
