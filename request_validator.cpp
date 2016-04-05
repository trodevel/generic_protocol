/*

Request Validator.

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

#include "request_validator.h"      // self

#include "request_parser.h"         // MalformedRequest

namespace generic_protocol
{

bool RequestValidator::validate( const AuthenticateRequest * r )
{
    if( r->user_login.empty() )
        throw RequestParser::MalformedRequest( "USER_LOGIN is empty" );

    if( r->password.empty() )
        throw RequestParser::MalformedRequest( "PASSWORD is empty" );

    return true;
}

bool RequestValidator::validate( const AuthenticateAltRequest * r )
{
    if( r->user_id == 0 )
        throw RequestParser::MalformedRequest( "USER_ID is 0" );

    if( r->password.empty() )
        throw RequestParser::MalformedRequest( "PASSWORD is empty" );

    return true;
}

bool validate( const CloseSessionRequest * r )
{
    if( r->session_id.empty() )
        throw RequestParser::MalformedRequest( "SESSION_ID is empty" );

    return true;
}

bool validate( const Request * r )
{
    if( r->session_id.empty() )
        throw RequestParser::MalformedRequest( "SESSION_ID is empty" );

    return true;
}

} // namespace generic_protocol
