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

// $Revision: 6542 $ $Date:: 2017-04-07 #$ $Author: serge $

#include "../generic_request/request.h"    // generic_request::Request
#include "enums.h"              // request_type_e
#include "generic_protocol.h"   // Request...

namespace generic_protocol
{

class RequestParser
{
public:

    static request_type_e   detect_request_type( const generic_request::Request & r );

    static ForwardMessage *     to_forward_message( const generic_request::Request & r );

    static ForwardMessage *     to_authenticate_request( const generic_request::Request & r );
    static ForwardMessage *     to_authenticate_alt_request( const generic_request::Request & r );
    static ForwardMessage *     to_close_session_request( const generic_request::Request & r );
    static Request *            to_request( Request * res, const generic_request::Request & r );
    static ForwardMessage *     to_get_user_id( const generic_request::Request & r );
};

void get_value_or_throw( std::string & res, const std::string & key, const generic_request::Request & r );
void get_value_or_throw_uint32( uint32_t & res, const std::string & key, const generic_request::Request & r );

} // namespace generic_protocol
