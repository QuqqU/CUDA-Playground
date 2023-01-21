#include <cuda_runtime.h>
#include <mylib/cuda/memory.hpp>
#include <mylib/type/result.hpp>

namespace qCuda {

//////////////////////ddd;

template <typename ElemType>
types::Result<ElemType *, cudaError_t> mem::cuda_malloc(size_t length) {
    void *ptr = nullptr;
    cudaError_t err_code = cudaMalloc(&ptr, length * sizeof(ElemType));
    if (err_code != cudaError::cudaSuccess)
        return types::Err(err_code);
    return types::Ok(static_cast<ElemType *>(ptr));
}

} // namespace qCuda