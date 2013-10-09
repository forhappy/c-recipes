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

template <class ForwardIterator, class T>
ForwardIterator my_upper_bound(ForwardIterator first, ForwardIterator last,
                           const T& val)
{
    ForwardIterator middle;
    typename std::iterator_traits<ForwardIterator>::difference_type len, half;
    len = std::distance(first, last);

    while (len > 0) {
        half = len >> 1;
        middle = first;
        std::advance(middle, half);
        if (val < *middle)
            len = half;
        else {
            first = middle;
            ++first;
            len = len - half - 1;
        }
    }

  return first;
}

template <class ForwardIterator, class T>
ForwardIterator my_lower_bound(ForwardIterator first,
                               ForwardIterator last,
                               const T& val)
{
    ForwardIterator middle;
    typename std::iterator_traits
        <ForwardIterator>::difference_type len, half;
    len = std::distance(first, last);

    while (len > 0) {
        half = len >> 1;
        middle = first;
        std::advance(middle, half);
        if (val <= *middle) {
            len = half;
        } else {
            first = middle;
            ++first;
            len = len - half - 1;
        }
    }

  return first;
}


#include <stdio.h>
#include <stdlib.h>

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    int a[] = {1, 2, 3, 4, 5, 5, 5, 5, 5, 6, 7, 8, 9, 10, 13};
    size_t alen = sizeof(a) / sizeof(a[0]);
    printf("%d\n", a[std::lower_bound(a, a + alen, 11) - a]);
    printf("%d\n", a[my_lower_bound(a, a + alen, 11) - a]);
    printf("%d\n", a[my_upper_bound(a, a + alen, 5) - a - 1]);

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */

