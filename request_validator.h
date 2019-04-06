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

// $Revision: 10788 $ $Date:: 2019-04-07 #$ $Author: serge $

#ifndef LIB_GENERIC_PROTOCOL_REQUEST_GENERATOR_H
#define LIB_GENERIC_PROTOCOL_REQUEST_GENERATOR_H

#include "generic_protocol.h"       // Request...

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

} // namespace generic_protocol

#endif // LIB_GENERIC_PROTOCOL_REQUEST_GENERATOR_H
