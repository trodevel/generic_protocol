#ifndef APG_GENERIC__REQUEST_TYPE_PARSER_H
#define APG_GENERIC__REQUEST_TYPE_PARSER_H

// includes
#include "enums.h"

namespace generic_protocol
{

class RequestTypeParser
{
public:
    static request_type_e   to_request_type( const std::string & s );
};
} // namespace generic_protocol

#endif // APG_GENERIC__REQUEST_TYPE_PARSER_H
