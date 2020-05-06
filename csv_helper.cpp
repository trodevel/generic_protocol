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

// $Revision: 12949 $ $Date:: 2020-04-30 #$ $Author: serge $

#include "csv_helper.h"                 // self

#include <typeinfo>                     // typeid

#include "utils/csv_helper.h"           // CsvHelper
#include "utils/utils_assert.h"         // ASSERT

#include "str_helper.h"                 // StrHelper

#define MODULENAME      "generic_protocol::CsvHelper"

namespace generic_protocol
{

namespace csv_helper
{

std::ostream & write( std::ostream & os, const BackwardMessage & r )
{
    return os;
}

std::ostream & write( std::ostream & os, const ErrorResponse & r )
{
    os << utils::CsvHelper::to_csv( "ERROR", r.type, r.descr );
    return os;
}

std::ostream & write( std::ostream & os, const AuthenticateResponse & r )
{
    os << utils::CsvHelper::to_csv( "AUTHENTICATE_RESPONSE", r.session_id );
    return os;
}

std::ostream & write( std::ostream & os, const CloseSessionResponse & r )
{
    os << utils::CsvHelper::to_csv( "CLOSE_SESSION_RESPONSE" );
    return os;
}

std::ostream & write( std::ostream & os, const GetUserIdResponse & r )
{
    os << utils::CsvHelper::to_csv( "GET_USER_ID_RESPONSE", r.user_id );
    return os;
}

std::ostream & write( std::ostream & os, const GetSessionInfoResponse & r )
{
    utils::CsvHelper::write( os, "GetSessionInfoResponse" );
    write( os, r.session_info );

    return os;
}

std::ostream & write( std::ostream & os, const Object & r )
{
    if( typeid( r ) == typeid( ErrorResponse ) )
    {
        return write( os, static_cast<const ErrorResponse&>( r ) );
    }
    else if( typeid( r ) == typeid( AuthenticateResponse ) )
    {
        return write( os, static_cast<const AuthenticateResponse&>( r ) );
    }
    else if( typeid( r ) == typeid( CloseSessionResponse ) )
    {
        return write( os, static_cast<const CloseSessionResponse&>( r ) );
    }
    else if( typeid( r ) == typeid( GetUserIdResponse ) )
    {
        return write( os, static_cast<const GetUserIdResponse&>( r ) );
    }
    else if( typeid( r ) == typeid( GetSessionInfoResponse ) )
    {
        return write( os, static_cast<const GetSessionInfoResponse&>( r ) );
    }
    else if( typeid( r ) == typeid( BackwardMessage ) )
    {
        return write( os, static_cast<const BackwardMessage&>( r ) );
    }
    else
    {
        ASSERT( 0 );
    }

    return os;
}

std::ostream & write( std::ostream & os, const SessionInfo & r )
{
    utils::CsvHelper::write(
            os,
            r.user_id,
            r.start_time,
            r.expiration_time );

    return os;
}

std::string to_csv( const Object & r )
{
    std::ostringstream os;

    write( os, r );

    return os.str();
}

} // namespace csv_helper

} // namespace generic_protocol
