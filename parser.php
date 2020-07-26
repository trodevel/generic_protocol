<?php

namespace generic_protocol;


// includes
require_once __DIR__.'/../basic_parser/parser.php';

// enums

function parse__ErrorResponse_type_e( & $csv_arr, & $offset )
{
    $res = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

// objects

function parse__SessionInfo( & $csv_arr, & $offset )
{
    $res = new SessionInfo;

    $res->user_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->start_time = \basic_parser\parse__int( $csv_arr, $offset );
    $res->expiration_time = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

// base messages

function parse__ForwardMessage( & $res, & $csv_arr, & $offset )
{

}

function parse__BackwardMessage( & $res, & $csv_arr, & $offset )
{

}

function parse__Request( & $res, & $csv_arr, & $offset )
{
    $res->session_id = \basic_parser\parse__string( $csv_arr, $offset );

}

// messages

function parse__ErrorResponse( & $csv_arr )
{
    $res = new ErrorResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->type = parse__ErrorResponse_type_e( $csv_arr, $offset );
    $res->descr = \basic_parser\parse__string( $csv_arr, $offset );

    return $res;
}

function parse__AuthenticateRequest( & $csv_arr )
{
    $res = new AuthenticateRequest;

    $offset = 1;

    // base class
    parse__ForwardMessage( $res, $csv_arr, $offset );

    $res->user_login = \basic_parser\parse__string( $csv_arr, $offset );
    $res->password = \basic_parser\parse__string( $csv_arr, $offset );

    return $res;
}

function parse__AuthenticateAltRequest( & $csv_arr )
{
    $res = new AuthenticateAltRequest;

    $offset = 1;

    // base class
    parse__ForwardMessage( $res, $csv_arr, $offset );

    $res->user_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->password = \basic_parser\parse__string( $csv_arr, $offset );

    return $res;
}

function parse__AuthenticateResponse( & $csv_arr )
{
    $res = new AuthenticateResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->session_id = \basic_parser\parse__string( $csv_arr, $offset );

    return $res;
}

function parse__CloseSessionRequest( & $csv_arr )
{
    $res = new CloseSessionRequest;

    $offset = 1;

    // base class
    parse__ForwardMessage( $res, $csv_arr, $offset );

    $res->session_id = \basic_parser\parse__string( $csv_arr, $offset );

    return $res;
}

function parse__CloseSessionResponse( & $csv_arr )
{
    $res = new CloseSessionResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );


    return $res;
}

function parse__GetUserIdRequest( & $csv_arr )
{
    $res = new GetUserIdRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->user_login = \basic_parser\parse__string( $csv_arr, $offset );

    return $res;
}

function parse__GetUserIdResponse( & $csv_arr )
{
    $res = new GetUserIdResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->user_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__GetSessionInfoRequest( & $csv_arr )
{
    $res = new GetSessionInfoRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->id = \basic_parser\parse__string( $csv_arr, $offset );

    return $res;
}

function parse__GetSessionInfoResponse( & $csv_arr )
{
    $res = new GetSessionInfoResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->session_info = parse__SessionInfo( $csv_arr, $offset );

    return $res;
}

// generic

class Parser extends \basic_parser\Parser
{

protected static function parse_csv_array( $csv_arr )
{
    if( sizeof( $csv_arr ) < 1 )
        return self::create_parse_error();

    $handler_map = array(
        // messages
        'generic/ErrorResponse'         => 'parse__ErrorResponse',
        'generic/AuthenticateRequest'         => 'parse__AuthenticateRequest',
        'generic/AuthenticateAltRequest'         => 'parse__AuthenticateAltRequest',
        'generic/AuthenticateResponse'         => 'parse__AuthenticateResponse',
        'generic/CloseSessionRequest'         => 'parse__CloseSessionRequest',
        'generic/CloseSessionResponse'         => 'parse__CloseSessionResponse',
        'generic/GetUserIdRequest'         => 'parse__GetUserIdRequest',
        'generic/GetUserIdResponse'         => 'parse__GetUserIdResponse',
        'generic/GetSessionInfoRequest'         => 'parse__GetSessionInfoRequest',
        'generic/GetSessionInfoResponse'         => 'parse__GetSessionInfoResponse',
    );

    $type = $csv_arr[0][0];

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\generic_protocol\\' . $handler_map[ $type ];
        return $func( $csv_arr[0] );
    }

    return NULL;
}

}

# namespace_end generic_protocol


?>
