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

// $Revision: 9125 $ $Date:: 2018-05-08 #$ $Author: serge $

#include "request_parser.h"         // self

#include "request_validator.h"      // RequestValidator
#include "basic_parser/malformed_request.h"     // MalformedRequest

namespace generic_protocol
{

typedef basic_parser::MalformedRequest MalformedRequest;

#define TUPLE_VAL_STR(_x_)  _x_,#_x_
#define TUPLE_STR_VAL(_x_)  #_x_,_x_

template< typename _M, typename _U, typename _V >
void insert_inverse_pair( _M & map, _U first, _V second )
{
    map.insert( typename _M::value_type( second, first ) );
}

request_type_e to_request_type( const std::string & s )
{
    typedef request_type_e Type;
    typedef std::map< std::string, Type > Map;
    static Map m;
    if( m.empty() )
    {
        insert_inverse_pair( m, Type:: TUPLE_VAL_STR( AUTHENTICATE_REQUEST ) );
        insert_inverse_pair( m, Type:: TUPLE_VAL_STR( AUTHENTICATE_ALT_REQUEST ) );
        insert_inverse_pair( m, Type:: TUPLE_VAL_STR( CLOSE_SESSION_REQUEST ) );
        insert_inverse_pair( m, Type:: TUPLE_VAL_STR( GET_USER_ID ) );
        insert_inverse_pair( m, Type:: TUPLE_VAL_STR( GetSessionInfoRequest ) );
    }

    auto it = m.find( s );

    if( it == m.end() )
        return Type::UNDEF;

    return it->second;
}

request_type_e  RequestParser::detect_request_type( const generic_request::Request & r )
{
    std::string cmd;

    if( r.get_value( "CMD", cmd ) == false )
        throw MalformedRequest( "CMD is not defined" );

    return to_request_type( cmd );
}

ForwardMessage * RequestParser::to_forward_message( const generic_request::Request & r )
{
    auto type = RequestParser::detect_request_type( r );

    typedef ForwardMessage* (*PPMF)( const generic_request::Request & r );

    static const std::map<request_type_e, PPMF> funcs =
    {
        { request_type_e::AUTHENTICATE_REQUEST,     & RequestParser::to_AuthenticateRequest },
        { request_type_e::AUTHENTICATE_ALT_REQUEST, & RequestParser::to_AuthenticateAltRequest },
        { request_type_e::CLOSE_SESSION_REQUEST,    & RequestParser::to_CloseSessionRequest },
        { request_type_e::GET_USER_ID,              & RequestParser::to_GetUserIdRequest },
        { request_type_e::GetSessionInfoRequest,    & RequestParser::to_GetSessionInfoRequest },
    };

    auto it = funcs.find( type );

    if( it == funcs.end() )
        throw MalformedRequest( "unknown request type" );

    return it->second( r );
}

ForwardMessage * RequestParser::to_AuthenticateRequest( const generic_request::Request & r )
{
    auto * res = new AuthenticateRequest;

    if( r.get_value( "USER_LOGIN", res->user_login ) == false )
        throw MalformedRequest( "USER_LOGIN is not defined" );

    if( r.get_value( "PASSWORD", res->password ) == false )
        throw MalformedRequest( "PASSWORD is not defined" );

    RequestValidator::validate( res );

    return res;
}

ForwardMessage * RequestParser::to_AuthenticateAltRequest( const generic_request::Request & r )
{
    auto * res = new AuthenticateAltRequest;

    if( r.get_value_converted( "USER_ID", res->user_id ) == false )
        throw MalformedRequest( "USER_ID is not defined" );

    if( r.get_value( "PASSWORD", res->password ) == false )
        throw MalformedRequest( "PASSWORD is not defined" );

    RequestValidator::validate( res );

    return res;
}

ForwardMessage * RequestParser::to_CloseSessionRequest( const generic_request::Request & r )
{
    auto * res = new CloseSessionRequest;

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

ForwardMessage * RequestParser::to_GetUserIdRequest( const generic_request::Request & r )
{
    auto * res = new GetUserIdRequest;

    if( r.get_value( "SESSION_ID", res->session_id ) == false )
        throw MalformedRequest( "SESSION_ID is not defined" );

    if( r.get_value( "USER_LOGIN", res->user_login ) == false )
        throw MalformedRequest( "USER_LOGIN is not defined" );

    RequestValidator::validate( res );

    return res;
}

ForwardMessage * RequestParser::to_GetSessionInfoRequest( const generic_request::Request & r )
{
    auto * res = new GetSessionInfoRequest;

    if( r.get_value( "SESSION_ID", res->session_id ) == false )
        throw MalformedRequest( "SESSION_ID is not defined" );

    if( r.get_value( "ID", res->id ) == false )
        throw MalformedRequest( "ID is not defined" );

    RequestValidator::validate( res );

    return res;
}

} // namespace generic_protocol
