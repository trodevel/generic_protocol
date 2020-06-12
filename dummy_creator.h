#ifndef APG_GENERIC__DUMMY_CREATOR_H
#define APG_GENERIC__DUMMY_CREATOR_H

// includes
#include "protocol.h"

namespace generic_protocol
{

namespace dummy
{

// enums

ErrorResponse_type_e create__ErrorResponse_type_e();

// objects

SessionInfo create__SessionInfo();

// messages

ErrorResponse * create__ErrorResponse();
AuthenticateRequest * create__AuthenticateRequest();
AuthenticateAltRequest * create__AuthenticateAltRequest();
AuthenticateResponse * create__AuthenticateResponse();
CloseSessionRequest * create__CloseSessionRequest();
CloseSessionResponse * create__CloseSessionResponse();
GetUserIdRequest * create__GetUserIdRequest();
GetUserIdResponse * create__GetUserIdResponse();
GetSessionInfoRequest * create__GetSessionInfoRequest();
GetSessionInfoResponse * create__GetSessionInfoResponse();

} // namespace dummy

} // namespace generic_protocol

#endif // APG_GENERIC__DUMMY_CREATOR_H
