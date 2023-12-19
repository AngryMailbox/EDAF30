#ifndef STRING_CAST_H
#define STRING_CAST_H
#include <sstream>
#include <stdexcept>

template <typename T>
T string_cast(std::string s)
{
    std::istringstream in;
    in.str(s);
    T ret;
    try
    {
        in >> ret;
        if (in.fail())
        {
            throw std::invalid_argument("");
        }
    }
    catch (std::exception &e)
    {
        std::string t = typeid(ret).name();
        throw std::invalid_argument("Cant cast from a string to " + t);
    }
    return ret;
}

#endif