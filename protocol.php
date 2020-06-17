<?php

namespace generic_protocol;


// includes
require_once __DIR__.'/../basic_parser/object.php';

// includes for used modules

// Enum ErrorResponse_type_e
const ErrorResponse_type_e__AUTHENTICATION_ERROR = 1;
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

    const MESSAGE_ID = 1604294198;

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

    const MESSAGE_ID = 641601580;

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

    const MESSAGE_ID = 3094302290;

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

    const MESSAGE_ID = 1812873298;

    public $session_id          ; // type: string
};

// Message
class CloseSessionRequest extends ForwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3342975108;

    public $session_id          ; // type: string
};

// Message
class CloseSessionResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3034715224;
};

// Message
class GetUserIdRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2375011622;

    public $user_login          ; // type: string
};

// Message
class GetUserIdResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2356156561;

    public $user_id             ; // type: uint32_t
};

// Message
class GetSessionInfoRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2613135952;

    public $id                  ; // type: string
};

// Message
class GetSessionInfoResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 889225759;

    public $session_info        ; // type: SessionInfo
};

# namespace_end generic_protocol


?>

