#include <iostream>
int main()
{
    std::cout << "/*"; // legimate
    std::cout << "*/"; // legimate
    std::cout << /* "*/ " */; //illegimate, the same reason for the 4th sentence
}