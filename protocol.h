#ifndef APG_GENERIC__PROTOCOL_H
#define APG_GENERIC__PROTOCOL_H

// system includes
#include <vector>
#include <map>

// includes
#include "basic_parser/object.h"

// includes for used modules

namespace generic_protocol
{

// Enum
enum class ErrorResponse_type_e
{
    INVALID_OR_EXPIRED_SESSION = 1,
    NOT_PERMITTED        = 2,
    INVALID_ARGUMENT     = 3,
    RUNTIME_ERROR        = 4,
};

// Object
struct SessionInfo
{
    uint32_t             user_id   ;
    uint32_t             start_time;
    uint32_t             expiration_time;
};

// Base message
struct ForwardMessage: public basic_parser::Object
{
};

// Base message
struct BackwardMessage: public basic_parser::Object
{
};

// Base message
struct Request: public ForwardMessage
{
    std::string          session_id;
};

// Message
struct ErrorResponse: public BackwardMessage
{
    enum
    {
        message_id = 1604294198
    };

    ErrorResponse_type_e type      ;
    std::string          descr     ;
};

// Message
struct AuthenticateRequest: public ForwardMessage
{
    enum
    {
        message_id = 641601580
    };

    std::string          user_login;
    std::string          password  ;
};

// Message
struct AuthenticateAltRequest: public ForwardMessage
{
    enum
    {
        message_id = 3094302290
    };

    uint32_t             user_id   ;
    std::string          password  ;
};

// Message
struct AuthenticateResponse: public BackwardMessage
{
    enum
    {
        message_id = 1812873298
    };

    std::string          session_id;
};

// Message
struct CloseSessionRequest: public ForwardMessage
{
    enum
    {
        message_id = 3342975108
    };

    std::string          session_id;
};

// Message
struct CloseSessionResponse: public BackwardMessage
{
    enum
    {
        message_id = 3034715224
    };
};

// Message
struct GetUserIdRequest: public Request
{
    enum
    {
        message_id = 2375011622
    };

    std::string          user_login;
};

// Message
struct GetUserIdResponse: public BackwardMessage
{
    enum
    {
        message_id = 2356156561
    };

    uint32_t             user_id   ;
};

// Message
struct GetSessionInfoRequest: public Request
{
    enum
    {
        message_id = 2613135952
    };

    std::string          id        ;
};

// Message
struct GetSessionInfoResponse: public BackwardMessage
{
    enum
    {
        message_id = 889225759
    };

    SessionInfo          session_info;
};

} // namespace generic_protocol

#endif // APG_GENERIC__PROTOCOL_H

