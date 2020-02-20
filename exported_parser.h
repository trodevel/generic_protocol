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

// $Revision: 12763 $ $Date:: 2020-02-19 #$ $Author: serge $

#ifndef LIB_GENERIC_PROTOCOL__EXPORTED_PARSER_H
#define LIB_GENERIC_PROTOCOL__EXPORTED_PARSER_H

#include "protocol.h"
#include "generic_request/request.h"

namespace basic_parser
{

void get_value_or_throw( generic_protocol::ErrorResponse::type_e * res, const std::string & key, const generic_request::Request & r );

void get_value_or_throw( generic_protocol::SessionInfo * res, const std::string & key, const generic_request::Request & r );

void get_value_or_throw( generic_protocol::BackwardMessage * res, const generic_request::Request & r );
void get_value_or_throw( generic_protocol::Request * res, const generic_request::Request & r );

void get_value_or_throw( generic_protocol::AuthenticateRequest * res, const generic_request::Request & r );
void get_value_or_throw( generic_protocol::AuthenticateAltRequest * res, const generic_request::Request & r );
void get_value_or_throw( generic_protocol::AuthenticateResponse * res, const generic_request::Request & r );
void get_value_or_throw( generic_protocol::CloseSessionRequest * res, const generic_request::Request & r );
void get_value_or_throw( generic_protocol::CloseSessionResponse * res, const generic_request::Request & r );
void get_value_or_throw( generic_protocol::GetUserIdRequest * res, const generic_request::Request & r );
void get_value_or_throw( generic_protocol::GetUserIdResponse * res, const generic_request::Request & r );
void get_value_or_throw( generic_protocol::GetSessionInfoRequest * res, const generic_request::Request & r );
void get_value_or_throw( generic_protocol::GetSessionInfoResponse * res, const generic_request::Request & r );

} // namespace basic_parser

#endif // LIB_GENERIC_PROTOCOL__EXPORTED_PARSER_H
