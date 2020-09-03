// includes
#include "dummy_creator.h"
#include "basic_parser/dummy_creator.h"
#include "object_initializer.h"

namespace generic_protocol
{

namespace dummy
{

// enums

ErrorResponse_type_e create__ErrorResponse_type_e()
{
    static const unsigned SIZE = 4;

    static const ErrorResponse_type_e values[SIZE] = { ErrorResponse_type_e::INVALID_OR_EXPIRED_SESSION, ErrorResponse_type_e::NOT_PERMITTED, ErrorResponse_type_e::INVALID_ARGUMENT, ErrorResponse_type_e::RUNTIME_ERROR,  };

    auto res = values[ ::basic_parser::dummy::create__uint32() % SIZE ];

    return res;
}

// objects

SessionInfo create__SessionInfo()
{
    SessionInfo res;

    ::generic_protocol::initialize( & res
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

// messages

ErrorResponse * create__ErrorResponse()
{
    auto res = new ErrorResponse;

    ::generic_protocol::initialize( res
        , dummy::create__ErrorResponse_type_e()
        , ::basic_parser::dummy::create__string()
        );

    return res;
}

AuthenticateRequest * create__AuthenticateRequest()
{
    auto res = new AuthenticateRequest;

    ::generic_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        );

    return res;
}

AuthenticateAltRequest * create__AuthenticateAltRequest()
{
    auto res = new AuthenticateAltRequest;

    ::generic_protocol::initialize( res
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__string()
        );

    return res;
}

AuthenticateResponse * create__AuthenticateResponse()
{
    auto res = new AuthenticateResponse;

    ::generic_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        );

    return res;
}

CloseSessionRequest * create__CloseSessionRequest()
{
    auto res = new CloseSessionRequest;

    ::generic_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        );

    return res;
}

CloseSessionResponse * create__CloseSessionResponse()
{
    auto res = new CloseSessionResponse;

    ::generic_protocol::initialize( res
        );

    return res;
}

GetUserIdRequest * create__GetUserIdRequest()
{
    auto res = new GetUserIdRequest;

    ::generic_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        );

    return res;
}

GetUserIdResponse * create__GetUserIdResponse()
{
    auto res = new GetUserIdResponse;

    ::generic_protocol::initialize( res
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

GetSessionInfoRequest * create__GetSessionInfoRequest()
{
    auto res = new GetSessionInfoRequest;

    ::generic_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        );

    return res;
}

GetSessionInfoResponse * create__GetSessionInfoResponse()
{
    auto res = new GetSessionInfoResponse;

    ::generic_protocol::initialize( res
        , dummy::create__SessionInfo()
        );

    return res;
}

} // namespace dummy

} // namespace generic_protocol

