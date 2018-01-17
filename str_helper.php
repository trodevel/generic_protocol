<?php
// $Revision: 8516 $ $Date:: 2018-01-16 #$ $Author: serge $

namespace generic_protocol;

require_once __DIR__.'/../php_snippets/hexcodec.php';        // str2hex()
require_once __DIR__.'/../php_snippets/html_elems.php';      // get_html_table_row_header
require_once __DIR__.'/../php_snippets/epoch_to_date.php';   // epoch_to_date_time


// error response ******************************************

function to_html_ErrorResponse( & $obj )
{
    return get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
        get_html_table_row_header( array( 'RESULT', 'TYPE', 'DESCRIPTION' ) ) .
        get_html_table_row_data( array( 'ERROR', to_html_ErrorResponse_type_to_string( $obj->type ), $obj->descr ) ) );
}

function to_html_ErrorResponse_type_to_string( $value )
{
    $class = new \ReflectionClass( "\\generic_protocol\\ErrorResponse" );
    $constants = array_flip($class->getConstants());

    return $constants[ $value ];
}

// authentication messages *********************************

function to_html_AuthenticateRequest( & $obj )
{
    return get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
        get_html_table_row_header( array( 'REQUEST', 'USER_LOGIN', 'PASSWORD' ) ) .
        get_html_table_row_data( array( 'AUTHENTICATE_REQUEST', str2hex( $obj->user_login ), str2hex( $obj->password ) ) ) );
}

function to_html_AuthenticateAltRequest( & $obj )
{
    return get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
        get_html_table_row_header( array( 'REQUEST', 'USER_ID', 'PASSWORD' ) ) .
        get_html_table_row_data( array( 'AUTHENTICATE_ALT_REQUEST', $obj->user_id, str2hex( $obj->password ) ) ) );
}

function to_html_AuthenticateResponse( & $obj )
{
    return get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
        get_html_table_row_header( array( 'RESPONSE', 'SESSION_ID' ) ) .
        get_html_table_row_data( array( 'AUTHENTICATE_RESPONSE', $obj->session_id ) ) );
}

// session messages ****************************************

function to_html_CloseSessionRequest( & $obj )
{
    return get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
        get_html_table_row_header( array( 'REQUEST', 'SESSION_ID' ) ) .
        get_html_table_row_data( array( 'CLOSE_SESSION_REQUEST', $obj->session_id ) ) );
}

function to_html_CloseSessionResponse( & $obj )
{
    return get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
        get_html_table_row_header( array( 'RESPONSE' ) ) .
        get_html_table_row_data( array( 'CLOSE_SESSION_RESPONSE' ) ) );
}

// request base ********************************************


// user id handling ****************************************

function to_html_GetUserIdRequest( & $obj )
{
    return get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
            get_html_table_row_header( array( 'REQUEST', 'USER_LOGIN' ) ) .
            get_html_table_row_data( array( 'GET_USER_ID', str2hex( $obj->user_login ) ) ) );
}

function to_html_GetUserIdResponse( & $obj )
{
    return get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
            get_html_table_row_header( array( 'RESPONSE', 'USER_ID' ) ) .
            get_html_table_row_data( array( 'GET_USER_ID_RESPONSE', $obj->user_id ) ) );
}

// session info ********************************************

function get_header_SessionInfo()
{
    return get_html_table_header_elems( array( 'USER_ID', 'START TIME', 'EXP TIME' ) );
}

function to_html_td_SessionInfo( & $obj )
{
    return get_html_table_data_elems( array(
        $obj->user_id,
        epoch_to_date_time( $obj->start_time ) . " ($obj->start_time)" ,
        epoch_to_date_time( $obj->expiration_time ) . " ($obj->expiration_time)" 
    ) );
}

function to_html_GetSessionInfoRequest( & $obj )
{
    return get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
        get_html_table_row_header( array( 'ID' ) ) .
        get_html_table_row_data( array( $obj->id ) ) );
}

function to_html_GetSessionInfoResponse( & $obj )
{
    return get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
        get_html_table_tr( get_header_SessionInfo() ) .
        get_html_table_tr( to_html_td_SessionInfo( $obj->session_info ) ) );
}

// *********************************************************

function to_html( $obj )
{
    $handler_map = array(
        'generic_protocol\ErrorResponse'            => 'to_html_ErrorResponse',
        'generic_protocol\AuthenticateRequest'      => 'to_html_AuthenticateRequest',
        'generic_protocol\AuthenticateAltRequest'   => 'to_html_AuthenticateAltRequest',
        'generic_protocol\AuthenticateResponse'     => 'to_html_AuthenticateResponse',
        'generic_protocol\CloseSessionRequest'      => 'to_html_CloseSessionRequest',
        'generic_protocol\CloseSessionResponse'     => 'to_html_CloseSessionResponse',
        'generic_protocol\GetUserIdRequest'         => 'to_html_GetUserIdRequest',
        'generic_protocol\GetUserIdResponse'        => 'to_html_GetUserIdResponse',
        'generic_protocol\GetSessionInfoRequest'    => 'to_html_GetSessionInfoRequest',
        'generic_protocol\GetSessionInfoResponse'   => 'to_html_GetSessionInfoResponse'
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
