/*

CSV response encoder.

Copyright (C) 2015 Sergey Kolevatov

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

// $Revision: 12721 $ $Date:: 2020-02-14 #$ $Author: serge $

#ifndef LIB_GENERIC_PROTOCOL_CSV_HELPER_H
#define LIB_GENERIC_PROTOCOL_CSV_HELPER_H

#include "protocol.h"       // ErrorResponse, ...

#include <sstream>                  // std::ostream

namespace generic_protocol
{

namespace csv_helper
{

std::ostream & write( std::ostream & os, const ErrorResponse & r );
std::ostream & write( std::ostream & os, const AuthenticateResponse & r );
std::ostream & write( std::ostream & os, const CloseSessionResponse & r );
std::ostream & write( std::ostream & os, const GetUserIdResponse & r );
std::ostream & write( std::ostream & os, const GetSessionInfoResponse & r );
std::ostream & write( std::ostream & os, const SessionInfo & r );

std::ostream & write( std::ostream & os, const Object & r );
std::ostream & write( std::ostream & os, const SessionInfo & r );

std::string to_csv( const Object & r );

} // namespace csv_helper

} // namespace generic_protocol

#endif // LIB_GENERIC_PROTOCOL_CSV_HELPER_H
