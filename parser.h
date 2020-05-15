/*

Request Parser.

Copyright (C) 2014 Sergey Kolevatov

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

// $Revision: 13061 $ $Date:: 2020-05-15 #$ $Author: serge $

#include "generic_request/request.h"    // generic_request::Request
#include "enums.h"              // request_type_e
#include "protocol.h"   // Request...

namespace generic_protocol
{

namespace parser
{

void get_value_or_throw( ErrorResponse::type_e * res, const std::string & key, const generic_request::Request & r );

void get_value_or_throw( SessionInfo * res, const std::string & key, const generic_request::Request & r );

void get_value_or_throw( BackwardMessage * res, const generic_request::Request & r );
void get_value_or_throw( Request * res, const generic_request::Request & r );

void get_value_or_throw( AuthenticateRequest * res, const generic_request::Request & r );
void get_value_or_throw( AuthenticateAltRequest * res, const generic_request::Request & r );
void get_value_or_throw( AuthenticateResponse * res, const generic_request::Request & r );
void get_value_or_throw( CloseSessionRequest * res, const generic_request::Request & r );
void get_value_or_throw( CloseSessionResponse * res, const generic_request::Request & r );
void get_value_or_throw( GetUserIdRequest * res, const generic_request::Request & r );
void get_value_or_throw( GetUserIdResponse * res, const generic_request::Request & r );
void get_value_or_throw( GetSessionInfoRequest * res, const generic_request::Request & r );
void get_value_or_throw( GetSessionInfoResponse * res, const generic_request::Request & r );

request_type_e   detect_request_type( const generic_request::Request & r );

ForwardMessage *     to_forward_message( const generic_request::Request & r );

ForwardMessage *     to_AuthenticateRequest( const generic_request::Request & r );
ForwardMessage *     to_AuthenticateAltRequest( const generic_request::Request & r );
ForwardMessage *     to_CloseSessionRequest( const generic_request::Request & r );
Request *            to_request( Request * res, const generic_request::Request & r );
ForwardMessage *     to_GetUserIdRequest( const generic_request::Request & r );
ForwardMessage *     to_GetSessionInfoRequest( const generic_request::Request & r );

} // namespace parser

} // namespace generic_protocol
