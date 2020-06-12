#ifndef APG_GENERIC__CSV_HELPER_H
#define APG_GENERIC__CSV_HELPER_H

// system includes
#include <sstream>

// includes
#include "protocol.h"

namespace generic_protocol
{

namespace csv_helper
{

// enums
std::ostream & write( std::ostream & os, const ErrorResponse_type_e & r );

// objects
std::ostream & write( std::ostream & os, const SessionInfo & r );

// base messages
std::ostream & write( std::ostream & os, const ForwardMessage & r );
std::ostream & write( std::ostream & os, const BackwardMessage & r );
std::ostream & write( std::ostream & os, const Request & r );

// messages
std::ostream & write( std::ostream & os, const ErrorResponse & r );
std::ostream & write( std::ostream & os, const AuthenticateRequest & r );
std::ostream & write( std::ostream & os, const AuthenticateAltRequest & r );
std::ostream & write( std::ostream & os, const AuthenticateResponse & r );
std::ostream & write( std::ostream & os, const CloseSessionRequest & r );
std::ostream & write( std::ostream & os, const CloseSessionResponse & r );
std::ostream & write( std::ostream & os, const GetUserIdRequest & r );
std::ostream & write( std::ostream & os, const GetUserIdResponse & r );
std::ostream & write( std::ostream & os, const GetSessionInfoRequest & r );
std::ostream & write( std::ostream & os, const GetSessionInfoResponse & r );

template<class T>
std::string to_csv( const T & l )
{
    std::ostringstream os;

    write( os, l );

    return os.str();
}

// generic
std::ostream & write( std::ostream & os, const basic_parser::Object & r );

} // namespace csv_helper

} // namespace generic_protocol

#endif // APG_GENERIC__CSV_HELPER_H
