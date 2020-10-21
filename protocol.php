<?php

namespace generic_protocol;


// includes
require_once __DIR__.'/../basic_parser/object.php';

// includes for used modules

// Enum ErrorResponse_type_e
const ErrorResponse_type_e__INVALID_OR_EXPIRED_SESSION = 1;
const ErrorResponse_type_e__NOT_PERMITTED        = 2;
const ErrorResponse_type_e__INVALID_ARGUMENT     = 3;
const ErrorResponse_type_e__RUNTIME_ERROR        = 4;

// Object
class SessionInfo
{
    public $user_id             ; // type: uint32_t
    public $start_time          ; // type: uint32_t
    public $expiration_time     ; // type: uint32_t
};

// Base message
class ForwardMessage extends \basic_parser\Object
{
    function __construct()
    {
    }
};

// Base message
class BackwardMessage extends \basic_parser\Object
{
    function __construct()
    {
    }
};

// Base message
class Request extends ForwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    public $session_id          ; // type: string
};

// Message
class ErrorResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2436397031;

    public $type                ; // type: ErrorResponse_type_e
    public $descr               ; // type: string
};

// Message
class AuthenticateRequest extends ForwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2707794751;

    public $user_login          ; // type: string
    public $password            ; // type: string
};

// Message
class AuthenticateAltRequest extends ForwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 1569172723;

    public $user_id             ; // type: uint32_t
    public $password            ; // type: string
};

// Message
class AuthenticateResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3895941687;

    public $session_id          ; // type: string
};

// Message
class CloseSessionRequest extends ForwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 1075477399;

    public $session_id          ; // type: string
};

// Message
class CloseSessionResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 819662397;
};

// Message
class GetUserIdRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 236152329;

    public $user_login          ; // type: string
};

// Message
class GetUserIdResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 656587107;

    public $user_id             ; // type: uint32_t
};

// Message
class GetSessionInfoRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2795366045;

    public $id                  ; // type: string
};

// Message
class GetSessionInfoResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3504890046;

    public $session_info        ; // type: SessionInfo
};

// namespace_end generic_protocol


?>

