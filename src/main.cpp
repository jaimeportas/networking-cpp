#include <iostream>
#include <functional>

#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

int main()
{
    [out = std::ref(std::cout << "Hello ")]() { out.get() << "World!\n"; }(); // Do not use std::endl because it does a flush. See https://youtu.be/GMqQOEZYVJQ
}