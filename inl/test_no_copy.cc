// test_no_copy.cc
#include "NoCopy.h"
#include "concatenation.h"
#include <vector>
#include <iostream>
#include "test.h"
using std::cout;
using std::endl;

template <typename C, typename T>
void emfill(C &c, std::initializer_list<T> l)
{
    c.clear();
    c.reserve(l.size());
    for (const auto &x : l)
        c.emplace_back(x);
}

template <typename C, typename T>
C create(std::initializer_list<T> l)
{
    C res;
    emfill(res, l);
    return res;
}

void test::test_no_copy()
{
    using std::vector;
    std::vector<NoCopy> a;
    a.reserve(5);
    emfill(a, {1, 2, 3, 4, 5});

    auto b = create<std::vector<NoCopy>>({11, 12, 13, 14});

    try
    {
        concatenation<vector<NoCopy>> j(a, b);
        for (auto &x : j)
        {
            std::cout << x << " ";
        }
    }
    catch (std::exception &e)
    {
        cout << "*** " << e.what() << "\n";
    }
}

// int main()
// {
//     try
//     {
//         cout << "The following call should not throw.\n";
//         test_no_copy();
//     }
//     catch (std::exception &e)
//     {
//         cout << "*** " << e.what() << "\n";
//         cout << "Test failed\n";
//     }
// }