<?php

// $Revision: 13098 $ $Date:: 2020-05-20 #$ $Author: serge $

namespace generic_protocol;

require_once __DIR__.'/../basic_parser/request_encoder.php';

// request base ********************************************

function to_generic_request__ForwardMessage( & $obj )
{
    $res = "";

    return $res;
}

function to_generic_request__BackwardMessage( & $obj )
{
    $res = "";

    return $res;
}

// error response ******************************************

function to_generic_request__ErrorResponse( & $obj )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "ErrorResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $obj );

    $res .= "&" . \basic_parser\to_generic_request__int( "TYPE", $obj->type );
    $res .= "&" . \basic_parser\to_generic_request__string( "DESCR", $obj->descr );

    return $res;
}

// authentication messages *********************************

function to_generic_request__AuthenticateRequest( & $obj )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "AUTHENTICATE_REQUEST" );

    // base class
    $res .= to_generic_request__ForwardMessage( $obj );

    $res .= "&" . \basic_parser\to_generic_request__string( "USER_LOGIN", $obj->user_login );
    $res .= "&" . \basic_parser\to_generic_request__string( "PASSWORD", $obj->password );

    return $res;
}

function to_generic_request__AuthenticateAltRequest( & $obj )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "AUTHENTICATE_ALT_REQUEST" );

    // base class
    $res .= to_generic_request__ForwardMessage( $obj );

    $res .= "&" . \basic_parser\to_generic_request__int( "USER_ID", $obj->user_id );
    $res .= "&" . \basic_parser\to_generic_request__string( "PASSWORD", $obj->password );

    return $res;
}

function to_generic_request__AuthenticateResponse( & $obj )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "AuthenticateResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $obj );

    $res .= "&" . \basic_parser\to_generic_request__string( "SESSION_ID", $obj->session_id );

    return $res;
}

// session messages ****************************************

function to_generic_request__CloseSessionRequest( & $obj )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "CLOSE_SESSION_REQUEST" );

    // base class
    $res .= to_generic_request__ForwardMessage( $obj );

    $res .= "&" . \basic_parser\to_generic_request__string( "SESSION_ID", $obj->session_id );

    return $res;
}

function to_generic_request__CloseSessionResponse( & $obj )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "CloseSessionResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $obj );

    return $res;
}


// user id handling ****************************************

function to_generic_request__GetUserIdRequest( & $obj )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "GET_USER_ID" );

    // base class
    $res .= to_generic_request__ForwardMessage( $obj );

    $res .= "&" . \basic_parser\to_generic_request__string( "USER_LOGIN", $obj->user_login );

    return $res;
}

function to_generic_request__GetUserIdResponse( & $obj )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "GetUserIdResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $obj );

    $res .= "&" . \basic_parser\to_generic_request__int( "USER_ID", $obj->user_id );

    return $res;
}

// session info ********************************************

function to_generic_request__SessionInfo( $prefix, $obj )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".USER_ID", $obj->user_id );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".START_TIME", $obj->start_time );
    $res .= "&" . \basic_parser\to_generic_request__int( $prefix . ".EXPIRATION_TIME", $obj->expiration_time );

    return $res;
}

function to_generic_request__GetSessionInfoRequest( & $obj )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "GetSessionInfoRequest" );

    // base class
    $res .= to_generic_request__ForwardMessage( $obj );

    $res .= "&" . \basic_parser\to_generic_request__string( "SESSION_ID", $obj->session_id );

    return $res;
}

function to_generic_request__GetSessionInfoResponse( & $obj )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "GetSessionInfoResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $obj );

    $res .= "&" . to_generic_request__SessionInfo( "SESSION_INFO", $obj->session_info );

    return $res;
}

// *********************************************************

function to_generic_request( $obj )
{
    $handler_map = array(
        'generic_protocol\ErrorResponse'            => 'to_generic_request__ErrorResponse',
        'generic_protocol\AuthenticateRequest'      => 'to_generic_request__AuthenticateRequest',
        'generic_protocol\AuthenticateAltRequest'   => 'to_generic_request__AuthenticateAltRequest',
        'generic_protocol\AuthenticateResponse'     => 'to_generic_request__AuthenticateResponse',
        'generic_protocol\CloseSessionRequest'      => 'to_generic_request__CloseSessionRequest',
        'generic_protocol\CloseSessionResponse'     => 'to_generic_request__CloseSessionResponse',
        'generic_protocol\GetUserIdRequest'         => 'to_generic_request__GetUserIdRequest',
        'generic_protocol\GetUserIdResponse'        => 'to_generic_request__GetUserIdResponse',
        'generic_protocol\GetSessionInfoRequest'    => 'to_generic_request__GetSessionInfoRequest',
        'generic_protocol\GetSessionInfoResponse'   => 'to_generic_request__GetSessionInfoResponse'
    );

    $type = get_class ( $obj );

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\generic_protocol\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return NULL;
}

?>
