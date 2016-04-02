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

// $Revision: 3604 $ $Date:: 2016-04-02 #$ $Author: serge $

#include "csv_helper.h"                 // self

#include "../utils/csv_helper.h"        // CsvHelper
#include "../utils/assert.h"            // ASSERT

#include "str_helper.h"                 // StrHelper

#define MODULENAME      "generic_protocol::CsvHelper"

namespace generic_protocol
{

std::string CsvHelper::to_csv( const ErrorResponse & r )
{
    return utils::CsvHelper::to_csv( "ERROR", StrHelper::to_string( r.type ), r.descr );
}

std::string CsvHelper::to_csv( const AuthenticateResponse & r )
{
    return utils::CsvHelper::to_csv( "AUTHENTICATE_RESPONSE", r.session_id );
}

std::string CsvHelper::to_csv( const CloseSessionResponse & r )
{
    return utils::CsvHelper::to_csv( "CLOSE_SESSION_RESPONSE" );
}

} // namespace generic_protocol
