// system includes
#include <map>
#include <memory>

// includes
#include "parser.h"
#include "basic_parser/parser.h"
#include "basic_parser/malformed_request.h"
#include "validator.h"
#include "request_type_parser.h"

namespace generic_protocol
{

namespace parser
{

using ::basic_parser::parser::get_value_or_throw;
using ::basic_parser::parser::get_value_or_throw_t;

// enums

void get_value_or_throw( ErrorResponse_type_e * res, const std::string & key, const generic_request::Request & r )
{
    uint32_t res_i;

    get_value_or_throw( & res_i, key, r );

    * res = static_cast<ErrorResponse_type_e>( res_i );
}

// objects

void get_value_or_throw( SessionInfo * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->user_id, prefix + ".USER_ID", r );
    get_value_or_throw( & res->start_time, prefix + ".START_TIME", r );
    get_value_or_throw( & res->expiration_time, prefix + ".EXPIRATION_TIME", r );
}

// base messages

void get_value_or_throw( ForwardMessage * res, const generic_request::Request & r )
{
}

void get_value_or_throw( BackwardMessage * res, const generic_request::Request & r )
{
}

void get_value_or_throw( Request * res, const generic_request::Request & r )
{
    get_value_or_throw( & res->session_id, "SESSION_ID", r );
}

// messages

void get_value_or_throw( ErrorResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

    get_value_or_throw( & res->type, "TYPE", r );
    get_value_or_throw( & res->descr, "DESCR", r );
}

void get_value_or_throw( AuthenticateRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<ForwardMessage*>( res ), r );

    get_value_or_throw( & res->user_login, "USER_LOGIN", r );
    get_value_or_throw( & res->password, "PASSWORD", r );
}

void get_value_or_throw( AuthenticateAltRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<ForwardMessage*>( res ), r );

    get_value_or_throw( & res->user_id, "USER_ID", r );
    get_value_or_throw( & res->password, "PASSWORD", r );
}

void get_value_or_throw( AuthenticateResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

    get_value_or_throw( & res->session_id, "SESSION_ID", r );
}

void get_value_or_throw( CloseSessionRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<ForwardMessage*>( res ), r );

    get_value_or_throw( & res->session_id, "SESSION_ID", r );
}

void get_value_or_throw( CloseSessionResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

}

void get_value_or_throw( GetUserIdRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->user_login, "USER_LOGIN", r );
}

void get_value_or_throw( GetUserIdResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

    get_value_or_throw( & res->user_id, "USER_ID", r );
}

void get_value_or_throw( GetSessionInfoRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->id, "ID", r );
}

void get_value_or_throw( GetSessionInfoResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

    get_value_or_throw( & res->session_info, "SESSION_INFO", r );
}

// to object

Object * to_ErrorResponse( const generic_request::Request & r )
{
    std::unique_ptr<ErrorResponse> res( new ErrorResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_AuthenticateRequest( const generic_request::Request & r )
{
    std::unique_ptr<AuthenticateRequest> res( new AuthenticateRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_AuthenticateAltRequest( const generic_request::Request & r )
{
    std::unique_ptr<AuthenticateAltRequest> res( new AuthenticateAltRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_AuthenticateResponse( const generic_request::Request & r )
{
    std::unique_ptr<AuthenticateResponse> res( new AuthenticateResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_CloseSessionRequest( const generic_request::Request & r )
{
    std::unique_ptr<CloseSessionRequest> res( new CloseSessionRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_CloseSessionResponse( const generic_request::Request & r )
{
    std::unique_ptr<CloseSessionResponse> res( new CloseSessionResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetUserIdRequest( const generic_request::Request & r )
{
    std::unique_ptr<GetUserIdRequest> res( new GetUserIdRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetUserIdResponse( const generic_request::Request & r )
{
    std::unique_ptr<GetUserIdResponse> res( new GetUserIdResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetSessionInfoRequest( const generic_request::Request & r )
{
    std::unique_ptr<GetSessionInfoRequest> res( new GetSessionInfoRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetSessionInfoResponse( const generic_request::Request & r )
{
    std::unique_ptr<GetSessionInfoResponse> res( new GetSessionInfoResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

// to forward message

basic_parser::Object* to_forward_message( const generic_request::Request & r )
{
    auto type = detect_request_type( r );

    typedef request_type_e KeyType;

    typedef Object* (*PPMF)( const generic_request::Request & r );

#define HANDLER_MAP_ENTRY(_v)       { KeyType::_v,    & to_##_v }

    static const std::map<KeyType, PPMF> funcs =
    {
        HANDLER_MAP_ENTRY( ErrorResponse ),
        HANDLER_MAP_ENTRY( AuthenticateRequest ),
        HANDLER_MAP_ENTRY( AuthenticateAltRequest ),
        HANDLER_MAP_ENTRY( AuthenticateResponse ),
        HANDLER_MAP_ENTRY( CloseSessionRequest ),
        HANDLER_MAP_ENTRY( CloseSessionResponse ),
        HANDLER_MAP_ENTRY( GetUserIdRequest ),
        HANDLER_MAP_ENTRY( GetUserIdResponse ),
        HANDLER_MAP_ENTRY( GetSessionInfoRequest ),
        HANDLER_MAP_ENTRY( GetSessionInfoResponse ),
    };

#undef HANDLER_MAP_ENTRY

    auto it = funcs.find( type );

    if( it != funcs.end() )
        return it->second( r );

    return nullptr;
}

using basic_parser::MalformedRequest;

request_type_e  detect_request_type( const generic_request::Request & r )
{
    std::string cmd;

    if( r.get_value( "CMD", cmd ) == false )
        throw MalformedRequest( "CMD is not defined" );

    return RequestTypeParser::to_request_type( cmd );
}

} // namespace parser

} // namespace generic_protocol

