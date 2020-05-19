<?php

// $Revision: 13097 $ $Date:: 2020-05-19 #$ $Author: serge $

namespace generic_protocol;

require_once __DIR__.'/../basic_parser/request_encoder.php';

// request base ********************************************

function to_generic_request_ForwardMessage( & $obj )
{
    $res = "";

    return $res;
}

function to_generic_request_BackwardMessage( & $obj )
{
    $res = "";

    return $res;
}

// error response ******************************************

function to_generic_request_ErrorResponse( & $obj )
{
    // name
    $res = \basic_parser\to_generic_request_string( "CMD", "ErrorResponse" );

    // base class
    $res .= to_generic_request_BackwardMessage( $obj );

    $res .= "&" . \basic_parser\to_generic_request_int( "TYPE", $obj->type );
    $res .= "&" . \basic_parser\to_generic_request_string( "DESCR", $obj->descr );

    return $res;
}

// authentication messages *********************************

function to_generic_request_AuthenticateRequest( & $obj )
{
    // name
    $res = \basic_parser\to_generic_request_string( "CMD", "AUTHENTICATE_REQUEST" );

    // base class
    $res .= to_generic_request_ForwardMessage( $obj );

    $res .= "&" . \basic_parser\to_generic_request_string( "USER_LOGIN", $obj->user_login );
    $res .= "&" . \basic_parser\to_generic_request_string( "PASSWORD", $obj->password );

    return $res;
}

function to_generic_request_AuthenticateAltRequest( & $obj )
{
    // name
    $res = \basic_parser\to_generic_request_string( "CMD", "AUTHENTICATE_ALT_REQUEST" );

    // base class
    $res .= to_generic_request_ForwardMessage( $obj );

    $res .= "&" . \basic_parser\to_generic_request_int( "USER_ID", $obj->user_id );
    $res .= "&" . \basic_parser\to_generic_request_string( "PASSWORD", $obj->password );

    return $res;
}

function to_generic_request_AuthenticateResponse( & $obj )
{
    // name
    $res = \basic_parser\to_generic_request_string( "CMD", "AuthenticateResponse" );

    // base class
    $res .= to_generic_request_BackwardMessage( $obj );

    $res .= "&" . \basic_parser\to_generic_request_string( "SESSION_ID", $obj->session_id );

    return $res;
}

// session messages ****************************************

function to_generic_request_CloseSessionRequest( & $obj )
{
    // name
    $res = \basic_parser\to_generic_request_string( "CMD", "CLOSE_SESSION_REQUEST" );

    // base class
    $res .= to_generic_request_ForwardMessage( $obj );

    $res .= "&" . \basic_parser\to_generic_request_string( "SESSION_ID", $obj->session_id );

    return $res;
}

function to_generic_request_CloseSessionResponse( & $obj )
{
    // name
    $res = \basic_parser\to_generic_request_string( "CMD", "CloseSessionResponse" );

    // base class
    $res .= to_generic_request_BackwardMessage( $obj );

    return $res;
}


// user id handling ****************************************

function to_generic_request_GetUserIdRequest( & $obj )
{
    // name
    $res = \basic_parser\to_generic_request_string( "CMD", "GET_USER_ID" );

    // base class
    $res .= to_generic_request_ForwardMessage( $obj );

    $res .= "&" . \basic_parser\to_generic_request_string( "USER_LOGIN", $obj->user_login );

    return $res;
}

function to_generic_request_GetUserIdResponse( & $obj )
{
    // name
    $res = \basic_parser\to_generic_request_string( "CMD", "GetUserIdResponse" );

    // base class
    $res .= to_generic_request_BackwardMessage( $obj );

    $res .= "&" . \basic_parser\to_generic_request_int( "USER_ID", $obj->user_id );

    return $res;
}

// session info ********************************************

function to_generic_request_SessionInfo( $prefix, $obj )
{
    $res = "";
    $res .= "&" . \basic_parser\to_generic_request_int( $prefix . ".USER_ID", $obj->user_id );
    $res .= "&" . \basic_parser\to_generic_request_int( $prefix . ".START_TIME", $obj->start_time );
    $res .= "&" . \basic_parser\to_generic_request_int( $prefix . ".EXPIRATION_TIME", $obj->expiration_time );

    return $res;
}

function to_generic_request_GetSessionInfoRequest( & $obj )
{
    // name
    $res = \basic_parser\to_generic_request_string( "CMD", "GetSessionInfoRequest" );

    // base class
    $res .= to_generic_request_ForwardMessage( $obj );

    $res .= "&" . \basic_parser\to_generic_request_string( "SESSION_ID", $obj->session_id );

    return $res;
}

function to_generic_request_GetSessionInfoResponse( & $obj )
{
    // name
    $res = \basic_parser\to_generic_request_string( "CMD", "GetSessionInfoResponse" );

    // base class
    $res .= to_generic_request_BackwardMessage( $obj );

    $res .= "&" . to_generic_request_SessionInfo( "SESSION_INFO", $obj->session_info );

    return $res;
}

// *********************************************************

function to_generic_request( $obj )
{
    $handler_map = array(
        'generic_protocol\ErrorResponse'            => 'to_generic_request_ErrorResponse',
        'generic_protocol\AuthenticateRequest'      => 'to_generic_request_AuthenticateRequest',
        'generic_protocol\AuthenticateAltRequest'   => 'to_generic_request_AuthenticateAltRequest',
        'generic_protocol\AuthenticateResponse'     => 'to_generic_request_AuthenticateResponse',
        'generic_protocol\CloseSessionRequest'      => 'to_generic_request_CloseSessionRequest',
        'generic_protocol\CloseSessionResponse'     => 'to_generic_request_CloseSessionResponse',
        'generic_protocol\GetUserIdRequest'         => 'to_generic_request_GetUserIdRequest',
        'generic_protocol\GetUserIdResponse'        => 'to_generic_request_GetUserIdResponse',
        'generic_protocol\GetSessionInfoRequest'    => 'to_generic_request_GetSessionInfoRequest',
        'generic_protocol\GetSessionInfoResponse'   => 'to_generic_request_GetSessionInfoResponse'
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
