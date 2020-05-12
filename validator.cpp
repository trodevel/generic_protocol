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

// $Revision: 13032 $ $Date:: 2020-05-13 #$ $Author: serge $

#include "validator.h"      // self

#include "basic_parser/malformed_request.h"     // MalformedRequest

namespace generic_protocol
{

namespace validator
{

typedef basic_parser::MalformedRequest MalformedRequest;

bool validate( const AuthenticateRequest & r )
{
    if( r.user_login.empty() )
        throw MalformedRequest( "USER_LOGIN is empty" );

    if( r.password.empty() )
        throw MalformedRequest( "PASSWORD is empty" );

    return true;
}

bool validate( const AuthenticateAltRequest & r )
{
    if( r.user_id == 0 )
        throw MalformedRequest( "USER_ID is 0" );

    if( r.password.empty() )
        throw MalformedRequest( "PASSWORD is empty" );

    return true;
}

bool validate( const CloseSessionRequest & r )
{
    if( r.session_id.empty() )
        throw MalformedRequest( "SESSION_ID is empty" );

    return true;
}

bool validate( const Request & r )
{
    if( r.session_id.empty() )
        throw MalformedRequest( "SESSION_ID is empty" );

    return true;
}

bool validate( const GetUserIdRequest & r )
{
    if( r.session_id.empty() )
        throw MalformedRequest( "SESSION_ID is empty" );

    if( r.user_login.empty() )
        throw MalformedRequest( "USER_LOGIN is empty" );

    return true;
}

bool validate( const GetSessionInfoRequest & r )
{
    if( r.session_id.empty() )
        throw MalformedRequest( "SESSION_ID is empty" );

    if( r.id.empty() )
        throw MalformedRequest( "ID is empty" );

    return true;
}

} // namespace validator

} // namespace generic_protocol

