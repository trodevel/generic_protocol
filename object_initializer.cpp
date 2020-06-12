// includes
#include "object_initializer.h"

namespace generic_protocol
{

// objects

void initialize( SessionInfo * res
    , uint32_t user_id
    , uint32_t start_time
    , uint32_t expiration_time
 )
{
    res->user_id = user_id;
    res->start_time = start_time;
    res->expiration_time = expiration_time;
}

// base messages

void initialize( ForwardMessage * res
 )
{
    // no base class
}

void initialize( BackwardMessage * res
 )
{
    // no base class
}

void initialize( Request * res
    , const std::string &  session_id
 )
{
    // base class
    initialize( static_cast<ForwardMessage*>( res ) );

    res->session_id = session_id;
}

// messages

void initialize( ErrorResponse * res
    , ErrorResponse_type_e type
    , const std::string &  descr
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

    res->type = type;
    res->descr = descr;
}

void initialize( AuthenticateRequest * res
    , const std::string &  user_login
    , const std::string &  password
 )
{
    // base class
    initialize( static_cast<ForwardMessage*>( res ) );

    res->user_login = user_login;
    res->password = password;
}

void initialize( AuthenticateAltRequest * res
    , uint32_t user_id
    , const std::string &  password
 )
{
    // base class
    initialize( static_cast<ForwardMessage*>( res ) );

    res->user_id = user_id;
    res->password = password;
}

void initialize( AuthenticateResponse * res
    , const std::string &  session_id
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

    res->session_id = session_id;
}

void initialize( CloseSessionRequest * res
    , const std::string &  session_id
 )
{
    // base class
    initialize( static_cast<ForwardMessage*>( res ) );

    res->session_id = session_id;
}

void initialize( CloseSessionResponse * res
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

}

void initialize( GetUserIdRequest * res
    , const std::string &  base_class_param_1
    , const std::string &  user_login
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->user_login = user_login;
}

void initialize( GetUserIdResponse * res
    , uint32_t user_id
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

    res->user_id = user_id;
}

void initialize( GetSessionInfoRequest * res
    , const std::string &  base_class_param_1
    , const std::string &  id
 )
{
    // base class
    initialize( static_cast<Request*>( res ), base_class_param_1 );

    res->id = id;
}

void initialize( GetSessionInfoResponse * res
    , const SessionInfo &  session_info
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

    res->session_info = session_info;
}

// messages (constructors)

ErrorResponse * create_ErrorResponse(
    ErrorResponse_type_e type
    , const std::string &  descr
 )
{
    auto * res = new ErrorResponse;

    initialize( res, type, descr );

    return res;
}

AuthenticateRequest * create_AuthenticateRequest(
    const std::string &  user_login
    , const std::string &  password
 )
{
    auto * res = new AuthenticateRequest;

    initialize( res, user_login, password );

    return res;
}

AuthenticateAltRequest * create_AuthenticateAltRequest(
    uint32_t user_id
    , const std::string &  password
 )
{
    auto * res = new AuthenticateAltRequest;

    initialize( res, user_id, password );

    return res;
}

AuthenticateResponse * create_AuthenticateResponse(
    const std::string &  session_id
 )
{
    auto * res = new AuthenticateResponse;

    initialize( res, session_id );

    return res;
}

CloseSessionRequest * create_CloseSessionRequest(
    const std::string &  session_id
 )
{
    auto * res = new CloseSessionRequest;

    initialize( res, session_id );

    return res;
}

CloseSessionResponse * create_CloseSessionResponse(
 )
{
    auto * res = new CloseSessionResponse;

    initialize( res );

    return res;
}

GetUserIdRequest * create_GetUserIdRequest(
    const std::string &  base_class_param_1
    , const std::string &  user_login
 )
{
    auto * res = new GetUserIdRequest;

    initialize( res, base_class_param_1, user_login );

    return res;
}

GetUserIdResponse * create_GetUserIdResponse(
    uint32_t user_id
 )
{
    auto * res = new GetUserIdResponse;

    initialize( res, user_id );

    return res;
}

GetSessionInfoRequest * create_GetSessionInfoRequest(
    const std::string &  base_class_param_1
    , const std::string &  id
 )
{
    auto * res = new GetSessionInfoRequest;

    initialize( res, base_class_param_1, id );

    return res;
}

GetSessionInfoResponse * create_GetSessionInfoResponse(
    const SessionInfo &  session_info
 )
{
    auto * res = new GetSessionInfoResponse;

    initialize( res, session_info );

    return res;
}

} // namespace generic_protocol

