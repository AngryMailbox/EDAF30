// test_concatenation.cc
#include <algorithm>
#include <deque>
#include <vector>
#include <iostream>
#include "concatenation.h"
#include "test.h"

void test::test_concatenation()
{
    using IntVector = std::vector<int>;
    IntVector a{1, 2, 3, 4, 5, 6, 7, 8};
    IntVector b{11, 12, 13, 14, 15};
    concatenation<IntVector> j(a, b);

    for (auto &x : j)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    auto first7 = std::find(j.begin(), j.end(), 7);
    auto first12 = std::find(first7, j.end(), 12);
    std::deque<int> result;
    std::copy(first7, first12, std::back_inserter(result));
    std::cout << "result ska nu innehålla {7,8,11}: Innehåller";

    for (auto i : result)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
