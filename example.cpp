#include "protocol.h"
#include "str_helper.h"
#include "csv_helper.h"
#include "dummy_creator.h"
#include "validator.h"

#include <iostream>       // std::cout

template <class T>
void validate( const T & o, const std::string & name )
{
    try
    {
        generic_protocol::validator::validate( o );
        std::cout << name << " : valid" << std::endl;
    }
    catch( std::exception & e )
    {
        std::cout << name << " : invalid : " << e.what() << std::endl;
    }
}

// enums

void example_ErrorResponse_type_e()
{
    auto obj = generic_protocol::dummy::create__ErrorResponse_type_e();

    std::cout << "ErrorResponse_type_e : STR : " << generic_protocol::str_helper::to_string( obj ) << std::endl;
}


// objects

void example_SessionInfo()
{
    auto obj = generic_protocol::dummy::create__SessionInfo();

    std::cout << "SessionInfo : STR : " << generic_protocol::str_helper::to_string( obj ) << std::endl;
}


// messages

void example_ErrorResponse()
{
    auto & obj = * generic_protocol::dummy::create__ErrorResponse();

    std::cout << "ErrorResponse : STR : " << generic_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "ErrorResponse : CSV : " << generic_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "ErrorResponse" );

    delete & obj;
}

void example_AuthenticateRequest()
{
    auto & obj = * generic_protocol::dummy::create__AuthenticateRequest();

    std::cout << "AuthenticateRequest : STR : " << generic_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "AuthenticateRequest : CSV : " << generic_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "AuthenticateRequest" );

    delete & obj;
}

void example_AuthenticateAltRequest()
{
    auto & obj = * generic_protocol::dummy::create__AuthenticateAltRequest();

    std::cout << "AuthenticateAltRequest : STR : " << generic_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "AuthenticateAltRequest : CSV : " << generic_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "AuthenticateAltRequest" );

    delete & obj;
}

void example_AuthenticateResponse()
{
    auto & obj = * generic_protocol::dummy::create__AuthenticateResponse();

    std::cout << "AuthenticateResponse : STR : " << generic_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "AuthenticateResponse : CSV : " << generic_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "AuthenticateResponse" );

    delete & obj;
}

void example_CloseSessionRequest()
{
    auto & obj = * generic_protocol::dummy::create__CloseSessionRequest();

    std::cout << "CloseSessionRequest : STR : " << generic_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "CloseSessionRequest : CSV : " << generic_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "CloseSessionRequest" );

    delete & obj;
}

void example_CloseSessionResponse()
{
    auto & obj = * generic_protocol::dummy::create__CloseSessionResponse();

    std::cout << "CloseSessionResponse : STR : " << generic_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "CloseSessionResponse : CSV : " << generic_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "CloseSessionResponse" );

    delete & obj;
}

void example_GetUserIdRequest()
{
    auto & obj = * generic_protocol::dummy::create__GetUserIdRequest();

    std::cout << "GetUserIdRequest : STR : " << generic_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetUserIdRequest : CSV : " << generic_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetUserIdRequest" );

    delete & obj;
}

void example_GetUserIdResponse()
{
    auto & obj = * generic_protocol::dummy::create__GetUserIdResponse();

    std::cout << "GetUserIdResponse : STR : " << generic_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetUserIdResponse : CSV : " << generic_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetUserIdResponse" );

    delete & obj;
}

void example_GetSessionInfoRequest()
{
    auto & obj = * generic_protocol::dummy::create__GetSessionInfoRequest();

    std::cout << "GetSessionInfoRequest : STR : " << generic_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetSessionInfoRequest : CSV : " << generic_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetSessionInfoRequest" );

    delete & obj;
}

void example_GetSessionInfoResponse()
{
    auto & obj = * generic_protocol::dummy::create__GetSessionInfoResponse();

    std::cout << "GetSessionInfoResponse : STR : " << generic_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetSessionInfoResponse : CSV : " << generic_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetSessionInfoResponse" );

    delete & obj;
}


int main( int argc, char ** argv )
{
    if( argc > 1 )
    {
        std::srand( std::stoi( std::string( argv[1] ) ) );
    }

    // enums

    example_ErrorResponse_type_e();

    // objects

    example_SessionInfo();

    // messages

    example_ErrorResponse();
    example_AuthenticateRequest();
    example_AuthenticateAltRequest();
    example_AuthenticateResponse();
    example_CloseSessionRequest();
    example_CloseSessionResponse();
    example_GetUserIdRequest();
    example_GetUserIdResponse();
    example_GetSessionInfoRequest();
    example_GetSessionInfoResponse();

    return 0;
}

