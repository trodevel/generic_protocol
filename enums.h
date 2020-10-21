#ifndef APG_GENERIC_PROTOCOL__ENUMS_H
#define APG_GENERIC_PROTOCOL__ENUMS_H

namespace generic_protocol
{

enum class request_type_e
{
    UNDEF,
    ErrorResponse,
    AuthenticateRequest,
    AuthenticateAltRequest,
    AuthenticateResponse,
    CloseSessionRequest,
    CloseSessionResponse,
    GetUserIdRequest,
    GetUserIdResponse,
    GetSessionInfoRequest,
    GetSessionInfoResponse,
};

} // namespace generic_protocol

#endif // APG_GENERIC_PROTOCOL__ENUMS_H
