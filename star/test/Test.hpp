#pragma once

#include <iostream>

template <typename... Args>
void println(const Args&... args)
{
    ((std::cout << args << '\n'), ...);
}

struct Base
{
    Base() { println("Base()"); }
    virtual ~Base() { println("~Base()"); }

    Base(const Base&) { println("Base(const Base&)"); }
    Base(Base&&) { println("Base(Base&&)"); }

    Base& operator = (const Base&)
    {
        println(" Base& operator = (const Base&)");
        return *this;
    }

    Base& operator = (Base&&)
    {
        println("Base& operator = (Base&&)");
        return *this;
    }

    virtual void test() { println("Base test"); }
};

struct Derive : public Base
{
    Derive() { println("Derive()"); }
    ~Derive() { println("~Derive()"); }

    Derive(const Derive&) { println("Derive(const Derive&)"); }
    Derive(Derive&&) { println("Derive(Derive&&)"); }

    Derive& operator = (const Derive&)
    {
        println(" Derive& operator = (const Derive&)");
        return *this;
    }

    Derive& operator = (Derive&&)
    {
        println("Derive& operator = (Derive&&)");
        return *this;
    }

    virtual void test() override { println("Derive test"); }
};
