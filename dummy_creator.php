<?php

namespace generic_protocol;


// includes
require_once __DIR__.'/../basic_parser/dummy_creator.php';
require_once 'object_initializer.php';

// enums

function create_dummy__ErrorResponse_type_e()
{
    $res = 0;

    return $res;
}

// objects

function create_dummy__SessionInfo()
{
    $res = new SessionInfo;

    initialize__SessionInfo( $res
        , \basic_parser\create_dummy__int()
        , \basic_parser\create_dummy__int()
        , \basic_parser\create_dummy__int()
        );
    return $res;
}

// messages

function create_dummy__ErrorResponse()
{
    $res = new ErrorResponse;

    initialize__ErrorResponse( $res
        , create_dummy__ErrorResponse_type_e()
        , \basic_parser\create_dummy__string()
        );
    return $res;
}

function create_dummy__AuthenticateRequest()
{
    $res = new AuthenticateRequest;

    initialize__AuthenticateRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        );
    return $res;
}

function create_dummy__AuthenticateAltRequest()
{
    $res = new AuthenticateAltRequest;

    initialize__AuthenticateAltRequest( $res
        , \basic_parser\create_dummy__int()
        , \basic_parser\create_dummy__string()
        );
    return $res;
}

function create_dummy__AuthenticateResponse()
{
    $res = new AuthenticateResponse;

    initialize__AuthenticateResponse( $res
        , \basic_parser\create_dummy__string()
        );
    return $res;
}

function create_dummy__CloseSessionRequest()
{
    $res = new CloseSessionRequest;

    initialize__CloseSessionRequest( $res
        , \basic_parser\create_dummy__string()
        );
    return $res;
}

function create_dummy__CloseSessionResponse()
{
    $res = new CloseSessionResponse;

    initialize__CloseSessionResponse( $res
        );
    return $res;
}

function create_dummy__GetUserIdRequest()
{
    $res = new GetUserIdRequest;

    initialize__GetUserIdRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        );
    return $res;
}

function create_dummy__GetUserIdResponse()
{
    $res = new GetUserIdResponse;

    initialize__GetUserIdResponse( $res
        , \basic_parser\create_dummy__int()
        );
    return $res;
}

function create_dummy__GetSessionInfoRequest()
{
    $res = new GetSessionInfoRequest;

    initialize__GetSessionInfoRequest( $res
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        );
    return $res;
}

function create_dummy__GetSessionInfoResponse()
{
    $res = new GetSessionInfoResponse;

    initialize__GetSessionInfoResponse( $res
        , create_dummy__SessionInfo()
        );
    return $res;
}

# namespace_end generic_protocol


?>
