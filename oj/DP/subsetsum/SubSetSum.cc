// Given a set of non-negative integers, and a value sum,
// determine if there is a subset of the given set with sum equal to
// given sum.
#include <stdio.h>
#include <stdlib.h>

#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

bool SubSetSum(const std::vector<int>& v, int sum) {

    std::vector<std::vector<int> > aux_table(sum + 1,
            std::vector<int>(v.size() + 1));

    for (int i = 0; i <= v.size(); i++) aux_table[0][i] = 1;
    for (int i = 1; i <= sum; i++) aux_table[i][0] = 0;

    for (int i = 1; i <= sum; i++) {
        for (int j = 1; j <= v.size(); j++) {
            aux_table[i][j] = aux_table[i][j - 1];
            if (i >= v[j - 1])
                aux_table[i][j] = aux_table[i][j] ||
                    aux_table[i - v[j - 1]][j - 1];
        }
    }

    return aux_table[sum][v.size()];

}


/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::vector<int> v = {3, 34, 4, 12, 5, 2};

    std::cout << SubSetSum(v, 51) << std::endl;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
