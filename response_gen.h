/*

Protocol response generator.

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

// $Revision: 3610 $ $Date:: 2016-04-03 #$ $Author: serge $

#ifndef LIB_GENERIC_PROTOCOL_RESPONSE_GEN_H
#define LIB_GENERIC_PROTOCOL_RESPONSE_GEN_H

#include "generic_protocol.h"   // ErrorResponse

namespace generic_protocol
{

inline ErrorResponse* create_error_response( ErrorResponse::type_e type, const std::string & descr )
{
    auto res = new ErrorResponse;

    res->type   = type;
    res->descr  = descr;

    return res;
}

inline AuthenticateResponse* create_autheticate_response( const std::string & session_id )
{
    auto res = new AuthenticateResponse;

    res->session_id = session_id;

    return res;
}

inline CloseSessionResponse* create_close_session_response()
{
    auto res = new CloseSessionResponse;

    return res;
}

} // namespace generic_protocol

#endif // LIB_GENERIC_PROTOCOL_RESPONSE_GEN_H