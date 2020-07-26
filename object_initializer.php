<?php

namespace generic_protocol;


// includes
require_once 'protocol.php';

// objects

function initialize__SessionInfo( & $res
    , $user_id // uint32_t
    , $start_time // uint32_t
    , $expiration_time // uint32_t
 )
{
    $res->user_id = $user_id;
    $res->start_time = $start_time;
    $res->expiration_time = $expiration_time;
}

// base messages

function initialize__ForwardMessage( & $res
 )
{
    // no base class
}

function initialize__BackwardMessage( & $res
 )
{
    // no base class
}

function initialize__Request( & $res
    , $session_id // string
 )
{
    // base class
    initialize__ForwardMessage( $res );

    $res->session_id = $session_id;
}

// messages

function initialize__ErrorResponse( & $res
    , $type // ErrorResponse_type_e
    , $descr // string
 )
{
    // base class
    initialize__BackwardMessage( $res );

    $res->type = $type;
    $res->descr = $descr;
}

function initialize__AuthenticateRequest( & $res
    , $user_login // string
    , $password // string
 )
{
    // base class
    initialize__ForwardMessage( $res );

    $res->user_login = $user_login;
    $res->password = $password;
}

function initialize__AuthenticateAltRequest( & $res
    , $user_id // uint32_t
    , $password // string
 )
{
    // base class
    initialize__ForwardMessage( $res );

    $res->user_id = $user_id;
    $res->password = $password;
}

function initialize__AuthenticateResponse( & $res
    , $session_id // string
 )
{
    // base class
    initialize__BackwardMessage( $res );

    $res->session_id = $session_id;
}

function initialize__CloseSessionRequest( & $res
    , $session_id // string
 )
{
    // base class
    initialize__ForwardMessage( $res );

    $res->session_id = $session_id;
}

function initialize__CloseSessionResponse( & $res
 )
{
    // base class
    initialize__BackwardMessage( $res );

}

function initialize__GetUserIdRequest( & $res
    , $base_class_param_1 // string
    , $user_login // string
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->user_login = $user_login;
}

function initialize__GetUserIdResponse( & $res
    , $user_id // uint32_t
 )
{
    // base class
    initialize__BackwardMessage( $res );

    $res->user_id = $user_id;
}

function initialize__GetSessionInfoRequest( & $res
    , $base_class_param_1 // string
    , $id // string
 )
{
    // base class
    initialize__Request( $res, $base_class_param_1 );

    $res->id = $id;
}

function initialize__GetSessionInfoResponse( & $res
    , $session_info // SessionInfo
 )
{
    // base class
    initialize__BackwardMessage( $res );

    $res->session_info = $session_info;
}

// objects (constructors)

function create__SessionInfo(
    $user_id // uint32_t
    , $start_time // uint32_t
    , $expiration_time // uint32_t
 )
{
    $res = new SessionInfo;

    initialize__SessionInfo( $res, $user_id, $start_time, $expiration_time );

    return $res;
}

// messages (constructors)

function create__ErrorResponse(
    $type // ErrorResponse_type_e
    , $descr // string
 )
{
    $res = new ErrorResponse;

    initialize__ErrorResponse( $res, $type, $descr );

    return $res;
}

function create__AuthenticateRequest(
    $user_login // string
    , $password // string
 )
{
    $res = new AuthenticateRequest;

    initialize__AuthenticateRequest( $res, $user_login, $password );

    return $res;
}

function create__AuthenticateAltRequest(
    $user_id // uint32_t
    , $password // string
 )
{
    $res = new AuthenticateAltRequest;

    initialize__AuthenticateAltRequest( $res, $user_id, $password );

    return $res;
}

function create__AuthenticateResponse(
    $session_id // string
 )
{
    $res = new AuthenticateResponse;

    initialize__AuthenticateResponse( $res, $session_id );

    return $res;
}

function create__CloseSessionRequest(
    $session_id // string
 )
{
    $res = new CloseSessionRequest;

    initialize__CloseSessionRequest( $res, $session_id );

    return $res;
}

function create__CloseSessionResponse(
 )
{
    $res = new CloseSessionResponse;

    initialize__CloseSessionResponse( $res );

    return $res;
}

function create__GetUserIdRequest(
    $base_class_param_1 // string
    , $user_login // string
 )
{
    $res = new GetUserIdRequest;

    initialize__GetUserIdRequest( $res, $base_class_param_1, $user_login );

    return $res;
}

function create__GetUserIdResponse(
    $user_id // uint32_t
 )
{
    $res = new GetUserIdResponse;

    initialize__GetUserIdResponse( $res, $user_id );

    return $res;
}

function create__GetSessionInfoRequest(
    $base_class_param_1 // string
    , $id // string
 )
{
    $res = new GetSessionInfoRequest;

    initialize__GetSessionInfoRequest( $res, $base_class_param_1, $id );

    return $res;
}

function create__GetSessionInfoResponse(
    $session_info // SessionInfo
 )
{
    $res = new GetSessionInfoResponse;

    initialize__GetSessionInfoResponse( $res, $session_info );

    return $res;
}

# namespace_end generic_protocol


?>
