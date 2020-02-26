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

// $Revision: 12801 $ $Date:: 2020-02-26 #$ $Author: serge $

#ifndef LIB_GENERIC_PROTOCOL__EXPORTED_VALIDATOR_H
#define LIB_GENERIC_PROTOCOL__EXPORTED_VALIDATOR_H

#include "protocol.h"

namespace basic_parser
{

namespace validator
{

bool validate( const generic_protocol::ErrorResponse::type_e & r );

bool validate( const generic_protocol::SessionInfo & r );

bool validate( const generic_protocol::BackwardMessage & r );
bool validate( const generic_protocol::Request & r );

bool validate( const generic_protocol::AuthenticateRequest & r );
bool validate( const generic_protocol::AuthenticateAltRequest & r );
bool validate( const generic_protocol::AuthenticateResponse & r );
bool validate( const generic_protocol::CloseSessionRequest & r );
bool validate( const generic_protocol::CloseSessionResponse & r );
bool validate( const generic_protocol::GetUserIdRequest & r );
bool validate( const generic_protocol::GetUserIdResponse & r );
bool validate( const generic_protocol::GetSessionInfoRequest & r );
bool validate( const generic_protocol::GetSessionInfoResponse & r );

} // namespace validator

} // namespace basic_parser

#endif // LIB_GENERIC_PROTOCOL__EXPORTED_VALIDATOR_H
