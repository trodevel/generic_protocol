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

// $Revision: 12746 $ $Date:: 2020-02-15 #$ $Author: serge $

#ifndef LIB_GENERIC_PROTOCOL_REQUEST_GENERATOR_H
#define LIB_GENERIC_PROTOCOL_REQUEST_GENERATOR_H

#include "protocol.h"       // Request...

namespace generic_protocol
{

class RequestValidator
{
public:
    static bool validate( const AuthenticateRequest & r );
    static bool validate( const AuthenticateAltRequest & r );
    static bool validate( const CloseSessionRequest & r );
    static bool validate( const Request & r );
    static bool validate( const GetUserIdRequest & r );
    static bool validate( const GetSessionInfoRequest & r );
};

#define THROW_IF_INT_ZERO(_var,_key)        { if( _var == 0 ) throw Parser::MalformedRequest( _key " is 0" ); }
#define THROW_IF_INT_NEG(_var,_key)         { if( _var < 0 ) throw Parser::MalformedRequest( _key " < 0" ); }
#define THROW_IF_INT_NOT_IN_RANGE(_var,_key,_min,_max)  { if( ( _var < _min ) || ( _var > _max ) ) throw Parser::MalformedRequest( _key " not in range [" + std::to_string( _min ) + "; " + std::to_string( _max ) + "]" ); }
#define THROW_IF_INT_NEG_ZERO(_var,_key)    { if( _var <= 0 ) throw Parser::MalformedRequest( _key " <= 0" ); }
#define THROW_IF_FLOAT_ZERO(_var,_key)      { if( _var == 0. ) throw Parser::MalformedRequest( _key " is 0" ); }
#define THROW_IF_FLOAT_NEG(_var,_key)       { if( _var < 0. ) throw Parser::MalformedRequest( _key " < 0" ); }
#define THROW_IF_FLOAT_NEG_ZERO(_var,_key)  { if( _var <= 0. ) throw Parser::MalformedRequest( _key " <= 0" ); }
#define THROW_IF_STRING_EMPTY(_var,_key)    { if( _var.empty() ) throw Parser::MalformedRequest( _key " is empty" ); }
#define THROW_IF_ARRAY_EMPTY(_var,_key)     { if( _var.empty() ) throw Parser::MalformedRequest( _key " is empty" ); }

} // namespace generic_protocol

#endif // LIB_GENERIC_PROTOCOL_REQUEST_GENERATOR_H
