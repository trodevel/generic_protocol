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

// $Revision: 3609 $ $Date:: 2016-04-03 #$ $Author: serge $

#include <stdexcept>            // std::runtime_error

#include "../server_core/generic_request.h"    // GenericRequest
#include "enums.h"              // request_type_e
#include "generic_protocol.h"   // Request...

namespace generic_protocol
{

class RequestParser
{
public:
    struct MalformedRequest: public std::runtime_error
    {
        MalformedRequest( const std::string & str ):
            std::runtime_error( str )
        {}
    };


public:

    static request_type_e   detect_request_type( const server_core::GenericRequest & r );

    static AuthenticateRequest *    to_authenticate_request( const server_core::GenericRequest & r );
    static CloseSessionRequest *    to_close_session_request( const server_core::GenericRequest & r );
};

} // namespace generic_protocol
