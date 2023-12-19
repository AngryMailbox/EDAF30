#include <iostream>
#include <string>
#include "TagRemover.h"
using namespace std;

string TagRemover::translate(std::string str)
{
    std::string newStr = "";
    bool in = false;

    for (auto i = 0u; i < str.length(); i++)
    {
        if (str[i] == '&')
        {
            if (str.substr(i, 4) == "&lt;")
            {
                newStr += "<";
                i += 3;
                in = true;
            }
            else if (str.substr(i, 4) == "&gt;")
            {
                newStr += ">";
                i += 3;
                in = true;
            }
            else if (str.substr(i, 5) == "&amp;")
            {
                newStr += "&";
                i += 4;
                in = true;
            }
            else if (str.substr(i, 6) == "&nbsp;")
            {
                newStr += " ";
                i += 5;
                in = true;
            }
        }

        if (!in)
        {
            newStr += str[i];
        }
        else
        {
            in = false; // Reset 'in' after processing HTML entity
        }
    }

    return newStr;
}

bool inside = false;

string TagRemover::removeTags(std::string str)
{
    string newStr = "";

    for (auto i = 0u; i < str.length(); i++)
    {
        if (str[i] == '<')
        {
            inside = true;
        }
        else if (str[i] == '>')
        {
            inside = false;
        }
        else if (!inside)
        {
            newStr += str[i];
        }
    }
    string ret = translate(newStr);
    return ret;
}

void TagRemover::print(std::ostream &outputStream)
{
    string line;
    while (getline(inputStream, line))
    {
        outputStream << removeTags(line) << endl;
    }
}