#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        try
        {
            if (b == 0)
                throw runtime_error("Divisor is 0.");
            else
            {
                cout << a / b << endl;
                break;
            }
        }
        catch (runtime_error e)
        {
            cout << e.what() << endl;
            cout << "Try again? Enter y or n." << endl;
            char ch;
            cin >> ch;
            if (ch == 'n')
                break;
        }
    }
}