
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <algorithm>

#include <boost/scoped_array.hpp>

int LCS(const int* target, size_t tlen,
        const int* source, size_t slen ) {
    size_t lcs = 0;
    boost::scoped_array<int> lcs_ptr(new int[slen * tlen]);
    bool first_matched_flags = false;

    for (size_t i = 0; i < tlen; i++) {
        if (source[0] == target[i] || first_matched_flags == true) {
            lcs_ptr[i] = 1;
            first_matched_flags = true;
        }
    }

    first_matched_flags = false;
    for (size_t i = 0; i < slen; i++) {
        if (target[0] == source[i] || first_matched_flags == true) {
            lcs_ptr[i * tlen] = 1;
        }
    }

    for (size_t s = 1; s < tlen; s++) {
        for (size_t t = 1; t < slen; t++) {
            if (target[t] == source[s])
                lcs_ptr[(s * tlen) + t] = lcs_ptr[(s - 1) * tlen + (t - 1)] + 1;
            else {
                lcs_ptr[(s * tlen) + t] =
                    std::max(lcs_ptr[(s - 1) * tlen + t], lcs_ptr[s * tlen + t - 1]);
            }
        }
    }
    lcs = lcs_ptr[(slen - 1) * tlen + slen - 1];

    return lcs;

}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    int target[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int source1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int source2[] = {4, 7, 2, 3, 10, 6, 9, 1, 5, 8};
    int source3[] = {3, 1, 2, 4, 9, 5, 10, 6, 8, 7};
    int source4[] = {2, 10, 1, 3, 8, 4, 9, 5, 7, 6};
    int source5[] = {2};
    int source6[] = {2, 3};
    int source7[] = {2, 3, 4};
    int source8[] = {2, 3, 5, 4};

    std::cout << LCS(target, 10, source1, 10) << std::endl;
    std::cout << LCS(target, 10, source2, 10) << std::endl;
    std::cout << LCS(target, 10, source3, 10) << std::endl;
    std::cout << LCS(target, 10, source4, 10) << std::endl;
    std::cout << LCS(target, 10, source5, 10) << std::endl;
    std::cout << LCS(target, 10, source6, 10) << std::endl;
    std::cout << LCS(target, 10, source7, 10) << std::endl;
    std::cout << LCS(target, 10, source8, 10) << std::endl;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
