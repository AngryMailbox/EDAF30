#include <date.h>
#include <string_cast.h>
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cassert>
#include <toString.h>

using namespace std;

void test()
{
    try
    {
        int i = string_cast<int>("123");
        double d = string_cast<double>("12.34");
        Date a = string_cast<Date>("2015-01-10");
        Date b{2015, 01, 10};

        cout << "i = " << i << endl;
        assert(i == 123);
        cout << "d = " << d << endl;
        assert(d == 12.34);

        cout << "a = " << toString(a) << endl;
        cout << "b = " << toString(b) << endl;
        cout << "Tests passed!" << endl;
    }
    catch (std::invalid_argument &e)
    {
        cout << "Error: " << e.what() << endl;
        cout << "Tests failed!" << endl;
    }
}
int main()
{
    test();

    return 0;
}