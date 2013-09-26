#include <algorithm>
#include <iterator>

template <class ForwardIterator, class T>
ForwardIterator upper_bound( ForwardIterator first, ForwardIterator last, const T& value )
{
    ForwardIterator it;
    typename std::iterator_traits<ForwardIterator>::difference_type count, step;
    count = std::distance(first, last);
    while (count > 0)
    {
        it = first;
        step=count / 2;
        std::advance(it, step);
        if (!(value < *it)) { // or: if (!comp(value,*it)), for the comp version
            first = ++it; count -= step+1;
        }
        else count = step;
    }
    return first;
}
