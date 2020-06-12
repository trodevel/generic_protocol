#ifndef APG_GENERIC__PARSER_H
#define APG_GENERIC__PARSER_H

// includes
#include "generic_request/request.h"
#include "enums.h"
#include "protocol.h"

namespace generic_protocol
{

namespace parser
{

typedef basic_parser::Object    Object;

basic_parser::Object * to_forward_message( const generic_request::Request & r );

request_type_e detect_request_type( const generic_request::Request & r );

// enums

void get_value_or_throw( ErrorResponse_type_e * res, const std::string & key, const generic_request::Request & r );

// objects

void get_value_or_throw( SessionInfo * res, const std::string & key, const generic_request::Request & r );

// base messages

void get_value_or_throw( ForwardMessage * res, const generic_request::Request & r );
void get_value_or_throw( BackwardMessage * res, const generic_request::Request & r );
void get_value_or_throw( Request * res, const generic_request::Request & r );

// messages

void get_value_or_throw( ErrorResponse * res, const generic_request::Request & r );
void get_value_or_throw( AuthenticateRequest * res, const generic_request::Request & r );
void get_value_or_throw( AuthenticateAltRequest * res, const generic_request::Request & r );
void get_value_or_throw( AuthenticateResponse * res, const generic_request::Request & r );
void get_value_or_throw( CloseSessionRequest * res, const generic_request::Request & r );
void get_value_or_throw( CloseSessionResponse * res, const generic_request::Request & r );
void get_value_or_throw( GetUserIdRequest * res, const generic_request::Request & r );
void get_value_or_throw( GetUserIdResponse * res, const generic_request::Request & r );
void get_value_or_throw( GetSessionInfoRequest * res, const generic_request::Request & r );
void get_value_or_throw( GetSessionInfoResponse * res, const generic_request::Request & r );

// to_... functions

Object * to_ErrorResponse( const generic_request::Request & r );
Object * to_AuthenticateRequest( const generic_request::Request & r );
Object * to_AuthenticateAltRequest( const generic_request::Request & r );
Object * to_AuthenticateResponse( const generic_request::Request & r );
Object * to_CloseSessionRequest( const generic_request::Request & r );
Object * to_CloseSessionResponse( const generic_request::Request & r );
Object * to_GetUserIdRequest( const generic_request::Request & r );
Object * to_GetUserIdResponse( const generic_request::Request & r );
Object * to_GetSessionInfoRequest( const generic_request::Request & r );
Object * to_GetSessionInfoResponse( const generic_request::Request & r );

} // namespace parser

} // namespace generic_protocol

#endif // APG_GENERIC__PARSER_H
