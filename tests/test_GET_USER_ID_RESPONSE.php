<?php

// $Revision: 9158 $ $Date:: 2018-05-11 #$ $Author: serge $

require_once '../generic_protocol.php';
require_once '../response_parser.php';
require_once '../str_helper.php';

{
    $resp  = 'GET_USER_ID_RESPONSE;123456789;';

    $parsed = \generic_protocol\ResponseParser::parse( $resp );

    echo "parsed :\n" . \generic_protocol\to_html( $parsed ) . "\n";
}

?>
