// Given weights and values of n items, put these items in a knapsack of
// capacity W to get the maximum total value in the knapsack.
// In other words, given two integer arrays val[0..n-1] and wt[0..n-1]
// which represent values and weights associated with n items respectively.
// Also given an integer W which represents knapsack capacity,
// find out the maximum value subset of val[] such that sum of the weights
// of this subset is smaller than or equal to W. You cannot break an item,
// either pick the complete item, or don’t pick it (0-1 property).
#include <cassert>
#include <cstdio>
#include <cstdlib>

#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

int Knapsack(int capacity,
        int items,
        const std::vector<int>& values,
        const std::vector<int>& weights) {
    assert((items == values.size()) && (items == weights.size()));

    std::vector<std::vector<int> > aux_table(capacity + 1,
            std::vector<int>(items));

    {
        for (int i = 0; i <= capacity; i++) {
            if (i < weights[0]) {
                aux_table[i][0] = 0;
            }
            else aux_table[i][0] = values[0];
        }
    }

    for (int i = 0; i < items; i++) {
        aux_table[0][i] = 0;
    }

    for (int c = 1; c <= capacity; c++) {
        for (int i = 1; i < items; i++) {
            if (c < weights[i]) {
                aux_table[c][i] = aux_table[c][i - 1];
            } else {
                aux_table[c][i] = std::max(aux_table[c][i - 1],
                        aux_table[c - weights[i]][i] + values[i]);
            }
        }
    }

    return aux_table[capacity][items - 1];
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    int capacity = 10;
    std::vector<int> weights = {2, 2, 6, 5, 4};
    std::vector<int> values = {6, 3, 5, 4, 6};

    std::cout << Knapsack(capacity, values.size(), values, weights) << std::endl;
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
