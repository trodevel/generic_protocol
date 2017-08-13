<?php
// $Revision: 7574 $ $Date:: 2017-08-11 #$ $Author: serge $

namespace generic_protocol;

require_once __DIR__.'/../php_snippets/hexcodec.php';        // str2hex()
require_once 'request_assembler.php';               // assemble_request()

// base messages *******************************************

abstract class MessageBase
{
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
        $res = array(
            "CMD"          => "AUTHENTICATE_REQUEST",
            "USER_LOGIN:X" => str2hex( $this->user_login ),
            "PASSWORD:X"   => str2hex( $this->password ) );

        return assemble_request( $res );
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
        $res = array(
            "CMD"          => "AUTHENTICATE_ALT_REQUEST",
            "USER_ID"      => $this->user_id,
            "PASSWORD:X"   => str2hex( $this->password ) );

        return assemble_request( $res );
    }
}

class AuthenticateResponse extends BackwardMessage
{
    public          $session_id;

    function __construct( $session_id )
    {
        $this->session_id = $session_id;
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
        $res = array(
            "CMD"          => "CLOSE_SESSION_REQUEST",
            "SESSION_ID"   => $this->session_id );

        return assemble_request( $res );
    }
}

class CloseSessionResponse extends BackwardMessage
{
}

// request base ********************************************

abstract class Request extends ForwardMessage
{
    public          $session_id;

    function __construct( $session_id )
    {
        $this->session_id = $session_id;
    }

    public function to_generic_request()
    {
        $res = array(
            "SESSION_ID"   => $this->session_id );

        return assemble_request( $res );
    }
}

// user id handling **********************************

class GetUserIdRequest extends Request
{
    public          $user_login;

    function __construct( $session_id, $user_login )
    {
        parent::__construct( $session_id );

        $this->user_login = $user_login;
    }

    public function to_generic_request()
    {
        $res = array(
                "CMD"          => "GET_USER_ID",
                "USER_LOGIN:X" => str2hex( $this->user_login ) );

        return assemble_request( $res ) . parent::to_generic_request();
    }
}

class GetUserIdResponse extends BackwardMessage
{
    public          $user_id;

    function __construct( $user_id )
    {
        $this->user_id = $user_id;
    }
}


?>
