/*

STR Helpers.

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

// $Revision: 12779 $ $Date:: 2020-02-21 #$ $Author: serge $

// includes
#include "exported_str_helper.h"
#include "str_helper.h"

#include "basic_parser/exported_str_helper.h"

namespace basic_parser
{

namespace str_helper
{

std::ostream & write( std::ostream & os, const generic_protocol::ErrorResponse::type_e & r )
{
    os << generic_protocol::StrHelper::to_string( r );

    return os;
}

std::ostream & write( std::ostream & os, const generic_protocol::SessionInfo & r )
{
    os << "(";

    write( os, " user_id=" ); write( os, r.user_id );
    write( os, " start_time=" ); write( os, r.start_time );
    write( os, " expiration_time=" ); write( os, r.expiration_time );

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const generic_protocol::Request & r )
{
    os << " session_id = "; write( os, r.session_id );

    return os;
}

std::ostream & write( std::ostream & os, const generic_protocol::ErrorResponse & r )
{
    os << " type = "; write( os, r.type );
    os << " descr = "; write( os, r.descr );

    return os;
}

std::ostream & write( std::ostream & os, const generic_protocol::AuthenticateResponse & r )
{
    os << " session_id = "; write( os, r.session_id );

    return os;
}

std::ostream & write( std::ostream & os, const generic_protocol::CloseSessionResponse & r )
{
    return os;
}

std::ostream & write( std::ostream & os, const generic_protocol::GetUserIdRequest & r )
{
    write( os, static_cast<const generic_protocol::Request&>( r ) );

    os << " user_login = "; write( os, r.user_login );

    return os;
}

std::ostream & write( std::ostream & os, const generic_protocol::GetUserIdResponse & r )
{
    os << " user_id = "; write( os, r.user_id );

    return os;
}

std::ostream & write( std::ostream & os, const generic_protocol::GetSessionInfoRequest & r )
{
    write( os, static_cast<const generic_protocol::Request&>( r ) );

    os << " session_id = "; write( os, r.session_id );

    return os;
}

std::ostream & write( std::ostream & os, const generic_protocol::GetSessionInfoResponse & r )
{
    os << " session_info = "; write( os, r.session_info );

    return os;
}

std::ostream & write( std::ostream & os, const generic_protocol::Object & r )
{
    return os;
}

std::ostream & write( std::ostream & os, const generic_protocol::BackwardMessage & r )
{
    return os;
}

} // namespace str_helper

} // namespace basic_parser

