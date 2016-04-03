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

// $Revision: 3619 $ $Date:: 2016-04-03 #$ $Author: serge $

#include "request_parser.h"         // self

#include "parser.h"                 // Parser
#include "request_validator.h"      // RequestValidator

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
        insert_inverse_pair( m, request_type_e:: TUPLE_VAL_STR( CLOSE_SESSION_REQUEST ) );
    }

    auto it = m.find( s );

    if( it == m.end() )
        return request_type_e::UNDEF;

    return it->second;
}

request_type_e  RequestParser::detect_request_type( const generic_request::Request & r )
{
    const std::string & cmd        = r.get_param( "CMD" );

    if( cmd.empty() )
        throw MalformedRequest( "CMD is not defined" );

    return to_request_type( cmd );
}


AuthenticateRequest * RequestParser::to_authenticate_request( const generic_request::Request & r )
{
    AuthenticateRequest * res = new AuthenticateRequest;

    res->user_login = r.get_param( "USER_LOGIN" );
    res->password   = r.get_param( "PASSWORD" );

    RequestValidator::validate( res );

    return res;
}

CloseSessionRequest * RequestParser::to_close_session_request( const generic_request::Request & r )
{
    CloseSessionRequest * res = new CloseSessionRequest;

    res->session_id = r.get_param( "SESSION_ID" );

    RequestValidator::validate( res );

    return res;
}

} // namespace generic_protocol
