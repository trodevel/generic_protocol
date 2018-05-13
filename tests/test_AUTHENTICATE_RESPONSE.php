<?php

// $Revision: 9158 $ $Date:: 2018-05-11 #$ $Author: serge $

require_once '../generic_protocol.php';
require_once '../response_parser.php';
require_once '../str_helper.php';

{
    $resp  = 'AUTHENTICATE_RESPONSE;b3ef4ab3-2c1c-4590-8d9c-a764ec068dbf;';

    $parsed = \generic_protocol\ResponseParser::parse( $resp );

    echo "parsed :\n" . \generic_protocol\to_html( $parsed ) . "\n";
}

?>
