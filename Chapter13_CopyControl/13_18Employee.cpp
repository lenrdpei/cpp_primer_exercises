#include <string>
#include <iostream>
class Employee
{
public:
    static int cnt;
    Employee() : name("N/A"), num(10000 + cnt) { ++cnt; }
    Employee(std::string nm) : name(nm), num(10000 + cnt) { ++cnt; }
    Employee(const Employee &) = delete;
    Employee &operator=(const Employee &) = delete;

private:
    std::string name;
    int num;
};
int Employee::cnt = 0;