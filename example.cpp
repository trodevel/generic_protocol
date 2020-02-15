#include <iostream>

#include "protocol.h"
#include "request_parser.h"
#include "response_gen.h"
#include "str_helper.h"
#include "csv_helper.h"     // CsvHelper
#include "../generic_request/request_parser.h"

void test( const std::string & str )
{
    std::cout << "REQ = " << str << " - ";

    try
    {
        generic_request::Request gr = generic_request::RequestParser::to_request( str );

        generic_protocol::ForwardMessage * r = generic_protocol::RequestParser::to_forward_message( gr );

        delete r;

        std::cout << "ok\n";
    }
    catch( std::exception & e )
    {
        std::cout << "FAILED - " << e.what() << "\n";
    }
}

void test_GetSessionInfoResponse()
{
    generic_protocol::SessionInfo si;

    generic_protocol::init( & si, 123, 1515700200, 1515701100 );

    auto s = generic_protocol::create_GetSessionInfoResponse( si );

    std::cout << generic_protocol::csv_helper::to_csv( * s ) << std::endl;

    delete s;
}

int main()
{
    test_GetSessionInfoResponse();

    std::cout << "\n*********************************\n" << std::endl;

    test( "CMD=AUTHENTICATE_REQUEST&USER_LOGIN=xxx&PASSWORD=yyy&SESSION_ID=zzz" );
    test( "CMD=GET_USER_ID&USER_LOGIN=xxx&SESSION_ID=zzz" );
    test( "CMD=GetSessionInfoRequest&ID=xxx&SESSION_ID=zzz" );
    test( "CMD=GetSessionInfoRequest&SESSION_ID=zzz" );

    return 0;
}
