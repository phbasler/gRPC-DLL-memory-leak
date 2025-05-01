#include <grpcpp/support/slice.h>

namespace
{
    #ifdef UseSplice
    grpc::Splice slice;
    #endif
}