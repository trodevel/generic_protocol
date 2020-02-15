<?php

/*
Generic Request Assembler.

Copyright (C) 2016 Sergey Kolevatov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

// $Revision: 12435 $ $Date:: 2019-12-07 #$ $Author: serge $

namespace generic_protocol;

require_once __DIR__.'/../php_snippets/hexcodec.php';        // str2hex()

function assemble_request( & $array )
{
    $res = "";

    foreach( $array as $key => $value )
    {
        $res = $res . "$key=$value&";
    }

    return $res;
}

function assemble_request_enc( & $array )
{
    $res = "";

    foreach( $array as $key => $value )
    {
        $res = $res . "$key:X=" . \str2hex( $value ) . "&";
    }

    return $res;
}


?>
