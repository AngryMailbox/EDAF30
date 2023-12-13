// iterator.h
#include <iterator>

template <typename Iterator>
class high_level_iterator
{
public:
    using value_type = typename Iterator::value_type;
    using iterator_category = std::forward_iterator_tag;
    using difference_type = typename Iterator::difference_type;
    using pointer = value_type *;
    using reference = value_type &;

    high_level_iterator(Iterator it_a, Iterator it_b, Iterator end_a)
        : current_iterator_a(it_a), current_iterator_b(it_b), end_iterator_a(end_a) {}

    // operator++
    high_level_iterator &operator++()
    {
        if (current_iterator_a != end_iterator_a)
        {
            ++current_iterator_a;
        }
        else
        {
            ++current_iterator_b;
        }
        return *this;
    }

    // operator++(int)
    high_level_iterator operator++(int)
    {
        high_level_iterator temp = *this;
        ++(*this);
        return temp;
    }

    // operator==(...)
    bool operator==(const high_level_iterator &other) const
    {
        return current_iterator_a == other.current_iterator_a && current_iterator_b == other.current_iterator_b;
    }

    // operator!=(...)
    bool operator!=(const high_level_iterator &other) const
    {
        return !(*this == other);
    }

    // operator*()
    reference operator*() const
    {
        return (current_iterator_a != end_iterator_a) ? *current_iterator_a : *current_iterator_b;
    }

private:
    Iterator current_iterator_a;
    Iterator current_iterator_b;
    Iterator end_iterator_a; // the end iterator of the first container
};
