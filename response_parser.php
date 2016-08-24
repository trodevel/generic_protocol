<?php

/*

Response Parser.

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

// $Revision: 4395 $ $Date:: 2016-08-19 #$ $Author: serge $

namespace generic_protocol;

require_once '../php_snippets/convert_csv_to_array.php';   // convert_csv_to_array()
require_once 'generic_protocol.php';

function parse_error_response( & $resp )
{
    // ERROR;1;authentication failed;

    $res = new ErrorResponse( $resp[1], $resp[2] );

    return $res;
}

function parse_authenticate_response( & $resp )
{
    // AUTHENTICATE_RESPONSE;b3ef4ab3-2c1c-4590-8d9c-a764ec068dbf;

    $res = new AuthenticateResponse( $resp[1] );

    return $res;
}

function parse_close_session_response( & $resp )
{
    // CLOSE_SESSION_RESPONSE;

    $res = new CloseSessionResponse;

    return $res;
}

function create_parse_error()
{
    // ERROR_RESPONSE;1;authentication failed;

    $res = new ErrorResponse( ErrorResponse::PARSE_ERROR, "cannot parse response" );

    return $res;
}

function get_response_type( $csv_arr )
{
    if( sizeof( $csv_arr ) < 1 )
        return '?';

    $type = $csv_arr[0][0];

    switch( $type )
    {
    case 'ERROR':
    case 'AUTHENTICATE_RESPONSE':
    case 'CLOSE_SESSION_RESPONSE':
        return $type;
    default:
        break;
    }

    return '?';
}

function parse_csv_array( $csv_arr )
{
    $type = get_response_type( $csv_arr );

    switch( $type )
    {
    case 'ERROR':
        return parse_error_response( $csv_arr[0] );
    case 'AUTHENTICATE_RESPONSE':
        return parse_authenticate_response( $csv_arr[0] );
    case 'CLOSE_SESSION_RESPONSE':
        return parse_close_session_response( $csv_arr[0] );
    default:
        break;
    }

    return create_parse_error();
}

function parse_response( $arr )
{
    if( sizeof( $arr ) < 1 )
        return false;

    $csv_arr = convert_csv_to_array( $arr );

    return parse_csv_array( $csv_arr );
}

?>
