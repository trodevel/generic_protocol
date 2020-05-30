#ifndef APG_GENERIC__OBJECT_INITIALIZER_H
#define APG_GENERIC__OBJECT_INITIALIZER_H

// includes
#include "protocol.h"

namespace generic_protocol
{

// base messages

void initialize( BackwardMessage * res );

// base messages

void initialize( Request * res
    , const std::string &  session_id
 );


} // namespace generic_protocol

#endif // APG_GENERIC__OBJECT_INITIALIZER_H
