#pragma once

#include <cstdint>
#include <utility>

template <typename T>
struct Box
{
private:
    using value_type = std::remove_all_extents_t<T>;
    using pointer = value_type*;
    using reference = value_type&;
    using const_pointer = const value_type*;
    using const_reference = const value_type&;
    using Self = Box;

private:
    pointer ptr;

    template <typename T2>
    friend struct Box;

public:
    constexpr Box(pointer ptr = nullptr) : ptr(ptr) {}

    Box(const Box<T>&) = delete;
    Box<T>& operator = (const Box<T>&) = delete;

    template <typename T2>
    Box(Box<T2>&& box) noexcept : ptr(box.ptr)
    {
        box.ptr = nullptr;
    }

    template <typename T2>
    auto operator = (Box<T2>&& box) noexcept -> Self&
    {
        Box(std::move(box)).swap(*this);
        return *this;
    }

    ~Box()
    {
        if(ptr != nullptr)
        {
            if constexpr (std::is_array_v<T>)
                delete[] ptr;
            else
                delete ptr;

            ptr = nullptr;
        }
    }

    template <typename... Args>
    requires (!std::is_array_v<T>)
    static auto make(Args&&... args) -> Self
    {
        return {new value_type{std::forward<Args>(args)...}};
    }

    template <typename T2 = T>
    requires std::is_array_v<T>
    static auto make(size_t size) -> Self
    {
        return {new value_type[size]{}};
    }

    template <typename T2>
    auto swap(Box<T2>& box) -> void
    {
        using std::swap;
        swap(ptr, box.ptr);
    }

    auto get() const noexcept -> pointer
    {
        return ptr;
    }

    auto get_owner() noexcept -> pointer
    {
        auto tmp = ptr;
        ptr = nullptr;
        return tmp;
    }

    template <typename T2 = T>
    requires std::is_array_v<T>
    auto operator [] (size_t index) noexcept -> reference
    {
        return ptr[index];
    }

    template <typename T2 = T>
    requires std::is_array_v<T>
    auto operator [] (size_t index) const noexcept -> value_type
    {
        return ptr[index];
    }

    auto operator * () const noexcept -> value_type
    {
        return *ptr;
    }

    auto operator -> () const noexcept -> pointer
    {
        return ptr;
    }

    operator bool () const noexcept
    {
        return ptr != nullptr;
    }
};
