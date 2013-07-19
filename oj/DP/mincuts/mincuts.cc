
#include <stdio.h>
#include <stdlib.h>

#include <climits>
#include <iostream>
#include <algorithm>

#include <boost/scoped_array.hpp>

size_t MinCuts(size_t L, const size_t cut_pos[], size_t cut_pos_len) {
    size_t min_cuts = 0;
    boost::scoped_array<int> cut_cost(
            new int[cut_pos_len * cut_pos_len]);

    for (size_t i = 0; i < cut_pos_len; i++) {
        cut_cost[i * cut_pos_len + i] = 0;
    }

    for (size_t i = 0; i < cut_pos_len-1;  i++) {
        cut_cost[i * cut_pos_len + i + 1] = 0;
    }

    for (size_t step = 2; step < cut_pos_len; step++) {
        for (size_t begin_cut = 0; begin_cut < cut_pos_len - step; begin_cut++) {

            size_t outer_min_cut_cost = UINT_MAX;
            for (size_t iter = 1; iter < step; iter++) {
                size_t inner_min_cut_cost =
                    cut_cost[begin_cut * cut_pos_len + (begin_cut + iter)] +
                    cut_cost[(begin_cut + iter) * cut_pos_len + (begin_cut + step)];

                if (inner_min_cut_cost < outer_min_cut_cost)
                    outer_min_cut_cost = inner_min_cut_cost;
            }

            cut_cost[begin_cut * cut_pos_len + begin_cut + step ] =
                outer_min_cut_cost + cut_pos[begin_cut + step] - cut_pos[begin_cut];
        }
    }
    min_cuts = cut_cost[cut_pos_len - 1];

    return min_cuts;
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    size_t L = 10;
    size_t cut_pos[] = {0, 4, 5, 7, 8, 10};
    size_t cut_pos_len = sizeof(cut_pos) / sizeof(int);

    std::cout << MinCuts(L, cut_pos, cut_pos_len) << std::endl;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
