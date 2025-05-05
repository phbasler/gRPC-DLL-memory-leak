#include <grpcpp/support/slice.h>

namespace
{
    int myFunc()
{
    #ifdef UseSlice
    grpc::Slice slice;
    #endif

    return 0;
}
}
