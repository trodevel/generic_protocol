<?php

namespace generic_protocol;


// own includes
require_once __DIR__.'/../generic_protocol/protocol.php';
require_once __DIR__.'/../generic_protocol/dummy_creator.php';
require_once __DIR__.'/../generic_protocol/str_helper.php';
require_once __DIR__.'/../generic_protocol/request_encoder.php';

# objects

function example_SessionInfo()
{
    $obj = \generic_protocol\create_dummy__SessionInfo();

    echo "SessionInfo : STR : " . \generic_protocol\to_string( $obj ) . "\n";
}


# messages

function example_ErrorResponse()
{
    $obj = \generic_protocol\create_dummy__ErrorResponse();

    echo "ErrorResponse : STR : " . \generic_protocol\to_string( $obj ) . "\n";

    echo "ErrorResponse : REQ : " . \generic_protocol\to_generic_request( $obj ) . "\n";

}

function example_AuthenticateRequest()
{
    $obj = \generic_protocol\create_dummy__AuthenticateRequest();

    echo "AuthenticateRequest : STR : " . \generic_protocol\to_string( $obj ) . "\n";

    echo "AuthenticateRequest : REQ : " . \generic_protocol\to_generic_request( $obj ) . "\n";

}

function example_AuthenticateAltRequest()
{
    $obj = \generic_protocol\create_dummy__AuthenticateAltRequest();

    echo "AuthenticateAltRequest : STR : " . \generic_protocol\to_string( $obj ) . "\n";

    echo "AuthenticateAltRequest : REQ : " . \generic_protocol\to_generic_request( $obj ) . "\n";

}

function example_AuthenticateResponse()
{
    $obj = \generic_protocol\create_dummy__AuthenticateResponse();

    echo "AuthenticateResponse : STR : " . \generic_protocol\to_string( $obj ) . "\n";

    echo "AuthenticateResponse : REQ : " . \generic_protocol\to_generic_request( $obj ) . "\n";

}

function example_CloseSessionRequest()
{
    $obj = \generic_protocol\create_dummy__CloseSessionRequest();

    echo "CloseSessionRequest : STR : " . \generic_protocol\to_string( $obj ) . "\n";

    echo "CloseSessionRequest : REQ : " . \generic_protocol\to_generic_request( $obj ) . "\n";

}

function example_CloseSessionResponse()
{
    $obj = \generic_protocol\create_dummy__CloseSessionResponse();

    echo "CloseSessionResponse : STR : " . \generic_protocol\to_string( $obj ) . "\n";

    echo "CloseSessionResponse : REQ : " . \generic_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetUserIdRequest()
{
    $obj = \generic_protocol\create_dummy__GetUserIdRequest();

    echo "GetUserIdRequest : STR : " . \generic_protocol\to_string( $obj ) . "\n";

    echo "GetUserIdRequest : REQ : " . \generic_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetUserIdResponse()
{
    $obj = \generic_protocol\create_dummy__GetUserIdResponse();

    echo "GetUserIdResponse : STR : " . \generic_protocol\to_string( $obj ) . "\n";

    echo "GetUserIdResponse : REQ : " . \generic_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetSessionInfoRequest()
{
    $obj = \generic_protocol\create_dummy__GetSessionInfoRequest();

    echo "GetSessionInfoRequest : STR : " . \generic_protocol\to_string( $obj ) . "\n";

    echo "GetSessionInfoRequest : REQ : " . \generic_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetSessionInfoResponse()
{
    $obj = \generic_protocol\create_dummy__GetSessionInfoResponse();

    echo "GetSessionInfoResponse : STR : " . \generic_protocol\to_string( $obj ) . "\n";

    echo "GetSessionInfoResponse : REQ : " . \generic_protocol\to_generic_request( $obj ) . "\n";

}


{
    // objects

    example_SessionInfo();

    // messages

    example_ErrorResponse();
    example_AuthenticateRequest();
    example_AuthenticateAltRequest();
    example_AuthenticateResponse();
    example_CloseSessionRequest();
    example_CloseSessionResponse();
    example_GetUserIdRequest();
    example_GetUserIdResponse();
    example_GetSessionInfoRequest();
    example_GetSessionInfoResponse();

}

// namespace_end generic_protocol


?>
