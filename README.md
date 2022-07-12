# star library

A experiment c++20 library

# Getting stared

Install [xmake](https://xmake.io/), create your xmake.lua and add one line

```lua
includes("star")
```

# Feature

## memory

- Box

    Like unique_ptr

- Rc(reference counter)

    Like shared_ptr, but without `week_ptr` and **not thread-safe**

## container

Not thread-safe

- Buffer2D  
    A 2D vector

## useful tools

- [Result](star/include/Result.hpp)

    Like [Rust result](https://doc.rust-lang.org/std/result/)

- [Timer](star/include/Timer.hpp)

    Measure the elapsed time between two code sections

- [join](star/include/join.hpp)

    Compile time concatenate string
