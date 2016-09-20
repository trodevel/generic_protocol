/*

Enums.

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

// $Revision: 4437 $ $Date:: 2016-09-19 #$ $Author: serge $

#ifndef LIB_GENERIC_PROTOCOL_ENUMS_H
#define LIB_GENERIC_PROTOCOL_ENUMS_H

namespace generic_protocol
{

enum class request_type_e
{
    UNDEF,
    AUTHENTICATE_REQUEST,
    AUTHENTICATE_ALT_REQUEST,
    CLOSE_SESSION_REQUEST,
    GET_USER_ID_REQUEST
};

} // namespace generic_protocol

#endif // LIB_GENERIC_PROTOCOL_ENUMS_H
