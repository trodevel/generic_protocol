#include <iostream>

#include "generic_protocol.h"
#include "request_parser.h"
#include "str_helper.h"
#include "../generic_request/request_parser.h"

int main()
{
    {
        std::string str = "CMD=AUTHENTICATE_REQUEST&USER_LOGIN=xxx&USER_PASSWORD=yyy";

        generic_request::Request gr = generic_request::RequestParser::to_request( str );

        generic_protocol::AuthenticateRequest * r = generic_protocol::RequestParser::to_authenticate_request( gr );

        delete r;
    }

    return 0;
}
