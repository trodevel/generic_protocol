// system includes
#include <map>

// includes
#include "str_helper.h"
#include "basic_parser/str_helper.h"

namespace generic_protocol
{

namespace str_helper
{

using ::basic_parser::str_helper::write;
using ::basic_parser::str_helper::write_t;

// enums

#define TUPLE_VAL_STR(_x_)  _x_,#_x_

std::ostream & write( std::ostream & os, const ErrorResponse_type_e r )
{
    typedef ErrorResponse_type_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( AUTHENTICATION_ERROR ) },
        { Type:: TUPLE_VAL_STR( NOT_PERMITTED ) },
        { Type:: TUPLE_VAL_STR( INVALID_ARGUMENT ) },
        { Type:: TUPLE_VAL_STR( RUNTIME_ERROR ) },
    };

    auto it = m.find( r );

    static const std::string undef( "undef" );

    if( it != m.end() )
        return write( os, it->second );

    return write( os, undef );
}

// objects

std::ostream & write( std::ostream & os, const SessionInfo & r )
{
    os << "(";

    os << " user_id="; write( os, r.user_id );
    os << " start_time="; write( os, r.start_time );
    os << " expiration_time="; write( os, r.expiration_time );

    os << ")";

    return os;
}

// base messages

std::ostream & write( std::ostream & os, const ForwardMessage & r )
{
    os << "(";


    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const BackwardMessage & r )
{
    os << "(";


    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const Request & r )
{
    os << "(";

    os << " session_id="; write( os, r.session_id );

    os << ")";

    return os;
}

// messages

std::ostream & write( std::ostream & os, const ErrorResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    os << " type="; write( os, r.type );
    os << " descr="; write( os, r.descr );

    return os;
}

std::ostream & write( std::ostream & os, const AuthenticateRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const ForwardMessage&>( r ) );

    os << " user_login="; write( os, r.user_login );
    os << " password="; write( os, r.password );

    return os;
}

std::ostream & write( std::ostream & os, const AuthenticateAltRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const ForwardMessage&>( r ) );

    os << " user_id="; write( os, r.user_id );
    os << " password="; write( os, r.password );

    return os;
}

std::ostream & write( std::ostream & os, const AuthenticateResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    os << " session_id="; write( os, r.session_id );

    return os;
}

std::ostream & write( std::ostream & os, const CloseSessionRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const ForwardMessage&>( r ) );

    os << " session_id="; write( os, r.session_id );

    return os;
}

std::ostream & write( std::ostream & os, const CloseSessionResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const GetUserIdRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " user_login="; write( os, r.user_login );

    return os;
}

std::ostream & write( std::ostream & os, const GetUserIdResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    os << " user_id="; write( os, r.user_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetSessionInfoRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " id="; write( os, r.id );

    return os;
}

std::ostream & write( std::ostream & os, const GetSessionInfoResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    os << " session_info="; write( os, r.session_info );

    return os;
}

} // namespace str_helper

} // namespace generic_protocol

