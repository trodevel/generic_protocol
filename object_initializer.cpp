// includes
#include "object_initializer.h"

namespace generic_protocol
{

// base messages

void initialize( BackwardMessage * res )
{
}

// base messages

void initialize( Request * res
    , const std::string &  session_id
 )
{
    res->session_id = session_id;
}

} // namespace generic_protocol
