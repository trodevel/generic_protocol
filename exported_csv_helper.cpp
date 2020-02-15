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

// includes
#include "exported_csv_helper.h"
#include "csv_helper.h"

namespace basic_parser
{

namespace csv_encoder
{

std::ostream & write( std::ostream & os, const generic_protocol::ErrorResponse & r )
{
    return generic_protocol::csv_helper::write( os, r );
}

std::ostream & write( std::ostream & os, const generic_protocol::AuthenticateResponse & r )
{
    return generic_protocol::csv_helper::write( os, r );
}

std::ostream & write( std::ostream & os, const generic_protocol::CloseSessionResponse & r )
{
    return generic_protocol::csv_helper::write( os, r );
}

std::ostream & write( std::ostream & os, const generic_protocol::GetUserIdResponse & r )
{
    return generic_protocol::csv_helper::write( os, r );
}

std::ostream & write( std::ostream & os, const generic_protocol::GetSessionInfoResponse & r )
{
    return generic_protocol::csv_helper::write( os, r );
}

std::ostream & write( std::ostream & os, const generic_protocol::Object & r )
{
    return generic_protocol::csv_helper::write( os, r );
}

std::ostream & write( std::ostream & os, const generic_protocol::BackwardMessage & r )
{
    return generic_protocol::csv_helper::write( os, r );
}

std::ostream & write( std::ostream & os, const generic_protocol::SessionInfo & r )
{
    return generic_protocol::csv_helper::write( os, r );
}

} // namespace csv_encoder

} // namespace basic_parser

