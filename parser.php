<?php

namespace generic_protocol;


// includes
require_once __DIR__.'/../basic_parser/parser.php';

// enums

function parse_ErrorResponse_type_e( & $csv_arr, & $offset )
{
    $res = \basic_parser\parse_int( $csv_arr, $offset );

    return $res;
}

// objects

function parse_SessionInfo( & $csv_arr, & $offset )
{
    $res = new SessionInfo;

    $res->user_id = \basic_parser\parse_int( $csv_arr, $offset );
    $res->start_time = \basic_parser\parse_int( $csv_arr, $offset );
    $res->expiration_time = \basic_parser\parse_int( $csv_arr, $offset );

    return $res;
}

// base messages

function parse_ForwardMessage( & $res, & $csv_arr, & $offset )
{

}

function parse_BackwardMessage( & $res, & $csv_arr, & $offset )
{

}

function parse_Request( & $res, & $csv_arr, & $offset )
{
    $res->session_id = \basic_parser\parse_string( $csv_arr, $offset );

}

// messages

function parse_ErrorResponse( & $csv_arr )
{
    $res = new ErrorResponse;

    $offset = 1;

    // base class
    parse_BackwardMessage( $res, $csv_arr, $offset );

    $res->type = parse_ErrorResponse_type_e( $csv_arr, $offset );
    $res->descr = \basic_parser\parse_string( $csv_arr, $offset );

    return $res;
}

function parse_AuthenticateRequest( & $csv_arr )
{
    $res = new AuthenticateRequest;

    $offset = 1;

    // base class
    parse_ForwardMessage( $res, $csv_arr, $offset );

    $res->user_login = \basic_parser\parse_string( $csv_arr, $offset );
    $res->password = \basic_parser\parse_string( $csv_arr, $offset );

    return $res;
}

function parse_AuthenticateAltRequest( & $csv_arr )
{
    $res = new AuthenticateAltRequest;

    $offset = 1;

    // base class
    parse_ForwardMessage( $res, $csv_arr, $offset );

    $res->user_id = \basic_parser\parse_int( $csv_arr, $offset );
    $res->password = \basic_parser\parse_string( $csv_arr, $offset );

    return $res;
}

function parse_AuthenticateResponse( & $csv_arr )
{
    $res = new AuthenticateResponse;

    $offset = 1;

    // base class
    parse_BackwardMessage( $res, $csv_arr, $offset );

    $res->session_id = \basic_parser\parse_string( $csv_arr, $offset );

    return $res;
}

function parse_CloseSessionRequest( & $csv_arr )
{
    $res = new CloseSessionRequest;

    $offset = 1;

    // base class
    parse_ForwardMessage( $res, $csv_arr, $offset );

    $res->session_id = \basic_parser\parse_string( $csv_arr, $offset );

    return $res;
}

function parse_CloseSessionResponse( & $csv_arr )
{
    $res = new CloseSessionResponse;

    $offset = 1;

    // base class
    parse_BackwardMessage( $res, $csv_arr, $offset );


    return $res;
}

function parse_GetUserIdRequest( & $csv_arr )
{
    $res = new GetUserIdRequest;

    $offset = 1;

    // base class
    parse_Request( $res, $csv_arr, $offset );

    $res->user_login = \basic_parser\parse_string( $csv_arr, $offset );

    return $res;
}

function parse_GetUserIdResponse( & $csv_arr )
{
    $res = new GetUserIdResponse;

    $offset = 1;

    // base class
    parse_BackwardMessage( $res, $csv_arr, $offset );

    $res->user_id = \basic_parser\parse_int( $csv_arr, $offset );

    return $res;
}

function parse_GetSessionInfoRequest( & $csv_arr )
{
    $res = new GetSessionInfoRequest;

    $offset = 1;

    // base class
    parse_Request( $res, $csv_arr, $offset );

    $res->id = \basic_parser\parse_string( $csv_arr, $offset );

    return $res;
}

function parse_GetSessionInfoResponse( & $csv_arr )
{
    $res = new GetSessionInfoResponse;

    $offset = 1;

    // base class
    parse_BackwardMessage( $res, $csv_arr, $offset );

    $res->session_info = parse_SessionInfo( $csv_arr, $offset );

    return $res;
}

// generic

class Parser
{

protected static function parse_csv_array( $csv_arr )
{
    if( sizeof( $csv_arr ) < 1 )
        return self::create_parse_error();

    $handler_map = array(
        // messages
        'generic_protocol\ErrorResponse'         => 'parse_ErrorResponse',
        'generic_protocol\AuthenticateRequest'         => 'parse_AuthenticateRequest',
        'generic_protocol\AuthenticateAltRequest'         => 'parse_AuthenticateAltRequest',
        'generic_protocol\AuthenticateResponse'         => 'parse_AuthenticateResponse',
        'generic_protocol\CloseSessionRequest'         => 'parse_CloseSessionRequest',
        'generic_protocol\CloseSessionResponse'         => 'parse_CloseSessionResponse',
        'generic_protocol\GetUserIdRequest'         => 'parse_GetUserIdRequest',
        'generic_protocol\GetUserIdResponse'         => 'parse_GetUserIdResponse',
        'generic_protocol\GetSessionInfoRequest'         => 'parse_GetSessionInfoRequest',
        'generic_protocol\GetSessionInfoResponse'         => 'parse_GetSessionInfoResponse',
    );

    $type = $csv_arr[0][0];

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\generic_protocol\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return NULL;
}

}

# namespace_end generic_protocol


?>
