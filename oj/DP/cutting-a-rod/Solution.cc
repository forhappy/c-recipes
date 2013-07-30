// Given a rod of length n inches and an array of prices
// that contains prices of all pieces of size smaller than n.
// Determine the maximum value obtainable by cutting up the rod and
// selling the pieces. For example, if length of the rod is 8 and the
// values of different pieces are given as following, then the maximum
// obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)
//
// length   | 1   2   3   4   5   6   7   8
// ----------------------------------------
// price    | 1   5   8   9  10  17  17  20
//
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>

int CuttingRod(size_t rod_length,
        const std::vector<int>& pieces,
        const std::vector<int>& values) {
    assert(pieces.size() == values.size());

    std::vector<int> value_table(rod_length + 1);
    value_table[0] = 0;

    for (int i = 0; i <= rod_length; i++) {
        int current_max_value = 0;
        for (int j = 0; j < pieces.size(); j++) {
            if (i >= pieces[j]) {
                int t = value_table[i - pieces[j]] + values[j];
                if (current_max_value < t) current_max_value = t;
            }
        }
        value_table[i] = current_max_value;
    }
    return value_table[rod_length];
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::vector<int> pieces = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> values = {3, 5, 8, 9, 10, 17, 17, 20};
    std::cout << CuttingRod(8, pieces, values) << std::endl;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
