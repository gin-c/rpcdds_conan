/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * rpcdds_LICENSE file included in this rpcdds distribution.
 *
 *************************************************************************
 *
 * @file UCarAsyncCallbackHandlers.h
 * This header file contains the declaration of callback handlers used in asynchronous calls.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _UCar_ASYNC_CALLBACK_HANDLERS_H_
#define _UCar_ASYNC_CALLBACK_HANDLERS_H_

#include "UCar.h"
#include <rpcdds/exceptions/SystemException.h>
#include <rpcdds/exceptions/UserException.h>

/*!
 * @brief This abstract class defines the callbacks that eProsima RPC will call in an asynchronous call.
 *        These callback has to be implemented in a derived class.
 * @ingroup UCAR
 */
class UCar_sendTouchEventCallbackHandler {
public:
    /*!
     * This function is called when is received the reply from the server.
     */
    virtual void sendTouchEvent(/*out*/ bool return_) = 0;

    /*!
     * @brief This function is called when an exception occurs.
     *        This exception can be launched in the server's side or in the client's side.
     *
     * @param ex The exception that will be launched.
     */
    virtual void on_exception(const eprosima::rpc::exception::SystemException &ex) = 0;
};

/*!
 * @brief This abstract class defines the callbacks that eProsima RPC will call in an asynchronous call.
 *        These callback has to be implemented in a derived class.
 * @ingroup UCAR
 */
class UCar_sendMicRecordDataCallbackHandler {
public:
    /*!
     * This function is called when is received the reply from the server.
     */
    virtual void sendMicRecordData(/*out*/ bool return_) = 0;

    /*!
     * @brief This function is called when an exception occurs.
     *        This exception can be launched in the server's side or in the client's side.
     *
     * @param ex The exception that will be launched.
     */
    virtual void on_exception(const eprosima::rpc::exception::SystemException &ex) = 0;
};

/*!
 * @brief This abstract class defines the callbacks that eProsima RPC will call in an asynchronous call.
 *        These callback has to be implemented in a derived class.
 * @ingroup UCAR
 */
class UCar_sendKeyEventCallbackHandler {
public:
    /*!
     * This function is called when is received the reply from the server.
     */
    virtual void sendKeyEvent(/*out*/ bool return_) = 0;

    /*!
     * @brief This function is called when an exception occurs.
     *        This exception can be launched in the server's side or in the client's side.
     *
     * @param ex The exception that will be launched.
     */
    virtual void on_exception(const eprosima::rpc::exception::SystemException &ex) = 0;
};

/*!
 * @brief This abstract class defines the callbacks that eProsima RPC will call in an asynchronous call.
 *        These callback has to be implemented in a derived class.
 * @ingroup UCAR
 */
class UCar_sendGotoForegroundCallbackHandler {
public:
    /*!
     * This function is called when is received the reply from the server.
     */
    virtual void sendGotoForeground(/*out*/ bool return_) = 0;

    /*!
     * @brief This function is called when an exception occurs.
     *        This exception can be launched in the server's side or in the client's side.
     *
     * @param ex The exception that will be launched.
     */
    virtual void on_exception(const eprosima::rpc::exception::SystemException &ex) = 0;
};

/*!
 * @brief This abstract class defines the callbacks that eProsima RPC will call in an asynchronous call.
 *        These callback has to be implemented in a derived class.
 * @ingroup UCAR
 */
class UCar_sendGotoBackgroundCallbackHandler {
public:
    /*!
     * This function is called when is received the reply from the server.
     */
    virtual void sendGotoBackground(/*out*/ bool return_) = 0;

    /*!
     * @brief This function is called when an exception occurs.
     *        This exception can be launched in the server's side or in the client's side.
     *
     * @param ex The exception that will be launched.
     */
    virtual void on_exception(const eprosima::rpc::exception::SystemException &ex) = 0;
};

/*!
 * @brief This abstract class defines the callbacks that eProsima RPC will call in an asynchronous call.
 *        These callback has to be implemented in a derived class.
 * @ingroup UCAR
 */
class UCar_sendVRCMDCallbackHandler {
public:
    /*!
     * This function is called when is received the reply from the server.
     */
    virtual void sendVRCMD(/*out*/ bool return_) = 0;

    /*!
     * @brief This function is called when an exception occurs.
     *        This exception can be launched in the server's side or in the client's side.
     *
     * @param ex The exception that will be launched.
     */
    virtual void on_exception(const eprosima::rpc::exception::SystemException &ex) = 0;
};

/*!
 * @brief This abstract class defines the callbacks that eProsima RPC will call in an asynchronous call.
 *        These callback has to be implemented in a derived class.
 * @ingroup UCAR
 */
class UCar_notifyIsCallHungUpCallbackHandler {
public:
    /*!
     * This function is called when is received the reply from the server.
     */
    virtual void notifyIsCallHungUp(/*out*/ bool return_) = 0;

    /*!
     * @brief This function is called when an exception occurs.
     *        This exception can be launched in the server's side or in the client's side.
     *
     * @param ex The exception that will be launched.
     */
    virtual void on_exception(const eprosima::rpc::exception::SystemException &ex) = 0;
};

/*!
 * @brief This abstract class defines the callbacks that eProsima RPC will call in an asynchronous call.
 *        These callback has to be implemented in a derived class.
 * @ingroup UCAR
 */
class UCar_notifySwitchDayOrNightCallbackHandler {
public:
    /*!
     * This function is called when is received the reply from the server.
     */
    virtual void notifySwitchDayOrNight(/*out*/ bool return_) = 0;

    /*!
     * @brief This function is called when an exception occurs.
     *        This exception can be launched in the server's side or in the client's side.
     *
     * @param ex The exception that will be launched.
     */
    virtual void on_exception(const eprosima::rpc::exception::SystemException &ex) = 0;
};

/*!
 * @brief This abstract class defines the callbacks that eProsima RPC will call in an asynchronous call.
 *        These callback has to be implemented in a derived class.
 * @ingroup UCAR
 */
class UCar_awakenVoiceAssistantCallbackHandler {
public:
    /*!
     * This function is called when is received the reply from the server.
     */
    virtual void awakenVoiceAssistant(/*out*/ bool return_) = 0;

    /*!
     * @brief This function is called when an exception occurs.
     *        This exception can be launched in the server's side or in the client's side.
     *
     * @param ex The exception that will be launched.
     */
    virtual void on_exception(const eprosima::rpc::exception::SystemException &ex) = 0;
};

/*!
 * @brief This abstract class defines the callbacks that eProsima RPC will call in an asynchronous call.
 *        These callback has to be implemented in a derived class.
 * @ingroup UCAR
 */
class UCar_presetVendorCustomFieldsCallbackHandler {
public:
    /*!
     * This function is called when is received the reply from the server.
     */
    virtual void presetVendorCustomFields(/*out*/ bool return_) = 0;

    /*!
     * @brief This function is called when an exception occurs.
     *        This exception can be launched in the server's side or in the client's side.
     *
     * @param ex The exception that will be launched.
     */
    virtual void on_exception(const eprosima::rpc::exception::SystemException &ex) = 0;
};

/*!
 * @brief This abstract class defines the callbacks that eProsima RPC will call in an asynchronous call.
 *        These callback has to be implemented in a derived class.
 * @ingroup UCAR
 */
class UCar_presetConnectModeCallbackHandler {
public:
    /*!
     * This function is called when is received the reply from the server.
     */
    virtual void presetConnectMode(/*out*/ bool return_) = 0;

    /*!
     * @brief This function is called when an exception occurs.
     *        This exception can be launched in the server's side or in the client's side.
     *
     * @param ex The exception that will be launched.
     */
    virtual void on_exception(const eprosima::rpc::exception::SystemException &ex) = 0;
};

#endif  // _UCar_ASYNC_CALLBACK_HANDLERS_H_