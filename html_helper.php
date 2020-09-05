<?php

namespace generic_protocol;


// includes
require_once __DIR__.'/../basic_parser/html_helper.php';
require_once 'str_helper.php';

// enums

function to_html_header__ErrorResponse_type_e( $r )
{
    return array( 'ERRORRESPONSE_TYPE_E' );
}

function to_html__ErrorResponse_type_e( $r )
{
    return to_string__ErrorResponse_type_e( $r ) . " (" . $r . ")";
}

// objects

function to_html__SessionInfo( & $r )
{
    $header = array( 'USER_ID', 'START_TIME', 'EXPIRATION_TIME' );

    $data = array(
        \basic_parser\to_html__int( $r->user_id ),
        \basic_parser\to_html__int( $r->start_time ),
        \basic_parser\to_html__int( $r->expiration_time )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

// base messages

function to_html__ForwardMessage( & $r )
{
    $header = array(  );

    $data = array(        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__BackwardMessage( & $r )
{
    $header = array(  );

    $data = array(        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__Request( & $r )
{
    $header = array( 'ForwardMessage', 'SESSION_ID' );

    $data = array(
        to_html__ForwardMessage( $r ),
        \basic_parser\to_html__string( $r->session_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

// messages

function to_html__ErrorResponse( & $r )
{
    $header = array( 'BackwardMessage', 'TYPE', 'DESCR' );

    $data = array(
        to_html__BackwardMessage( $r ),
        to_html__ErrorResponse_type_e( $r->type ),
        \basic_parser\to_html__string( $r->descr )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__AuthenticateRequest( & $r )
{
    $header = array( 'ForwardMessage', 'USER_LOGIN', 'PASSWORD' );

    $data = array(
        to_html__ForwardMessage( $r ),
        \basic_parser\to_html__string( $r->user_login ),
        \basic_parser\to_html__string( $r->password )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__AuthenticateAltRequest( & $r )
{
    $header = array( 'ForwardMessage', 'USER_ID', 'PASSWORD' );

    $data = array(
        to_html__ForwardMessage( $r ),
        \basic_parser\to_html__int( $r->user_id ),
        \basic_parser\to_html__string( $r->password )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__AuthenticateResponse( & $r )
{
    $header = array( 'BackwardMessage', 'SESSION_ID' );

    $data = array(
        to_html__BackwardMessage( $r ),
        \basic_parser\to_html__string( $r->session_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__CloseSessionRequest( & $r )
{
    $header = array( 'ForwardMessage', 'SESSION_ID' );

    $data = array(
        to_html__ForwardMessage( $r ),
        \basic_parser\to_html__string( $r->session_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__CloseSessionResponse( & $r )
{
    $header = array( 'BackwardMessage' );

    $data = array(
        to_html__BackwardMessage( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetUserIdRequest( & $r )
{
    $header = array( 'Request', 'USER_LOGIN' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__string( $r->user_login )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetUserIdResponse( & $r )
{
    $header = array( 'BackwardMessage', 'USER_ID' );

    $data = array(
        to_html__BackwardMessage( $r ),
        \basic_parser\to_html__int( $r->user_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetSessionInfoRequest( & $r )
{
    $header = array( 'Request', 'ID' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__string( $r->id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetSessionInfoResponse( & $r )
{
    $header = array( 'BackwardMessage', 'SESSION_INFO' );

    $data = array(
        to_html__BackwardMessage( $r ),
        to_html__SessionInfo( $r->session_info )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

// generic

function to_html( $obj )
{
    $handler_map = array(
        // objects
        'generic_protocol\SessionInfo'         => 'to_html__SessionInfo',
        // messages
        'generic_protocol\ErrorResponse'         => 'to_html__ErrorResponse',
        'generic_protocol\AuthenticateRequest'         => 'to_html__AuthenticateRequest',
        'generic_protocol\AuthenticateAltRequest'         => 'to_html__AuthenticateAltRequest',
        'generic_protocol\AuthenticateResponse'         => 'to_html__AuthenticateResponse',
        'generic_protocol\CloseSessionRequest'         => 'to_html__CloseSessionRequest',
        'generic_protocol\CloseSessionResponse'         => 'to_html__CloseSessionResponse',
        'generic_protocol\GetUserIdRequest'         => 'to_html__GetUserIdRequest',
        'generic_protocol\GetUserIdResponse'         => 'to_html__GetUserIdResponse',
        'generic_protocol\GetSessionInfoRequest'         => 'to_html__GetSessionInfoRequest',
        'generic_protocol\GetSessionInfoResponse'         => 'to_html__GetSessionInfoResponse',
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
