// system includes
#include <map>
#include <typeindex>

// includes
#include "csv_helper.h"
#include "basic_parser/csv_helper.h"

namespace generic_protocol
{

namespace csv_helper
{

using ::basic_parser::csv_helper::write;
using ::basic_parser::csv_helper::write_t;

// enums

std::ostream & write( std::ostream & os, const ErrorResponse_type_e r )
{
    write( os, static_cast<unsigned>( r ) );

    return os;
}

// objects

std::ostream & write( std::ostream & os, const SessionInfo & r )
{
    write( os, r.user_id );
    write( os, r.start_time );
    write( os, r.expiration_time );

    return os;
}

// base messages

std::ostream & write( std::ostream & os, const ForwardMessage & r )
{

    return os;
}

std::ostream & write( std::ostream & os, const BackwardMessage & r )
{

    return os;
}

std::ostream & write( std::ostream & os, const Request & r )
{
    write( os, r.session_id );

    return os;
}

// messages

std::ostream & write( std::ostream & os, const ErrorResponse & r )
{
    write( os, std::string( "generic/ErrorResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    write( os, r.type );
    write( os, r.descr );

    return os;
}

std::ostream & write( std::ostream & os, const AuthenticateRequest & r )
{
    write( os, std::string( "generic/AuthenticateRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const ForwardMessage&>( r ) );

    write( os, r.user_login );
    write( os, r.password );

    return os;
}

std::ostream & write( std::ostream & os, const AuthenticateAltRequest & r )
{
    write( os, std::string( "generic/AuthenticateAltRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const ForwardMessage&>( r ) );

    write( os, r.user_id );
    write( os, r.password );

    return os;
}

std::ostream & write( std::ostream & os, const AuthenticateResponse & r )
{
    write( os, std::string( "generic/AuthenticateResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    write( os, r.session_id );

    return os;
}

std::ostream & write( std::ostream & os, const CloseSessionRequest & r )
{
    write( os, std::string( "generic/CloseSessionRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const ForwardMessage&>( r ) );

    write( os, r.session_id );

    return os;
}

std::ostream & write( std::ostream & os, const CloseSessionResponse & r )
{
    write( os, std::string( "generic/CloseSessionResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const GetUserIdRequest & r )
{
    write( os, std::string( "generic/GetUserIdRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.user_login );

    return os;
}

std::ostream & write( std::ostream & os, const GetUserIdResponse & r )
{
    write( os, std::string( "generic/GetUserIdResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    write( os, r.user_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetSessionInfoRequest & r )
{
    write( os, std::string( "generic/GetSessionInfoRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.id );

    return os;
}

std::ostream & write( std::ostream & os, const GetSessionInfoResponse & r )
{
    write( os, std::string( "generic/GetSessionInfoResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    write( os, r.session_info );

    return os;
}

std::ostream & write_ErrorResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const ErrorResponse &>( rr );

    return write( os, r );
}

std::ostream & write_AuthenticateRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const AuthenticateRequest &>( rr );

    return write( os, r );
}

std::ostream & write_AuthenticateAltRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const AuthenticateAltRequest &>( rr );

    return write( os, r );
}

std::ostream & write_AuthenticateResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const AuthenticateResponse &>( rr );

    return write( os, r );
}

std::ostream & write_CloseSessionRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const CloseSessionRequest &>( rr );

    return write( os, r );
}

std::ostream & write_CloseSessionResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const CloseSessionResponse &>( rr );

    return write( os, r );
}

std::ostream & write_GetUserIdRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetUserIdRequest &>( rr );

    return write( os, r );
}

std::ostream & write_GetUserIdResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetUserIdResponse &>( rr );

    return write( os, r );
}

std::ostream & write_GetSessionInfoRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetSessionInfoRequest &>( rr );

    return write( os, r );
}

std::ostream & write_GetSessionInfoResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetSessionInfoResponse &>( rr );

    return write( os, r );
}


std::ostream & write( std::ostream & os, const basic_parser::Object & r )
{
    typedef std::ostream & (*PPMF)( std::ostream & os, const basic_parser::Object & );

#define HANDLER_MAP_ENTRY(_v)       { typeid( _v ),        & write_##_v }

    static const std::map<std::type_index, PPMF> funcs =
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

    auto it = funcs.find( typeid( r ) );

    if( it != funcs.end() )
        return it->second( os, r );

    return os;
}

} // namespace csv_helper

} // namespace generic_protocol

