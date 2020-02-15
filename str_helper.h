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

// $Revision: 12699 $ $Date:: 2020-02-04 #$ $Author: serge $

#include <string>

#include "protocol.h"       // ErrorResponse::type_e

namespace generic_protocol
{

class StrHelper
{
public:
    static const std::string & to_string( const ErrorResponse::type_e l );
};

} // namespace generic_protocol
