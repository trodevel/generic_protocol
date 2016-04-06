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

// $Revision: 3656 $ $Date:: 2016-04-07 #$ $Author: serge $

#include "request_parser.h"         // self

#include "request_validator.h"      // RequestValidator
#include "malformed_request.h"      // MalformedRequest

namespace generic_protocol
{

#define TUPLE_VAL_STR(_x_)  _x_,#_x_
#define TUPLE_STR_VAL(_x_)  #_x_,_x_

template< typename _M, typename _U, typename _V >
void insert_inverse_pair( _M & map, _U first, _V second )
{
    map.insert( typename _M::value_type( second, first ) );
}

request_type_e to_request_type( const std::string & s )
{
    typedef std::map< std::string, request_type_e > Map;
    static Map m;
    if( m.empty() )
    {
        insert_inverse_pair( m, request_type_e:: TUPLE_VAL_STR( AUTHENTICATE_REQUEST ) );
        insert_inverse_pair( m, request_type_e:: TUPLE_VAL_STR( AUTHENTICATE_ALT_REQUEST ) );
        insert_inverse_pair( m, request_type_e:: TUPLE_VAL_STR( CLOSE_SESSION_REQUEST ) );
    }

    auto it = m.find( s );

    if( it == m.end() )
        return request_type_e::UNDEF;

    return it->second;
}

request_type_e  RequestParser::detect_request_type( const generic_request::Request & r )
{
    std::string cmd;

    if( r.get_value( "CMD", cmd ) == false )
        throw MalformedRequest( "CMD is not defined" );

    return to_request_type( cmd );
}

AuthenticateRequest * RequestParser::to_authenticate_request( const generic_request::Request & r )
{
    AuthenticateRequest * res = new AuthenticateRequest;

    if( r.get_value( "USER_LOGIN", res->user_login ) == false )
        throw MalformedRequest( "USER_LOGIN is not defined" );

    if( r.get_value( "PASSWORD", res->password ) == false )
        throw MalformedRequest( "PASSWORD is not defined" );

    RequestValidator::validate( res );

    return res;
}

AuthenticateAltRequest * RequestParser::to_authenticate_alt_request( const generic_request::Request & r )
{
    auto * res = new AuthenticateAltRequest;

    if( r.get_value_uint32( "USER_ID", res->user_id ) == false )
        throw MalformedRequest( "USER_ID is not defined" );

    if( r.get_value( "PASSWORD", res->password ) == false )
        throw MalformedRequest( "PASSWORD is not defined" );

    RequestValidator::validate( res );

    return res;
}

CloseSessionRequest * RequestParser::to_close_session_request( const generic_request::Request & r )
{
    CloseSessionRequest * res = new CloseSessionRequest;

    if( r.get_value( "SESSION_ID", res->session_id ) == false )
        throw MalformedRequest( "SESSION_ID is not defined" );

    RequestValidator::validate( res );

    return res;
}

Request * RequestParser::to_request( Request * res, const generic_request::Request & r )
{
    if( r.get_value( "SESSION_ID", res->session_id ) == false )
        throw MalformedRequest( "SESSION_ID is not defined" );

    return res;
}

} // namespace generic_protocol
