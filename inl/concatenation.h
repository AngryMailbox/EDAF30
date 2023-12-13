// concatenation.h
#include "iterator.h"

template <typename T>
class concatenation
{
public:
    using value_type = typename T::value_type;
    using iter = high_level_iterator<typename T::iterator>;

    concatenation(T &ca, T &cb) : container_a(ca), container_b(cb) {}

    iter begin()
    {
        return iter(container_a.begin(), container_b.begin(), container_a.end());
    }

    iter end()
    {
        return iter(container_a.end(), container_b.end(), container_a.end());
    }

private:
    T &container_a;
    T &container_b;
};
