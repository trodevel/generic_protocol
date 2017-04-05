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

// $Revision: 3600 $ $Date:: 2016-04-02 #$ $Author: serge $

#include "str_helper.h"             // self

#include <sstream>                  // std::ostringstream
#include <map>

namespace generic_protocol
{

#define TUPLE_VAL_STR(_x_)  _x_,#_x_
#define TUPLE_STR_VAL(_x_)  #_x_,_x_

#define MAP_INSERT_VAL( _m, _val )      _m.insert( Map::value_type( _val ) )

const std::string & StrHelper::to_string( const ErrorResponse::type_e l )
{
    typedef std::map< ErrorResponse::type_e , std::string > Map;
    static Map m =
    {
            { ErrorResponse::type_e:: TUPLE_VAL_STR( AUTHENTICATION_ERROR ) },
            { ErrorResponse::type_e:: TUPLE_VAL_STR( NOT_PERMITTED ) },
            { ErrorResponse::type_e:: TUPLE_VAL_STR( INVALID_ARGUMENT ) },
            { ErrorResponse::type_e:: TUPLE_VAL_STR( RUNTIME_ERROR ) },
    };

    auto it = m.find( l );

    static const std::string undef( "?" );

    if( it == m.end() )
        return undef;

    return it->second;
}

} // namespace generic_protocol
