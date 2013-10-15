#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <iterator>

template <class ForwardIterator, class T>
ForwardIterator FindUpperBound(ForwardIterator first,
                               ForwardIterator last,
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
ForwardIterator FindLowerBound(ForwardIterator first,
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
template<typename ForwardIterator, typename Value>
typename std::iterator_traits<ForwardIterator>::difference_type
FindOccurrences(ForwardIterator first,
                ForwardIterator last,
                const Value& value)
{
    ForwardIterator first_occurrence = FindLowerBound(first, last, value);
    ForwardIterator last_occurrence  = FindUpperBound(first, last, value);
    if (*first_occurrence == value
            && *std::prev(last_occurrence) == value) {
        return last_occurrence - first_occurrence;
    } else return last - last;
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    // std::vector<int> A = {1, 2, 3, 4, 4, 5, 6, 8};
    // std::cout << FindOccurrences(A.begin(), A.end(), 8) << std::endl;
    //
    int A[] = {1, 2, 3, 4, 4, 5, 6, 8};
    int len = sizeof(A) / sizeof(A[0]);
    std::cout << FindOccurrences(A, A + len, 4) << std::endl;
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
