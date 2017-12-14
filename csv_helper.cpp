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

// $Revision: 8501 $ $Date:: 2017-12-13 #$ $Author: serge $

#include "csv_helper.h"                 // self

#include <typeinfo>                     // typeid

#include "../utils/csv_helper.h"        // CsvHelper
#include "../utils/assert.h"            // ASSERT

#include "str_helper.h"                 // StrHelper

#define MODULENAME      "generic_protocol::CsvHelper"

namespace generic_protocol
{

std::string CsvHelper::to_csv( const BackwardMessage & r )
{
    if( typeid( r ) == typeid( ErrorResponse ) )
    {
        return to_csv( static_cast<const ErrorResponse&>( r ) );
    }
    else if( typeid( r ) == typeid( AuthenticateResponse ) )
    {
        return to_csv( static_cast<const AuthenticateResponse&>( r ) );
    }
    else if( typeid( r ) == typeid( CloseSessionResponse ) )
    {
        return to_csv( static_cast<const CloseSessionResponse&>( r ) );
    }
    else if( typeid( r ) == typeid( GetUserIdResponse ) )
    {
        return to_csv( static_cast<const GetUserIdResponse&>( r ) );
    }
    else if( typeid( r ) == typeid( GetSessionInfoResponse ) )
    {
        return to_csv( static_cast<const GetSessionInfoResponse&>( r ) );
    }
    else
    {
        ASSERT( 0 );
    }

    return std::string();
}

std::ostream & write( std::ostream & os, const SessionInfo & r )
{
    return utils::CsvHelper::write(
            os,
            r.user_id,
            r.start_time,
            r.expiration_time );
}

std::string CsvHelper::to_csv( const ErrorResponse & r )
{
    return utils::CsvHelper::to_csv( "ERROR", r.type, r.descr );
}

std::string CsvHelper::to_csv( const AuthenticateResponse & r )
{
    return utils::CsvHelper::to_csv( "AUTHENTICATE_RESPONSE", r.session_id );
}

std::string CsvHelper::to_csv( const CloseSessionResponse & r )
{
    return utils::CsvHelper::to_csv( "CLOSE_SESSION_RESPONSE" );
}

std::string CsvHelper::to_csv( const GetUserIdResponse & r )
{
    return utils::CsvHelper::to_csv( "GET_USER_ID_RESPONSE", r.user_id );
}

std::string CsvHelper::to_csv( const GetSessionInfoResponse & r )
{
    std::ostringstream os;

    utils::CsvHelper::write( os, "GetSessionInfoResponse" );
    write( os, r.session_info );

    return os.str();
}

} // namespace generic_protocol
