#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
struct Person
{
    std::string name;
    std::string address;
};
std::istream &read(std::istream &is, Person &p)
{
    is >> p.name >> p.address;
    return is;
}
std::ostream &print(std::ostream &os, const Person &p)
{
    os << p.name << " " << p.address;
    return os;
}
#endif