/*

Generic Protocol messages.

Copyright (C) 2016 Sergey Kolevatov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

// $Revision: 3634 $ $Date:: 2016-04-05 #$ $Author: serge $

#ifndef LIB_GENERIC_PROTOCOL_GENERIC_PROTOCOL_H
#define LIB_GENERIC_PROTOCOL_GENERIC_PROTOCOL_H

#include <cstdint>              // uint32_t
#include <string>               // std::string

namespace generic_protocol
{

// base messages *******************************************

struct MessageBase
{
protected:
    MessageBase() {}

    virtual ~MessageBase() {};
};

struct ObjectBase
{
    virtual ~ObjectBase() {};
};

// forward/backward messages *******************************

struct ForwardMessage: public MessageBase
{
protected:
    ForwardMessage() {}

    virtual ~ForwardMessage() {};
};

struct BackwardMessage: public MessageBase
{
protected:
    BackwardMessage() {}

    virtual ~BackwardMessage() {};
};

// error response *******************************************

struct ErrorResponse: public BackwardMessage
{
    enum type_e
    {
        AUTHENTICATION_ERROR    = 1,
        NOT_PERMITTED           = 2,
        INVALID_ARGUMENT        = 3,
        RUNTIME_ERROR           = 4,
    };

    type_e          type;
    std::string     descr;
};

// authentication messages **********************************

struct AuthenticateRequest: public ForwardMessage
{
    virtual ~AuthenticateRequest() {};

    std::string         user_login;
    std::string         password;
};

struct AuthenticateAltRequest: public ForwardMessage
{
    virtual ~AuthenticateAltRequest() {};

    uint32_t            user_id;
    std::string         password;
};

struct AuthenticateResponse: public BackwardMessage
{
    virtual ~AuthenticateResponse() {};

    std::string         session_id;
};

// session messages ****************************************

struct CloseSessionRequest: public ForwardMessage
{
    virtual ~CloseSessionRequest() {};

    std::string         session_id;
};

struct CloseSessionResponse: public BackwardMessage
{
    virtual ~CloseSessionResponse() {};
};

// authentication messages **********************************

struct Request: public ForwardMessage
{
protected:
    Request() {}

public:

    virtual ~Request() {};

    std::string         session_id;
};

} // namespace generic_protocol

#endif // LIB_GENERIC_PROTOCOL_GENERIC_PROTOCOL_H
