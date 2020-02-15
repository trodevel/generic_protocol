/*

CSV Helpers.

Copyright (C) 2020 Sergey Kolevatov

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

// $Revision: 12725 $ $Date:: 2020-02-14 #$ $Author: serge $

#ifndef LIB_GENERIC_PROTOCOL__EXPORTED_CSV_HELPER_H
#define LIB_GENERIC_PROTOCOL__EXPORTED_CSV_HELPER_H

#include "protocol.h"

namespace basic_parser
{

namespace csv_encoder
{

std::ostream & write( std::ostream & os, const generic_protocol::ErrorResponse & r );
std::ostream & write( std::ostream & os, const generic_protocol::AuthenticateResponse & r );
std::ostream & write( std::ostream & os, const generic_protocol::CloseSessionResponse & r );
std::ostream & write( std::ostream & os, const generic_protocol::GetUserIdResponse & r );
std::ostream & write( std::ostream & os, const generic_protocol::GetSessionInfoResponse & r );
std::ostream & write( std::ostream & os, const generic_protocol::Object & r );
std::ostream & write( std::ostream & os, const generic_protocol::BackwardMessage & r );
std::ostream & write( std::ostream & os, const generic_protocol::SessionInfo & r );

} // namespace csv_encoder

} // namespace basic_parser

#endif // LIB_GENERIC_PROTOCOL__EXPORTED_CSV_HELPER_H
