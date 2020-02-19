/*

Exported Parser.

Copyright (C) 2020 Sergey Kolevatov

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

// $Revision: 12760 $ $Date:: 2020-02-17 #$ $Author: serge $

// includes
#include "exported_parser.h"

#include "basic_parser/exported_parser.h"

namespace basic_parser
{

using namespace generic_protocol;

void get_value_or_throw( generic_protocol::ErrorResponse::type_e * res, const std::string & key, const generic_request::Request & r )
{
    uint32_t res_i;

    get_value_or_throw( & res_i, key, r );

    * res = static_cast<ErrorResponse::type_e>( res_i );
}

void get_value_or_throw( generic_protocol::SessionInfo * res, const std::string & key, const generic_request::Request & r )
{
    get_value_or_throw( & res->user_id, key + ".USER_ID", r );
    get_value_or_throw( & res->start_time, key + ".START_TIME", r );
    get_value_or_throw( & res->expiration_time, key + ".EXPIRATION_TIME", r );
}

void get_value_or_throw( generic_protocol::ErrorResponse * res, const generic_request::Request & r )
{
    get_value_or_throw( & res->type, "TYPE", r );
    get_value_or_throw( & res->descr, "DESCR", r );
}

void get_value_or_throw( generic_protocol::AuthenticateRequest * res, const generic_request::Request & r )
{
}

void get_value_or_throw( generic_protocol::AuthenticateAltRequest * res, const generic_request::Request & r )
{
}

void get_value_or_throw( generic_protocol::AuthenticateResponse * res, const generic_request::Request & r )
{
}

void get_value_or_throw( generic_protocol::CloseSessionRequest * res, const generic_request::Request & r )
{
}

void get_value_or_throw( generic_protocol::CloseSessionResponse * res, const generic_request::Request & r )
{
}

void get_value_or_throw( generic_protocol::GetUserIdRequest * res, const generic_request::Request & r )
{
}

void get_value_or_throw( generic_protocol::GetUserIdResponse * res, const generic_request::Request & r )
{
}

void get_value_or_throw( generic_protocol::GetSessionInfoRequest * res, const generic_request::Request & r )
{
}

void get_value_or_throw( generic_protocol::GetSessionInfoResponse * res, const generic_request::Request & r )
{
}

} // namespace basic_parser

