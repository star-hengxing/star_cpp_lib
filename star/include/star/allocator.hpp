#pragma once

#include <cstdlib>

auto operator new(std::size_t size) -> void*
{
    if (size == 0) [[unlikely]]
        size = 1;

    const auto ptr = std::malloc(size);
    if (!ptr) [[unlikely]]
    {
        std::abort();
    }

    return ptr;
}

auto operator delete(void* ptr) noexcept -> void
{
    std::free(ptr);
}
