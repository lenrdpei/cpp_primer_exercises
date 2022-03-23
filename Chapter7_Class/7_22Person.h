#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
class Person
{
    friend std::istream &read(std::istream &is, Person &p);
    friend std::ostream &print(std::ostream &os, const Person &p);

private:
    std::string name;
    std::string address;

public:
    Person() = default;
    Person(std::string &nm, std::string &ad) : name(nm), address(ad){};
    Person(std::istream &is) { is >> name >> address; };
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