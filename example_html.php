<?php

namespace generic_protocol;


// own includes
require_once __DIR__.'/../generic_protocol/protocol.php';
require_once __DIR__.'/../generic_protocol/dummy_creator.php';
require_once __DIR__.'/../generic_protocol/html_helper.php';

# objects

function example_SessionInfo()
{
    $obj = \generic_protocol\create_dummy__SessionInfo();

    echo "SessionInfo : HTML : " . \generic_protocol\to_html( $obj ) . "<br>\n";
}


# messages

function example_ErrorResponse()
{
    $obj = \generic_protocol\create_dummy__ErrorResponse();

    echo "ErrorResponse : HTML : " . \generic_protocol\to_html( $obj ) . "<br>\n";
}

function example_AuthenticateRequest()
{
    $obj = \generic_protocol\create_dummy__AuthenticateRequest();

    echo "AuthenticateRequest : HTML : " . \generic_protocol\to_html( $obj ) . "<br>\n";
}

function example_AuthenticateAltRequest()
{
    $obj = \generic_protocol\create_dummy__AuthenticateAltRequest();

    echo "AuthenticateAltRequest : HTML : " . \generic_protocol\to_html( $obj ) . "<br>\n";
}

function example_AuthenticateResponse()
{
    $obj = \generic_protocol\create_dummy__AuthenticateResponse();

    echo "AuthenticateResponse : HTML : " . \generic_protocol\to_html( $obj ) . "<br>\n";
}

function example_CloseSessionRequest()
{
    $obj = \generic_protocol\create_dummy__CloseSessionRequest();

    echo "CloseSessionRequest : HTML : " . \generic_protocol\to_html( $obj ) . "<br>\n";
}

function example_CloseSessionResponse()
{
    $obj = \generic_protocol\create_dummy__CloseSessionResponse();

    echo "CloseSessionResponse : HTML : " . \generic_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetUserIdRequest()
{
    $obj = \generic_protocol\create_dummy__GetUserIdRequest();

    echo "GetUserIdRequest : HTML : " . \generic_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetUserIdResponse()
{
    $obj = \generic_protocol\create_dummy__GetUserIdResponse();

    echo "GetUserIdResponse : HTML : " . \generic_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetSessionInfoRequest()
{
    $obj = \generic_protocol\create_dummy__GetSessionInfoRequest();

    echo "GetSessionInfoRequest : HTML : " . \generic_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetSessionInfoResponse()
{
    $obj = \generic_protocol\create_dummy__GetSessionInfoResponse();

    echo "GetSessionInfoResponse : HTML : " . \generic_protocol\to_html( $obj ) . "<br>\n";
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
