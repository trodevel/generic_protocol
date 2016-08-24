<?php

// $Revision: 3877 $ $Date:: 2016-05-17 #$ $Author: serge $

require_once 'generic_protocol.php';
require_once 'response_parser.php';

$login      = 'test';
$user_id    = 175774203;
$password   = 'xxx';
$session_id = "b3ef4ab3-2c1c-4590-8d9c-a764eb068dbf";

$req_auth     = new generic_protocol\AuthenticateRequest( $login, $password );
$req_alt_auth = new generic_protocol\AuthenticateAltRequest( $user_id, $password );
$req_sess     = new generic_protocol\CloseSessionRequest( $session_id );

echo "request auth    : " . $req_auth->to_generic_request() . "\n";
echo "request alt auth: " . $req_alt_auth->to_generic_request() . "\n";
echo "request close s : " . $req_sess->to_generic_request() . "\n";

$resp_unk   = 'UNKNOWN_RESPONSE;xxx;123;';
$resp_err   = 'ERROR;1;authentication failed;';
$resp_close = 'CLOSE_SESSION_RESPONSE;';
$resp_auth  = 'AUTHENTICATE_RESPONSE;b3ef4ab3-2c1c-4590-8d9c-a764ec068dbf;';

echo "\n";

$parsed_unk   = generic_protocol\parse_response( $resp_unk );
$parsed_err   = generic_protocol\parse_response( $resp_err );
$parsed_close = generic_protocol\parse_response( $resp_close );
$parsed_auth  = generic_protocol\parse_response( $resp_auth );

echo "parsed unknown:\n" . $parsed_unk->to_html() . "\n";
echo "parsed error  :\n" . $parsed_err->to_html() . "\n";
echo "parsed close  :\n" . $parsed_close->to_html() . "\n";
echo "parsed auth   :\n" . $parsed_auth->to_html() . "\n";

?>
