#include "toString.h"
#include <cassert>
#include <iostream>

void testToString()
{
    double d = 1.234;

    std::string sd = toString(d);
    assert(sd == "1.234");

    Date date = Date(2020, 11, 11);
    std::string st = toString(date);
    assert(st == "2020-11-11");

    std::cout << "Tests passed!" << std::endl;
}

int main()
{
    testToString();

    return 0;
}