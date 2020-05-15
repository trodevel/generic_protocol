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

#include "parser.h"         // self

#include <memory>           // std::unique_ptr

#include "validator.h"      // Validator
#include "basic_parser/malformed_request.h"     // MalformedRequest
#include "basic_parser/parser.h"     // basic_parser::get_value_or_throw

namespace generic_protocol
{

namespace parser
{

using basic_parser::parser::get_value_or_throw;
using basic_parser::parser::get_value_or_throw_t;

void get_value_or_throw( ErrorResponse::type_e * res, const std::string & key, const generic_request::Request & r )
{
    uint32_t res_i;

    get_value_or_throw( & res_i, key, r );

    * res = static_cast<ErrorResponse::type_e>( res_i );
}

void get_value_or_throw( SessionInfo * res, const std::string & key, const generic_request::Request & r )
{
    get_value_or_throw( & res->user_id, key + ".USER_ID", r );
    get_value_or_throw( & res->start_time, key + ".START_TIME", r );
    get_value_or_throw( & res->expiration_time, key + ".EXPIRATION_TIME", r );
}

void get_value_or_throw( BackwardMessage * res, const generic_request::Request & r )
{
}

void get_value_or_throw( Request * res, const generic_request::Request & r )
{
    get_value_or_throw( & res->session_id, "SESSION_ID", r );
}

void get_value_or_throw( ErrorResponse * res, const generic_request::Request & r )
{
    get_value_or_throw( & res->type, "TYPE", r );
    get_value_or_throw( & res->descr, "DESCR", r );
}

void get_value_or_throw( AuthenticateRequest * res, const generic_request::Request & r )
{
    get_value_or_throw( & res->user_login, "USER_LOGIN", r );
    get_value_or_throw( & res->password, "PASSWORD", r );
}

void get_value_or_throw( AuthenticateAltRequest * res, const generic_request::Request & r )
{
    get_value_or_throw( & res->user_id, "USER_ID", r );
    get_value_or_throw( & res->password, "PASSWORD", r );
}

void get_value_or_throw( AuthenticateResponse * res, const generic_request::Request & r )
{
}

void get_value_or_throw( CloseSessionRequest * res, const generic_request::Request & r )
{
    get_value_or_throw( & res->session_id, "SESSION_ID", r );
}

void get_value_or_throw( CloseSessionResponse * res, const generic_request::Request & r )
{
}

void get_value_or_throw( GetUserIdRequest * res, const generic_request::Request & r )
{
    get_value_or_throw( & res->session_id, "SESSION_ID", r );
    get_value_or_throw( & res->user_login, "USER_LOGIN", r );
}

void get_value_or_throw( GetUserIdResponse * res, const generic_request::Request & r )
{
}

void get_value_or_throw( GetSessionInfoRequest * res, const generic_request::Request & r )
{
    get_value_or_throw( & res->session_id, "SESSION_ID", r );
    get_value_or_throw( & res->id, "ID", r );
}

void get_value_or_throw( GetSessionInfoResponse * res, const generic_request::Request & r )
{
}

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

request_type_e  detect_request_type( const generic_request::Request & r )
{
    std::string cmd;

    if( r.get_value( "CMD", cmd ) == false )
        throw MalformedRequest( "CMD is not defined" );

    return to_request_type( cmd );
}

ForwardMessage * to_forward_message( const generic_request::Request & r )
{
    auto type = detect_request_type( r );

    typedef ForwardMessage* (*PPMF)( const generic_request::Request & r );

    static const std::map<request_type_e, PPMF> funcs =
    {
        { request_type_e::AUTHENTICATE_REQUEST,     & to_AuthenticateRequest },
        { request_type_e::AUTHENTICATE_ALT_REQUEST, & to_AuthenticateAltRequest },
        { request_type_e::CLOSE_SESSION_REQUEST,    & to_CloseSessionRequest },
        { request_type_e::GET_USER_ID,              & to_GetUserIdRequest },
        { request_type_e::GetSessionInfoRequest,    & to_GetSessionInfoRequest },
    };

    auto it = funcs.find( type );

    if( it == funcs.end() )
        throw MalformedRequest( "unknown request type" );

    return it->second( r );
}

ForwardMessage * to_AuthenticateRequest( const generic_request::Request & r )
{
    std::unique_ptr<AuthenticateRequest> res( new AuthenticateRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

ForwardMessage * to_AuthenticateAltRequest( const generic_request::Request & r )
{
    std::unique_ptr<AuthenticateAltRequest> res( new AuthenticateAltRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

ForwardMessage * to_CloseSessionRequest( const generic_request::Request & r )
{
    std::unique_ptr<CloseSessionRequest> res( new CloseSessionRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

ForwardMessage * to_GetUserIdRequest( const generic_request::Request & r )
{
    std::unique_ptr<GetUserIdRequest> res( new GetUserIdRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

ForwardMessage * to_GetSessionInfoRequest( const generic_request::Request & r )
{
    std::unique_ptr<GetSessionInfoRequest> res( new GetSessionInfoRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

} // namespace parser

} // namespace generic_protocol
