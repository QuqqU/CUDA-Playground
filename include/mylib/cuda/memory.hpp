#include <cuda_runtime.h>
#include <stdlib.h>
#include <utility>

namespace qCuda {
namespace mem {

struct HostMem {
    HostMem(size_t length);
    ~HostMem();

    const float *operator&();

    float *h_mem;
    size_t length;
};

struct DeviceMem {
    DeviceMem(size_t length);
    ~DeviceMem();

    const float *operator&();

    float *d_mem;
    size_t length;
};

cudaError_t memcpy_host_to_device(DeviceMem *dev, const HostMem *host);
cudaError_t memcpy_device_to_host(HostMem *host, const DeviceMem *dev);

} // namespace mem
} // namespace qCuda