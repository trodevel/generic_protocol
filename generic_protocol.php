<?php
// $Revision: 3763 $ $Date:: 2016-04-12 #$ $Author: serge $

namespace generic_protocol;

require_once 'php_snippets/hexcodec.php';           // str2hex()
require_once 'php_snippets/html_elems.php';         // get_html_table_row_header

// base messages *******************************************

abstract class MessageBase
{
    public function to_html()
    {
        return "not implemented yet";
    }
}

// forward/backward messages *******************************

abstract class ForwardMessage extends MessageBase
{
}

abstract class BackwardMessage extends MessageBase
{
}

// error response ******************************************

class ErrorResponse extends BackwardMessage
{
    const AUTHENTICATION_ERROR    = 1;
    const NOT_PERMITTED           = 2;
    const INVALID_ARGUMENT        = 3;
    const RUNTIME_ERROR           = 4;
    const PARSE_ERROR             = 5;

    public          $type;
    public          $descr;

    function __construct( $type, $descr )
    {
        $this->type    = $type;
        $this->descr   = $descr;
    }

    function to_html()
    {
        return get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
            get_html_table_row_header( array( 'RESULT', 'TYPE', 'DESCRIPTION' ) ) .
            get_html_table_row_data( array( 'ERROR', $this->type_to_string( $this->type ), $this->descr ) ) );
    }

    public static function type_to_string( $value )
    {
        $class = new \ReflectionClass(__CLASS__);
        $constants = array_flip($class->getConstants());

        return $constants[ $value ];
    }
}

// authentication messages *********************************

class AuthenticateRequest extends ForwardMessage
{
    public          $user_login;
    public          $password;

    function __construct( $user_login, $password )
    {
        $this->user_login = $user_login;
        $this->password   = $password;
    }

    public function to_generic_request()
    {
        return "CMD=AUTHENTICATE_REQUEST&USER_LOGIN:X=" . str2hex( $this->user_login ) . "&PASSWORD:X=" . str2hex( $this->password );
    }

    function to_html()
    {
        return get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
            get_html_table_row_header( array( 'REQUEST', 'USER_LOGIN', 'PASSWORD' ) ) .
            get_html_table_row_data( array( 'AUTHENTICATE_REQUEST', str2hex( $this->user_login ), str2hex( $this->password ) ) ) );
    }
}

class AuthenticateAltRequest extends ForwardMessage
{
    public          $user_id;
    public          $password;

    function __construct( $user_id, $password )
    {
        $this->user_id  = $user_id;
        $this->password = $password;
    }

    public function to_generic_request()
    {
        return "CMD=AUTHENTICATE_ALT_REQUEST&USER_ID=" . $this->user_id . "&PASSWORD:X=" . str2hex( $this->password );
    }

    function to_html()
    {
        return get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
            get_html_table_row_header( array( 'REQUEST', 'USER_ID', 'PASSWORD' ) ) .
            get_html_table_row_data( array( 'AUTHENTICATE_ALT_REQUEST', $this->user_id, str2hex( $this->password ) ) ) );
    }
}

class AuthenticateResponse extends BackwardMessage
{
    public          $session_id;

    function __construct( $session_id )
    {
        $this->session_id = $session_id;
    }

    function to_html()
    {
        return get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
            get_html_table_row_header( array( 'RESPONSE', 'SESSION_ID' ) ) .
            get_html_table_row_data( array( 'AUTHENTICATE_RESPONSE', $this->session_id ) ) );
    }
}

// session messages ****************************************

class CloseSessionRequest extends ForwardMessage
{
    public          $session_id;

    function __construct( $session_id )
    {
       $this->session_id = $session_id;
    }

    public function to_generic_request()
    {
        return "CMD=CLOSE_SESSION_REQUEST&SESSION_ID=" . $this->session_id;
    }

    function to_html()
    {
        return get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
            get_html_table_row_header( array( 'REQUEST', 'SESSION_ID' ) ) .
            get_html_table_row_data( array( 'CLOSE_SESSION_REQUEST', $this->session_id ) ) );
    }
}

class CloseSessionResponse extends BackwardMessage
{
    function to_html()
    {
        return get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
            get_html_table_row_header( array( 'RESPONSE' ) ) .
            get_html_table_row_data( array( 'CLOSE_SESSION_RESPONSE' ) ) );
    }
}

// request base ********************************************

abstract class Request extends ForwardMessage
{
    public          $session_id;
}


?>
