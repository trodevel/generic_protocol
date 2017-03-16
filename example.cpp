#include <iostream>

#include "generic_protocol.h"
#include "request_parser.h"
#include "str_helper.h"
#include "../generic_request/request_parser.h"

void test_1( const std::string & str )
{
    generic_request::Request gr = generic_request::RequestParser::to_request( str );

    auto r = static_cast<generic_protocol::AuthenticateRequest *>( generic_protocol::RequestParser::to_authenticate_request( gr ) );

    delete r;
}

void test_2( const std::string & str )
{
    generic_request::Request gr = generic_request::RequestParser::to_request( str );

    auto * r = generic_protocol::RequestParser::to_get_user_id( gr );

    delete r;
}

int main()
{
    try
    {
        test_1( "CMD=AUTHENTICATE_REQUEST&USER_LOGIN=xxx&PASSWORD=yyy&SESSION_ID=zzz" );

        test_2( "CMD=GET_USER_ID&USER_LOGIN=xxx&SESSION_ID=zzz" );

        std::cout << "OK" << std::endl;
    }
    catch( std::exception & e )
    {
        std::cout << "ERROR: " << e.what() << std::endl;
    }

    return 0;
}
