#pragma once

#include <cstdint>
#include <utility>
#include <new>
// thread not safe, without week count
template <typename T>
struct Rc
{
private:
    template <typename T2>
    struct Block
    {
        std::size_t counter = 1;
        char value[sizeof(T2)];

        Block(const Block&) = delete;
        Block& operator = (const Block& rc) = delete;
        Block& operator = (Block&& rc) = delete;

        Block() {}

        void inc()
        {
            counter += 1;
        }

        void dec()
        {
            counter -= 1;
        }

        bool is_zero()
        {
            return counter == 0;
        }

        auto get() noexcept
        {
            return value;
        }
    };

private:
    T* ptr;
    Block<T>* block;

    template <typename T2>
    friend struct Rc;

    void set_value()
    {
        ptr = nullptr;
        block = nullptr;
    }

public:
    constexpr Rc()
    {
        this->set_value();
    }

    template <typename T2>
    Rc(const Rc<T2>& rc)
    {
        rc.block->inc();

        this->ptr = rc.ptr;
        this->block = reinterpret_cast<Block<T>*>(rc.block);
    }

    template <typename T2>
    Rc(Rc<T2>&& rc) noexcept
    {
        this->ptr = rc.ptr;
        this->block = reinterpret_cast<Block<T>*>(rc.block);

        rc.set_value();
    }

    template <typename T2>
    Rc& operator = (const Rc<T2>& rc)
    {
        Rc(rc).swap(*this);
        return *this;
    }

    template <typename T2>
    Rc& operator = (Rc<T2>&& rc) noexcept
    {
        Rc(std::move(rc)).swap(*this);
        return *this;
    }

    ~Rc()
    {
        if(!block) return;

        block->dec();
        if(!block->is_zero()) return;

        reinterpret_cast<T*>(block->get())->~T();
        delete block;
        set_value();
    }

    template <typename... Args>
    static Rc<T> make(Args&&... args)
    {
        auto block = new Block<T>();
        Rc<T> rc;
        rc.block = block;
        rc.ptr = new (block->get()) T(std::forward<Args>(args)...);
        return rc;
    }

    template <typename T2>
    void swap(Rc<T2>& rc) noexcept
    {
        std::swap(ptr, rc.ptr);
        std::swap(block, rc.block);
    }

    T* get() const
    {
        return ptr;
    }

    T& operator * () const
    {
        return *get();
    }

    T* operator -> () const
    {
        return get();
    }

    operator bool () const
    {
        return block != nullptr;
    }
};
