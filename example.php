<?php

// $Revision: 8517 $ $Date:: 2018-01-16 #$ $Author: serge $

require_once 'generic_protocol.php';
require_once 'response_parser.php';
require_once 'str_helper.php';

$login      = 'test';
$user_id    = 175774203;
$password   = 'xxx';
$session_id = "b3ef4ab3-2c1c-4590-8d9c-a764eb068dbf";

{
    $req = new \generic_protocol\AuthenticateRequest( $session_id, $login, $password );
    
    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $req = new \generic_protocol\AuthenticateAltRequest( $user_id, $password );

    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $req = new \generic_protocol\CloseSessionRequest( $session_id );

    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $req = new \generic_protocol\GetUserIdRequest( $session_id, $user_id );

    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $req = new \generic_protocol\GetSessionInfoRequest( $session_id, "abababab-2e2e-5647-8dc7-6575ab87ac7e" );

    echo "req = " . $req->to_generic_request() . "\n";
}

echo "\n";

{
    $resp  = 'UNKNOWN_RESPONSE;xxx;123;';

    $parsed = \generic_protocol\ResponseParser::parse( $resp );

    echo "parsed :\n" . \generic_protocol\to_html( $parsed ) . "\n";
}

{
    $resp  = 'ERROR;1;authentication failed;';

    $parsed = \generic_protocol\ResponseParser::parse( $resp );

    echo "parsed :\n" . \generic_protocol\to_html( $parsed ) . "\n";
}

{
    $resp  = 'CLOSE_SESSION_RESPONSE;';

    $parsed = \generic_protocol\ResponseParser::parse( $resp );

    echo "parsed :\n" . \generic_protocol\to_html( $parsed ) . "\n";
}

{
    $resp  = 'AUTHENTICATE_RESPONSE;b3ef4ab3-2c1c-4590-8d9c-a764ec068dbf;';

    $parsed = \generic_protocol\ResponseParser::parse( $resp );

    echo "parsed :\n" . \generic_protocol\to_html( $parsed ) . "\n";
}

{
    $resp  = 'GET_USER_ID_RESPONSE;123456789;';

    $parsed = \generic_protocol\ResponseParser::parse( $resp );

    echo "parsed :\n" . \generic_protocol\to_html( $parsed ) . "\n";
}

{
    $resp  = 'broken;';

    $parsed = \generic_protocol\ResponseParser::parse( $resp );

    echo "parsed :\n" . \generic_protocol\to_html( $parsed ) . "\n";
}

{
    $resp  = 'GetSessionInfoResponse;123;1515700200;1515701100;';

    $parsed = \generic_protocol\ResponseParser::parse( $resp );

    echo "parsed :\n" . \generic_protocol\to_html( $parsed ) . "\n";
}

?>
