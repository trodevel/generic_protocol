/*

String Helper. Provides to_string() function.

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

// $Revision: 12973 $ $Date:: 2020-05-07 #$ $Author: serge $

#include "str_helper.h"             // self

#include "basic_parser/str_helper.h"

#include <sstream>                  // std::ostringstream
#include <map>

namespace generic_protocol
{

namespace str_helper
{

using ::basic_parser::str_helper::write;

#define TUPLE_VAL_STR(_x_)  _x_,#_x_
#define TUPLE_STR_VAL(_x_)  #_x_,_x_

#define MAP_INSERT_VAL( _m, _val )      _m.insert( Map::value_type( _val ) )

std::ostream & write( std::ostream & os, const ErrorResponse::type_e & r )
{
    typedef ErrorResponse::type_e Type;
    typedef std::map< Type , std::string > Map;
    static Map m =
    {
            { Type:: TUPLE_VAL_STR( AUTHENTICATION_ERROR ) },
            { Type:: TUPLE_VAL_STR( NOT_PERMITTED ) },
            { Type:: TUPLE_VAL_STR( INVALID_ARGUMENT ) },
            { Type:: TUPLE_VAL_STR( RUNTIME_ERROR ) },
    };

    auto it = m.find( r );

    static const std::string undef( "?" );

    if( it != m.end() )
        return write( os, it->second );

    return write( os, undef );
}

std::ostream & write( std::ostream & os, const SessionInfo & r )
{
    os << "(";

    write( os, " user_id=" ); write( os, r.user_id );
    write( os, " start_time=" ); write( os, r.start_time );
    write( os, " expiration_time=" ); write( os, r.expiration_time );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const Object & r )
{
    return os;
}

std::ostream & write( std::ostream & os, const Request & r )
{
    os << " session_id = "; write( os, r.session_id );

    return os;
}

std::ostream & write( std::ostream & os, const BackwardMessage & r )
{
    return os;
}

std::ostream & write( std::ostream & os, const ErrorResponse & r )
{
    os << " type = "; write( os, r.type );
    os << " descr = "; write( os, r.descr );

    return os;
}

std::ostream & write( std::ostream & os, const AuthenticateResponse & r )
{
    os << " session_id = "; write( os, r.session_id );

    return os;
}

std::ostream & write( std::ostream & os, const CloseSessionResponse & r )
{
    return os;
}

std::ostream & write( std::ostream & os, const GetUserIdRequest & r )
{
    write( os, static_cast<const Request&>( r ) );

    os << " user_login = "; write( os, r.user_login );

    return os;
}

std::ostream & write( std::ostream & os, const GetUserIdResponse & r )
{
    os << " user_id = "; write( os, r.user_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetSessionInfoRequest & r )
{
    write( os, static_cast<const Request&>( r ) );

    os << " session_id = "; write( os, r.session_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetSessionInfoResponse & r )
{
    os << " session_info = "; write( os, r.session_info );

    return os;
}

} // namespace str_helper

} // namespace generic_protocol
