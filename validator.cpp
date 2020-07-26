// includes
#include "validator.h"
#include "basic_parser/validator.h"

namespace generic_protocol
{

namespace validator
{

using ::basic_parser::validator::validate;
using ::basic_parser::validator::validate_t;

// enums

bool validate( const std::string & prefix, const ErrorResponse_type_e r )
{
    validate( prefix, static_cast<unsigned>( r ), true, true, static_cast<unsigned>( ErrorResponse_type_e::AUTHENTICATION_ERROR ), true, true, static_cast<unsigned>( ErrorResponse_type_e::RUNTIME_ERROR ) );

    return true;
}

// objects

bool validate( const std::string & prefix, const SessionInfo & r )
{
    validate( prefix + ".USER_ID", r.user_id );
    validate( prefix + ".START_TIME", r.start_time );
    validate( prefix + ".EXPIRATION_TIME", r.expiration_time );

    return true;
}

// base messages

bool validate( const ForwardMessage & r )
{

    return true;
}

bool validate( const BackwardMessage & r )
{

    return true;
}

bool validate( const Request & r )
{
    validate( "SESSION_ID", r.session_id ); // String

    return true;
}

// messages

bool validate( const ErrorResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );

    validate( "TYPE", r.type );
    validate( "DESCR", r.descr ); // String

    return true;
}

bool validate( const AuthenticateRequest & r )
{
    // base class
    validator::validate( static_cast<const ForwardMessage&>( r ) );

    validate( "USER_LOGIN", r.user_login ); // String
    validate( "PASSWORD", r.password ); // String

    return true;
}

bool validate( const AuthenticateAltRequest & r )
{
    // base class
    validator::validate( static_cast<const ForwardMessage&>( r ) );

    validate( "USER_ID", r.user_id );
    validate( "PASSWORD", r.password ); // String

    return true;
}

bool validate( const AuthenticateResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );

    validate( "SESSION_ID", r.session_id ); // String

    return true;
}

bool validate( const CloseSessionRequest & r )
{
    // base class
    validator::validate( static_cast<const ForwardMessage&>( r ) );

    validate( "SESSION_ID", r.session_id ); // String

    return true;
}

bool validate( const CloseSessionResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );


    return true;
}

bool validate( const GetUserIdRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "USER_LOGIN", r.user_login ); // String

    return true;
}

bool validate( const GetUserIdResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );

    validate( "USER_ID", r.user_id );

    return true;
}

bool validate( const GetSessionInfoRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "ID", r.id ); // String

    return true;
}

bool validate( const GetSessionInfoResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );

    validate( "SESSION_INFO", r.session_info );

    return true;
}

} // namespace validator

} // namespace generic_protocol

