<?php

namespace generic_protocol;


// includes
require_once __DIR__.'/../basic_parser/str_helper.php';

// enums

function to_string__ErrorResponse_type_e( $r )
{
    $map = array
    (
        ErrorResponse_type_e__INVALID_OR_EXPIRED_SESSION => 'INVALID_OR_EXPIRED_SESSION',
        ErrorResponse_type_e__NOT_PERMITTED => 'NOT_PERMITTED',
        ErrorResponse_type_e__INVALID_ARGUMENT => 'INVALID_ARGUMENT',
        ErrorResponse_type_e__RUNTIME_ERROR => 'RUNTIME_ERROR',
    );

    if( array_key_exists( $r, $map ) )
    {
        return $map[ $r ];
    }

    return '?';
}

// objects

function to_string__SessionInfo( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " user_id=" . \basic_parser\to_string__int( $r->user_id );
    $res .= " start_time=" . \basic_parser\to_string__int( $r->start_time );
    $res .= " expiration_time=" . \basic_parser\to_string__int( $r->expiration_time );

    $res .= ")";

    return $res;
}

// base messages

function to_string__ForwardMessage( & $r )
{
    $res = "";

    $res .= "(";

    // no base class

    $res .= ")";

    return $res;
}

function to_string__BackwardMessage( & $r )
{
    $res = "";

    $res .= "(";

    // no base class

    $res .= ")";

    return $res;
}

function to_string__Request( & $r )
{
    $res = "";

    $res .= "(";

    // base class
    $res .= to_string__ForwardMessage( $r );

    $res .= " session_id=" . \basic_parser\to_string__string( $r->session_id );

    $res .= ")";

    return $res;
}

// messages

function to_string__ErrorResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );

    $res .= " type=" . to_string__ErrorResponse_type_e( $r->type );
    $res .= " descr=" . \basic_parser\to_string__string( $r->descr );

    return $res;
}

function to_string__AuthenticateRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__ForwardMessage( $r );

    $res .= " user_login=" . \basic_parser\to_string__string( $r->user_login );
    $res .= " password=" . \basic_parser\to_string__string( $r->password );

    return $res;
}

function to_string__AuthenticateAltRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__ForwardMessage( $r );

    $res .= " user_id=" . \basic_parser\to_string__int( $r->user_id );
    $res .= " password=" . \basic_parser\to_string__string( $r->password );

    return $res;
}

function to_string__AuthenticateResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );

    $res .= " session_id=" . \basic_parser\to_string__string( $r->session_id );

    return $res;
}

function to_string__CloseSessionRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__ForwardMessage( $r );

    $res .= " session_id=" . \basic_parser\to_string__string( $r->session_id );

    return $res;
}

function to_string__CloseSessionResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );


    return $res;
}

function to_string__GetUserIdRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " user_login=" . \basic_parser\to_string__string( $r->user_login );

    return $res;
}

function to_string__GetUserIdResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );

    $res .= " user_id=" . \basic_parser\to_string__int( $r->user_id );

    return $res;
}

function to_string__GetSessionInfoRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " id=" . \basic_parser\to_string__string( $r->id );

    return $res;
}

function to_string__GetSessionInfoResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );

    $res .= " session_info=" . to_string__SessionInfo( $r->session_info );

    return $res;
}

// generic

function to_string( $obj )
{
    $handler_map = array(
        // objects
        'generic_protocol\SessionInfo'         => 'to_string__SessionInfo',
        // messages
        'generic_protocol\ErrorResponse'         => 'to_string__ErrorResponse',
        'generic_protocol\AuthenticateRequest'         => 'to_string__AuthenticateRequest',
        'generic_protocol\AuthenticateAltRequest'         => 'to_string__AuthenticateAltRequest',
        'generic_protocol\AuthenticateResponse'         => 'to_string__AuthenticateResponse',
        'generic_protocol\CloseSessionRequest'         => 'to_string__CloseSessionRequest',
        'generic_protocol\CloseSessionResponse'         => 'to_string__CloseSessionResponse',
        'generic_protocol\GetUserIdRequest'         => 'to_string__GetUserIdRequest',
        'generic_protocol\GetUserIdResponse'         => 'to_string__GetUserIdResponse',
        'generic_protocol\GetSessionInfoRequest'         => 'to_string__GetSessionInfoRequest',
        'generic_protocol\GetSessionInfoResponse'         => 'to_string__GetSessionInfoResponse',
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
