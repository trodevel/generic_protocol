<?php

// $Revision: 13173 $ $Date:: 2020-05-30 #$ $Author: serge $

require_once 'protocol.php';
require_once 'response_parser.php';
require_once 'str_helper.php';
require_once 'request_encoder.php';

$login      = 'test';
$user_id    = 175774203;
$password   = 'xxx';
$session_id = "b3ef4ab3-2c1c-4590-8d9c-a764eb068dbf";

{
    $req = new \generic_protocol\AuthenticateRequest( $session_id, $login, $password );

    echo "req = " . \generic_protocol\to_generic_request( $req ) . "\n";
}

{
    $req = new \generic_protocol\AuthenticateAltRequest( $user_id, $password );

    echo "req = " . \generic_protocol\to_generic_request( $req ) . "\n";
}

{
    $req = new \generic_protocol\CloseSessionRequest( $session_id );

    echo "req = " . \generic_protocol\to_generic_request( $req ) . "\n";
}

{
    $req = new \generic_protocol\GetUserIdRequest( $session_id, $user_id );

    echo "req = " . \generic_protocol\to_generic_request( $req ) . "\n";
}

{
    $req = new \generic_protocol\GetSessionInfoRequest( $session_id, "abababab-2e2e-5647-8dc7-6575ab87ac7e" );

    echo "req = " . \generic_protocol\to_generic_request( $req ) . "\n";
}

?>
