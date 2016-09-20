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

// $Revision: 4439 $ $Date:: 2016-09-19 #$ $Author: serge $

#include "../generic_request/request.h"    // generic_request::Request
#include "enums.h"              // request_type_e
#include "generic_protocol.h"   // Request...

namespace generic_protocol
{

class RequestParser
{
public:

    static request_type_e   detect_request_type( const generic_request::Request & r );

    static ForwardMessage *         to_forward_message( const generic_request::Request & r );

    static AuthenticateRequest *    to_authenticate_request( const generic_request::Request & r );
    static AuthenticateAltRequest * to_authenticate_alt_request( const generic_request::Request & r );
    static CloseSessionRequest *    to_close_session_request( const generic_request::Request & r );
    static Request *                to_request( Request * res, const generic_request::Request & r );
    static GetUserIdRequest *       to_get_user_id( const generic_request::Request & r );
};

} // namespace generic_protocol
