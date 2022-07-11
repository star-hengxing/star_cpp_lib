#pragma once

#include <cstdint>
#include <utility>

template <typename T>
struct Box
{
private:
    T* ptr;

    template <typename T2>
    friend struct Box;

public:
    constexpr Box(T* ptr = nullptr) : ptr(ptr) {}

    Box(const Box<T>&) = delete;
    Box<T>& operator = (const Box<T>&) = delete;

    template <typename T2>
    Box(Box<T2>&& box) noexcept : ptr(box.ptr)
    {
        box.ptr = nullptr;
    }

    template <typename T2>
    Box& operator = (Box<T2>&& box) noexcept
    {
        Box(std::move(box)).swap(*this);
        return *this;
    }

    ~Box()
    {
        if(ptr != nullptr)
        {
            delete ptr;
            ptr = nullptr;
        }
    }

    template <typename... Args>
    static Box<T> make(Args&&... args)
    {
        return {new T(std::forward<Args>(args)...)};
    }

    template <typename T2>
    void swap(Box<T2>& box)
    {
        std::swap(ptr, box.ptr);
    }

    T* get() const noexcept
    {
        return ptr;
    }

    T operator * () const noexcept
    {
        return *get();
    }

    T* operator -> () const noexcept
    {
        return get();
    }

    operator bool () const
    {
        return ptr != nullptr;
    }
};
