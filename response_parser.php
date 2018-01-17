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

// $Revision: 8515 $ $Date:: 2018-01-16 #$ $Author: serge $

namespace generic_protocol;

require_once __DIR__.'/../php_snippets/convert_csv_to_array.php';   // convert_csv_to_array()
require_once 'generic_protocol.php';

function parse_error_response( & $resp )
{
    // ERROR;1;authentication failed;

    $res = new ErrorResponse( intval( $resp[1] ), $resp[2] );

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

function parse_get_user_id_response( & $resp )
{
    // GET_USER_ID_RESPONSE;123456789;
    
    $res = new GetUserIdResponse( intval( $resp[1] ) );
    
    return $res;
}

function parse_SessionInfo( & $csv_arr, $offset )
{
    $res = new SessionInfo;

    $res->user_id           = intval( $csv_arr[ $offset++ ] );
    $res->start_time        = intval( $csv_arr[ $offset++ ] );
    $res->expiration_time   = intval( $csv_arr[ $offset++ ] );

    return $res;
}

function parse_GetSessionInfoResponse( & $resp )
{
    // GetSessionInfoResponse;123;1515700200;1515701100;

    $res = new GetSessionInfoResponse;

    $offs = 1;

    $res->session_info  = parse_SessionInfo( $resp, $offs );

    return $res;
}

class ResponseParser
{
    public static function parse( $arr )
    {
        if( sizeof( $arr ) < 1 )
            return false;

        $csv_arr = \convert_csv_to_array( $arr );

        return static::parse_csv_array( $csv_arr );
    }

    protected static function parse_csv_array( $csv_arr )
    {
        if( sizeof( $csv_arr ) < 1 )
            return self::create_parse_error();

        $type = $csv_arr[0][0];

        $func_map = array(
            'ERROR'                     => 'parse_error_response',
            'AUTHENTICATE_RESPONSE'     => 'parse_authenticate_response',
            'CLOSE_SESSION_RESPONSE'    => 'parse_close_session_response',
            'GET_USER_ID_RESPONSE'      => 'parse_get_user_id_response',
            'GetSessionInfoResponse'    => 'parse_GetSessionInfoResponse'
        );

        if( array_key_exists( $type, $func_map ) )
        {
            $func = '\\generic_protocol\\' . $func_map[ $type ];
            return $func( $csv_arr[0] );
        }

        return self::create_parse_error();
    }

    protected static function create_parse_error()
    {
        // ERROR_RESPONSE;1;authentication failed;

        $res = new ErrorResponse( ErrorResponse::PARSE_ERROR, "cannot parse response" );

        return $res;
    }

}

?>
