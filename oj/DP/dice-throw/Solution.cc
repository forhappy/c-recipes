// Given n dice each with m faces, numbered from 1 to m, find the number
// of ways to get sum X. X is the summation of values on each face when
// all the dice are thrown.
//
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>

int DiceThrow(int n, int m, int sum) {
    assert(n > 0);
    assert(m > 0);
    assert(sum > 0);

    if (sum > n * m) return 0;
    if (sum == n * m || sum == n) return 1;
    if (sum < n) return 0;

    std::vector<std::vector<int> > aux(n + 1, std::vector<int>(sum + 1));

    for (int i = 0; i <= sum; i++) {
        aux[0][i] = 0;
        if (i <= m) aux[1][i] = 1;
    }

    for (int i = 0; i <= n; i++) {
        aux[i][0] = 0;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            for (int k = 1; k <= m && k < j; k++) {
                aux[i][j] += aux[i - 1][j - k];
            }
        }
    }

    return aux[n][sum];
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    // const int n = 5, m = 6, sum = 20;
    const int n = 4, m = 2, sum = 5;
    std::cout << DiceThrow(n, m, sum) << std::endl;
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
