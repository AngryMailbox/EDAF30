#ifndef STRING_CAST_H
#define STRING_CAST_H
#include <sstream>
#include <stdexcept>

template <typename T>
T string_cast(std::string s)
{
    std::stringstream in(s);
    T ret;
    try
    {
        in >> ret;
        if (in.fail() || !in.eof())
        {
            throw std::exception();
        }
    }
    catch (std::exception &e)
    {
        std::string type = typeid(ret).name();
        throw std::invalid_argument("Cant cast from a string to " + type);
    }
    return ret;
}

#endif