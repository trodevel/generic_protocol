<?php

namespace generic_protocol;


// includes
require_once __DIR__.'/../basic_parser/request_encoder.php';

// enums

function to_generic_request__ErrorResponse_type_e( $prefix, $r )
{
    $res = \basic_parser\to_generic_request__int( $prefix, $r );

    return $res;
}

// objects

function to_generic_request__SessionInfo( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".USER_ID", $r->user_id );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".START_TIME", $r->start_time );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".EXPIRATION_TIME", $r->expiration_time );

    return $res;
}

// base messages

function to_generic_request__ForwardMessage( & $r )
{
    $res = "";

    return $res;
}

function to_generic_request__BackwardMessage( & $r )
{
    $res = "";

    return $res;
}

function to_generic_request__Request( & $r )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__string( "SESSION_ID", $r->session_id );

    return $res;
}

// messages

function to_generic_request__ErrorResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "generic/ErrorResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );

    $res .= "&" . to_generic_request__ErrorResponse_type_e( "TYPE", $r->type );
    $res .= "&" . \basic_parser\to_generic_request__string( "DESCR", $r->descr );

    return $res;
}

function to_generic_request__AuthenticateRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "generic/AuthenticateRequest" );

    // base class
    $res .= to_generic_request__ForwardMessage( $r );

    $res .= "&" . \basic_parser\to_generic_request__string( "USER_LOGIN", $r->user_login );
    $res .= "&" . \basic_parser\to_generic_request__string( "PASSWORD", $r->password );

    return $res;
}

function to_generic_request__AuthenticateAltRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "generic/AuthenticateAltRequest" );

    // base class
    $res .= to_generic_request__ForwardMessage( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "USER_ID", $r->user_id );
    $res .= "&" . \basic_parser\to_generic_request__string( "PASSWORD", $r->password );

    return $res;
}

function to_generic_request__AuthenticateResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "generic/AuthenticateResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );

    $res .= "&" . \basic_parser\to_generic_request__string( "SESSION_ID", $r->session_id );

    return $res;
}

function to_generic_request__CloseSessionRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "generic/CloseSessionRequest" );

    // base class
    $res .= to_generic_request__ForwardMessage( $r );

    $res .= "&" . \basic_parser\to_generic_request__string( "SESSION_ID", $r->session_id );

    return $res;
}

function to_generic_request__CloseSessionResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "generic/CloseSessionResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );


    return $res;
}

function to_generic_request__GetUserIdRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "generic/GetUserIdRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__string( "USER_LOGIN", $r->user_login );

    return $res;
}

function to_generic_request__GetUserIdResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "generic/GetUserIdResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "USER_ID", $r->user_id );

    return $res;
}

function to_generic_request__GetSessionInfoRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "generic/GetSessionInfoRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__string( "ID", $r->id );

    return $res;
}

function to_generic_request__GetSessionInfoResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "generic/GetSessionInfoResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );

    $res .= "&" . to_generic_request__SessionInfo( "SESSION_INFO", $r->session_info );

    return $res;
}

// generic

function to_generic_request( $obj )
{
    $handler_map = array(
        // messages
        'generic_protocol\ErrorResponse'         => 'to_generic_request__ErrorResponse',
        'generic_protocol\AuthenticateRequest'         => 'to_generic_request__AuthenticateRequest',
        'generic_protocol\AuthenticateAltRequest'         => 'to_generic_request__AuthenticateAltRequest',
        'generic_protocol\AuthenticateResponse'         => 'to_generic_request__AuthenticateResponse',
        'generic_protocol\CloseSessionRequest'         => 'to_generic_request__CloseSessionRequest',
        'generic_protocol\CloseSessionResponse'         => 'to_generic_request__CloseSessionResponse',
        'generic_protocol\GetUserIdRequest'         => 'to_generic_request__GetUserIdRequest',
        'generic_protocol\GetUserIdResponse'         => 'to_generic_request__GetUserIdResponse',
        'generic_protocol\GetSessionInfoRequest'         => 'to_generic_request__GetSessionInfoRequest',
        'generic_protocol\GetSessionInfoResponse'         => 'to_generic_request__GetSessionInfoResponse',
    );

    $type = get_class( $obj );

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\generic_protocol\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return NULL;
}

# namespace_end generic_protocol


?>
