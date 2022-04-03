#ifndef READLINE_H
#define READLINE_H
#include <iostream>
#include <string>
#include <vector>
class Readline
{
    std::string operator()(std::istream &is)
    {
        std::string s;
        std::getline(is, s);
        if (is)
            return s;
        else
            return std::string();
    }
};
#endif