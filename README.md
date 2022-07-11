# star library

A experiment c++ library

# Feature

## memory

- Box

    like unique_ptr
- Rc(reference counter)

    like shared_ptr, but without `week_ptr` and **not thread-safe**

## container

not thread-safe

- Buffer2D  
    a 2D vector

## useful tools

- [Result](star/include/Result.hpp)

    like [Rust result](https://doc.rust-lang.org/std/result/)
- [Timer](star/include/Timer.hpp)

    Measure the elapsed time between two code sections
- [join](star/include/join.hpp)

    compile time concatenate string