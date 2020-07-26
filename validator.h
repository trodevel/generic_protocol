#ifndef APG_GENERIC__VALIDATOR_H
#define APG_GENERIC__VALIDATOR_H

// includes
#include "protocol.h"

namespace generic_protocol
{

namespace validator
{

// enums
bool validate( const std::string & prefix, const ErrorResponse_type_e r );

// objects
bool validate( const std::string & prefix, const SessionInfo & r );

// base messages
bool validate( const ForwardMessage & r );
bool validate( const BackwardMessage & r );
bool validate( const Request & r );

// messages
bool validate( const ErrorResponse & r );
bool validate( const AuthenticateRequest & r );
bool validate( const AuthenticateAltRequest & r );
bool validate( const AuthenticateResponse & r );
bool validate( const CloseSessionRequest & r );
bool validate( const CloseSessionResponse & r );
bool validate( const GetUserIdRequest & r );
bool validate( const GetUserIdResponse & r );
bool validate( const GetSessionInfoRequest & r );
bool validate( const GetSessionInfoResponse & r );

} // namespace validator

} // namespace generic_protocol

#endif // APG_GENERIC__VALIDATOR_H
