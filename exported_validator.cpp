/*

Exported Validator.

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

// $Revision: 12792 $ $Date:: 2020-02-26 #$ $Author: serge $

// includes
#include "exported_parser.h"

#include "basic_parser/exported_parser.h"

namespace basic_parser
{

namespace validator
{

using namespace generic_protocol;

bool validate( generic_protocol::ErrorResponse::type_e & r )
{
    uint32_t res_i;

    get_value_or_throw( & res_i, key, r );

    * res = static_cast<ErrorResponse::type_e>( res_i );
}

bool validate( generic_protocol::SessionInfo & r )
{
    get_value_or_throw( & res->user_id, key + ".USER_ID", r );
    get_value_or_throw( & res->start_time, key + ".START_TIME", r );
    get_value_or_throw( & res->expiration_time, key + ".EXPIRATION_TIME", r );
}

bool validate( generic_protocol::BackwardMessage & r )
{
}

bool validate( generic_protocol::Request & r )
{
    get_value_or_throw( & res->session_id, "SESSION_ID", r );
}

bool validate( generic_protocol::ErrorResponse & r )
{
    get_value_or_throw( & res->type, "TYPE", r );
    get_value_or_throw( & res->descr, "DESCR", r );
}

bool validate( generic_protocol::AuthenticateRequest & r )
{
    get_value_or_throw( & res->user_login, "USER_LOGIN", r );
    get_value_or_throw( & res->password, "PASSWORD", r );
}

bool validate( generic_protocol::AuthenticateAltRequest & r )
{
    get_value_or_throw( & res->user_id, "USER_ID", r );
    get_value_or_throw( & res->password, "PASSWORD", r );
}

bool validate( generic_protocol::AuthenticateResponse & r )
{
}

bool validate( generic_protocol::CloseSessionRequest & r )
{
    get_value_or_throw( & res->session_id, "SESSION_ID", r );
}

bool validate( generic_protocol::CloseSessionResponse & r )
{
}

bool validate( generic_protocol::GetUserIdRequest & r )
{
    get_value_or_throw( & res->session_id, "SESSION_ID", r );
    get_value_or_throw( & res->user_login, "USER_LOGIN", r );
}

bool validate( generic_protocol::GetUserIdResponse & r )
{
}

bool validate( generic_protocol::GetSessionInfoRequest & r )
{
    get_value_or_throw( & res->session_id, "SESSION_ID", r );
    get_value_or_throw( & res->id, "ID", r );
}

bool validate( generic_protocol::GetSessionInfoResponse & r )
{
}

} // namespace validator

} // namespace basic_parser

