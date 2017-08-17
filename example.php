<?php

// $Revision: 7605 $ $Date:: 2017-08-16 #$ $Author: serge $

require_once 'generic_protocol.php';
require_once 'response_parser.php';
require_once 'str_helper.php';

$login      = 'test';
$user_id    = 175774203;
$password   = 'xxx';
$session_id = "b3ef4ab3-2c1c-4590-8d9c-a764eb068dbf";

$req_auth     = new \generic_protocol\AuthenticateRequest( $session_id, $login, $password );
$req_alt_auth = new \generic_protocol\AuthenticateAltRequest( $user_id, $password );
$req_sess     = new \generic_protocol\CloseSessionRequest( $session_id );
$req_id       = new \generic_protocol\GetUserIdRequest( $session_id, $user_id );

echo "request auth    : " . $req_auth->to_generic_request() . "\n";
echo "request alt auth: " . $req_alt_auth->to_generic_request() . "\n";
echo "request close s : " . $req_sess->to_generic_request() . "\n";
echo "request get id  : " . $req_id->to_generic_request() . "\n";

$resp_unk   = 'UNKNOWN_RESPONSE;xxx;123;';
$resp_err   = 'ERROR;1;authentication failed;';
$resp_close = 'CLOSE_SESSION_RESPONSE;';
$resp_auth  = 'AUTHENTICATE_RESPONSE;b3ef4ab3-2c1c-4590-8d9c-a764ec068dbf;';
$resp_id    = 'GET_USER_ID_RESPONSE;123456789;';

echo "\n";

$parsed_unk   = \generic_protocol\ResponseParser::parse( $resp_unk );
$parsed_err   = \generic_protocol\ResponseParser::parse( $resp_err );
$parsed_close = \generic_protocol\ResponseParser::parse( $resp_close );
$parsed_auth  = \generic_protocol\ResponseParser::parse( $resp_auth );
$parsed_id    = \generic_protocol\ResponseParser::parse( $resp_id );

echo "parsed unknown:\n" . \generic_protocol\to_html( $parsed_unk ) . "\n";
echo "parsed error  :\n" . \generic_protocol\to_html( $parsed_err ) . "\n";
echo "parsed close  :\n" . \generic_protocol\to_html( $parsed_close ) . "\n";
echo "parsed auth   :\n" . \generic_protocol\to_html( $parsed_auth ) . "\n";
echo "parsed id     :\n" . \generic_protocol\to_html( $parsed_id ) . "\n";

{
    $resp  = 'broken;';

    $parsed = \generic_protocol\ResponseParser::parse( $resp );

    echo "parsed :\n" . \generic_protocol\to_html( $parsed ) . "\n";
}


?>
