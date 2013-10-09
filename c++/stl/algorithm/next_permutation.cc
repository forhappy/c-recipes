/*
 * ========================================================================
 *
 *       Filename:  next_permutation.cc
 *
 *    Description:  next_permutation implementation.
 *
 *        Created:  10/09/2013 07:23:58 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

template<typename BidirectionalIterator>
bool my_next_permutation(BidirectionalIterator first,
                         BidirectionalIterator last) {
    if (first == last) return false;

    BidirectionalIterator i = first;
    i++;
    if (i == last) return false;

    i = last;
    i--;
    for (;;) {
        BidirectionalIterator ii = i;
        i--;
        if (*i < *ii) {
            BidirectionalIterator j = last;
            while(!(*i < *--j));
            std::iter_swap(i, j);
            std::reverse(ii, last);
            return true;
        }
        if (i == first) {
            std::reverse(first, last);
            return false;
        }
    }
}

template<typename BidirectionalIterator>
bool my_prev_permutation(BidirectionalIterator first,
                         BidirectionalIterator last) {
    if (first == last) return false;

    BidirectionalIterator i = first;
    i++;
    if (i == last) return false;

    i = last;
    i--;
    for (;;) {
        BidirectionalIterator ii = i;
        i--;
        if (*i > *ii) {
            BidirectionalIterator j = last;
            while(!(*i > *--j));
            std::iter_swap(i, j);
            std::reverse(ii, last);
            return true;
        }
        if (i == first) {
            std::reverse(first, last);
            return false;
        }
    }
}


/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
