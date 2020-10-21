#ifndef APG_GENERIC_PROTOCOL__OBJECT_INITIALIZER_H
#define APG_GENERIC_PROTOCOL__OBJECT_INITIALIZER_H

// includes
#include "protocol.h"

namespace generic_protocol
{

// objects

void initialize( SessionInfo * res
    , uint32_t user_id
    , uint32_t start_time
    , uint32_t expiration_time
 );

// base messages

void initialize( ForwardMessage * res
 );
void initialize( BackwardMessage * res
 );
void initialize( Request * res
    , const std::string &  session_id
 );

// messages

void initialize( ErrorResponse * res
    , ErrorResponse_type_e type
    , const std::string &  descr
 );
void initialize( AuthenticateRequest * res
    , const std::string &  user_login
    , const std::string &  password
 );
void initialize( AuthenticateAltRequest * res
    , uint32_t user_id
    , const std::string &  password
 );
void initialize( AuthenticateResponse * res
    , const std::string &  session_id
 );
void initialize( CloseSessionRequest * res
    , const std::string &  session_id
 );
void initialize( CloseSessionResponse * res
 );
void initialize( GetUserIdRequest * res
    , const std::string &  base_class_param_1
    , const std::string &  user_login
 );
void initialize( GetUserIdResponse * res
    , uint32_t user_id
 );
void initialize( GetSessionInfoRequest * res
    , const std::string &  base_class_param_1
    , const std::string &  id
 );
void initialize( GetSessionInfoResponse * res
    , const SessionInfo &  session_info
 );

// messages (constructors)

ErrorResponse * create_ErrorResponse(
    ErrorResponse_type_e type
    , const std::string &  descr
 );
AuthenticateRequest * create_AuthenticateRequest(
    const std::string &  user_login
    , const std::string &  password
 );
AuthenticateAltRequest * create_AuthenticateAltRequest(
    uint32_t user_id
    , const std::string &  password
 );
AuthenticateResponse * create_AuthenticateResponse(
    const std::string &  session_id
 );
CloseSessionRequest * create_CloseSessionRequest(
    const std::string &  session_id
 );
CloseSessionResponse * create_CloseSessionResponse(
 );
GetUserIdRequest * create_GetUserIdRequest(
    const std::string &  base_class_param_1
    , const std::string &  user_login
 );
GetUserIdResponse * create_GetUserIdResponse(
    uint32_t user_id
 );
GetSessionInfoRequest * create_GetSessionInfoRequest(
    const std::string &  base_class_param_1
    , const std::string &  id
 );
GetSessionInfoResponse * create_GetSessionInfoResponse(
    const SessionInfo &  session_info
 );

} // namespace generic_protocol

#endif // APG_GENERIC_PROTOCOL__OBJECT_INITIALIZER_H
