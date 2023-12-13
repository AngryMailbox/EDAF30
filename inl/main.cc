#include "test.h"

int main()
{
    test t;

    t.test_concatenation();

    t.test_no_copy();

    t.test_join_iterator();

    return 0;
}