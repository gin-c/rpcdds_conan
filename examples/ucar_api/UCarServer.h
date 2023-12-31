/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * rpcdds_LICENSE file included in this rpcdds distribution.
 *
 *************************************************************************
 *
 * @file UCarServer.h
 * This header file contains the declaration of the server for all interfaces.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _UCarSERVER_H_
#define _UCarSERVER_H_

#include "UCar.h"
#include "UCarServerImpl.h"
#include <rpcdds/server/Server.h>

namespace eprosima {
namespace rpc {
namespace protocol {
class UCarProtocol;
}
}  // namespace rpc
}  // namespace eprosima

/*!
 * @brief This class implements a specific server for the defined interface UCar by user.
 * @ingroup UCAR
 */
class RPCUSERDllExport UCarServer : public eprosima::rpc::server::Server, public UCarNotify {
public:
    /*!
     * @brief This constructor sets the transport that will be used by the server.
     *
     * @param strategy Strategy used by server to work with new requests.
     *        This class doesn't delete this object in its destructor. Cannot be NULL.
     * @param transport The network transport that the server has to use.
     *        This transport's object is not deleted by this class in its destructor. Cannot be NULL.
     * @param protocol Generated protocol that the server has to use.
     *        This class has the information to process requests and build responses for this application environment.
     * @param servant Servant that the server will use to invoke user's functions.
     * @exception eProsima::RPCDDS::InitializeException This exception is thrown when the initialization was wrong.
     */
    UCarServer(eprosima::rpc::strategy::ServerStrategy& strategy, eprosima::rpc::transport::ServerTransport& transport,
               eprosima::rpc::protocol::UCarProtocol& protocol, UCarServerImpl& servant);

    //! @brief Destructor.
    virtual ~UCarServer();

    //! @brief Proxy method for the operation videoInitialized.
    void videoInitialized(/*in*/ int32_t type, /*in*/ const VideoFormat& videFormat);

    //! @brief Proxy method for the operation videoDataReceived.
    void videoDataReceived(/*in*/ int32_t type, /*in*/ int32_t size, /*in*/ const ByteArray& byte);

    //! @brief Proxy method for the operation requestGotoHUDesktop.
    void requestGotoHUDesktop();

    //! @brief Proxy method for the operation audioStateChanged.
    void audioStateChanged(/*in*/ int32_t var2, /*in*/ const AudioFormat& audioFormat, /*in*/ int32_t playerState);

    //! @brief Proxy method for the operation audioDataReceived.
    void audioDataReceived(/*in*/ int32_t var2, /*in*/ int32_t var3, /*in*/ const ByteArray& var4);

    //! @brief Proxy method for the operation musicInfoReceived.
    void musicInfoReceived(/*in*/ const MusicInfo& var2);

    //! @brief Proxy method for the operation navigationInfoReceived.
    void navigationInfoReceived(/*in*/ const NavigationInfo& var2);

    //! @brief Proxy method for the operation phoneStateInfoReceived.
    void phoneStateInfoReceived(/*in*/ const PhoneStateInfo& var2);

    //! @brief Proxy method for the operation micRecordRequest.
    void micRecordRequest(/*in*/ const AudioFormat& var2, /*in*/ bool var3);

    //! @brief Proxy method for the operation userInterventionNeeded.
    void userInterventionNeeded();

private:
    //! \brief Pointer to the server's servant implemented by the user.
    UCarServerImpl& _impl;
};

#endif  // _UCarSERVER_H_