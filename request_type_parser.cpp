// system includes
#include <map>

// includes
#include "request_type_parser.h"

namespace generic_protocol
{

#define TUPLE_VAL_STR(_x_)  _x_,"generic/"+std::string(#_x_)

template< typename _U, typename _V >
std::pair<_V,_U> make_inverse_pair( _U first, _V second )
{
    return std::make_pair( second, first );
}

request_type_e RequestTypeParser::to_request_type( const std::string & s )
{
    typedef std::string KeyType;
    typedef request_type_e Type;

    typedef std::map< KeyType, Type > Map;
    static const Map m =
    {
        make_inverse_pair( Type:: TUPLE_VAL_STR( ErrorResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( AuthenticateRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( AuthenticateAltRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( AuthenticateResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( CloseSessionRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( CloseSessionResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetUserIdRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetUserIdResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetSessionInfoRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetSessionInfoResponse ) ),
    };

    auto it = m.find( s );

    if( it == m.end() )
        return request_type_e::UNDEF;

    return it->second;
}
} // namespace generic_protocol

