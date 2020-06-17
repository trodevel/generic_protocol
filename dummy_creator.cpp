// includes
#include "basic_parser/dummy_creator.h"
#include "object_initializer.h"

namespace generic_protocol
{

namespace dummy
{

// enums

ErrorResponse_type_e create__ErrorResponse_type_e()
{
    auto res = ErrorResponse_type_e::AUTHENTICATION_ERROR;

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

