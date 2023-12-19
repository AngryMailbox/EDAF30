#ifndef TAGREMOVER_H
#define TAGREMOVER_H
#include <iostream>
#include <cassert>
#include <string>

class TagRemover
{
public:
    TagRemover(std::istream &inputStream) : inputStream(inputStream)
    {
    }

    void print(std::ostream &outputStream);

    std::string removeTags(std::string str);
    std::istream &inputStream;

    std::string translate(std::string str);
};

#endif