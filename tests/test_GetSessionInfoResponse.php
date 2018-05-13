<?php

// $Revision: 9158 $ $Date:: 2018-05-11 #$ $Author: serge $

require_once '../generic_protocol.php';
require_once '../response_parser.php';
require_once '../str_helper.php';

{
    $resp  = 'GetSessionInfoResponse;123;1515700200;1515701100;';

    $parsed = \generic_protocol\ResponseParser::parse( $resp );

    echo "parsed :\n" . \generic_protocol\to_html( $parsed ) . "\n";
}

?>
