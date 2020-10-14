#include <iostream>
#include <functional>

int main()
{
    [out = std::ref(std::cout << "Hello ")]() { out.get() << "World!\n"; }(); // Do not use std::endl because it does a flush. See https://youtu.be/GMqQOEZYVJQ
}