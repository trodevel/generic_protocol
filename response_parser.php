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

// $Revision: 3623 $ $Date:: 2016-04-04 #$ $Author: serge $

namespace generic_protocol;

require_once 'php_snippets/convert_csv_to_array.php';      // convert_csv_to_array()
require_once 'generic_protocol.php';

function parse_error_response( & $resp )
{
    // ERROR;1;authentication failed;

    $res = new ErrorResponse;

    $res->type  = $resp[1];
    $res->descr = $resp[2];

    return $res;
}

function parse_authenticate_response( & $resp )
{
    // AUTHENTICATE_RESPONSE;b3ef4ab3-2c1c-4590-8d9c-a764ec068dbf;

    $res = new AutheticateResponse;

    $res->session_id    = $resp[1];

    return $res;
}

function parse_close_session_response( & $resp )
{
    // SESSION_CLOSE_RESPONSE;

    $res = new CloseSessionResponse;

    return $res;
}

function create_parse_error()
{
    // ERROR_RESPONSE;1;authentication failed;

    $res = new ErrorResponse;

    $res->type  = ErrorResponse::PARSE_ERROR;
    $res->descr = "cannot parse response";

    return $res;
}

function parse_response( $arr )
{
    if( sizeof( $arr ) < 1 )
        return false;

    $resp = convert_csv_to_array( $arr );

    //echo "resp[0][0]=" . $resp[0][0] . "<br>";
    //echo "resp[0][1]=" . $resp[0][1] . "<br>";

    if( $resp[0][0] == 'ERROR' )
        return parse_error_response( $resp[0] );

    if( $resp[0][0] == 'AUTHENTICATE_RESPONSE' )
        return parse_authenticate_response( $resp[0] );

    if( $resp[0][0] == 'CLOSE_SESSION_RESPONSE' )
        return parse_close_session_response( $resp[0] );

    return create_parse_error;
}

?>
