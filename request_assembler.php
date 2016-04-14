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

// $Revision: 3786 $ $Date:: 2016-04-14 #$ $Author: serge $

namespace generic_protocol;

function assemble_request( & $array )
{
    $res = "";

    foreach( $array as $key => $value )
    {
        $res = $res . "$key=$value&";
    }

    return $res;
}


?>
