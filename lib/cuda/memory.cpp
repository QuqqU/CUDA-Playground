#include <mylib/cuda/memory.hpp>

#include <cuda_runtime.h>
#include <stdlib.h>
#include <utility>

namespace qCuda {
namespace mem {

// HostMem
HostMem::HostMem(size_t length) : length(length) {
    cudaMalloc((void **)&h_mem, length * sizeof(float));
}

HostMem::~HostMem() { cudaFree(h_mem); }

const float *HostMem::operator&() { return h_mem; }

// DeviceMem
DeviceMem::DeviceMem(size_t length) : length(length) {
    cudaMalloc((void **)&d_mem, length * sizeof(float));
}

DeviceMem::~DeviceMem() { cudaFree(d_mem); }

const float *DeviceMem::operator&() { return d_mem; }

// memcpy
cudaError_t memcpy_host_to_device(DeviceMem *dev, const HostMem *host) {
    return cudaMemcpy(dev, host, dev->length, cudaMemcpyHostToDevice);
}

cudaError_t memcpy_device_to_host(HostMem *host, const DeviceMem *dev) {
    return cudaMemcpy(host, dev, host->length, cudaMemcpyDeviceToHost);
}

} // namespace mem
} // namespace qCuda