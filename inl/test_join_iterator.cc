// test_join_iterator.cc
#include <iostream>
#include <vector>
#include "iterator.h"
#include "test.h"

void test::test_join_iterator()
{
    std::vector<int> a{1, 2, 3, 4, 5};
    std::vector<int> b{6, 7, 8, 9};
    using iter_type = decltype(a.begin());
    high_level_iterator<iter_type> it_begin(a.begin(), b.begin(), a.end());
    high_level_iterator<iter_type> it_end(a.end(), b.end(), a.end());
    for (auto i = it_begin; i != it_end; ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}