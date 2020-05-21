<?php
// $Revision: 13106 $ $Date:: 2020-05-21 #$ $Author: serge $

namespace generic_protocol;

// base messages *******************************************

abstract class Object
{
}

// forward/backward messages *******************************

abstract class ForwardMessage extends Object
{
}

abstract class BackwardMessage extends Object
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
}

class GetUserIdResponse extends BackwardMessage
{
    public          $user_id;

    function __construct( $user_id )
    {
        $this->user_id = $user_id;
    }
}

// session info **********************************

class SessionInfo
{
    public          $user_id;           // user ID
    public          $start_time;        // session start time
    public          $expiration_time;   // session expiration time
};

class GetSessionInfoRequest extends Request
{
    public          $id;

    function __construct( $session_id, $id )
    {
        parent::__construct( $session_id );

        $this->id   = $id;
    }
};

class GetSessionInfoResponse extends BackwardMessage
{
    public          $session_info;  // type SessionInfo
};

?>
