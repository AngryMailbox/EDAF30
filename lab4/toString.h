#include <iostream>
#include <string>
#include <sstream>
#include "date.h"

template <typename T>
std::string toString(const T &value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

// int main()
// {
//     double d = 1.234;
//     Date today;

//     std::string sd = toString(d);
//     std::string st = toString(today);

//     std::cout << "String of double: " << sd << std::endl;
//     std::cout << "String of Date: " << st << std::endl;

//     return 0;
// }
