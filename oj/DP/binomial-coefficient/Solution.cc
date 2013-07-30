// Write a function that takes two parameters n and k and
// returns the value of Binomial Coefficient C(n, k).
// C(n, k) = C(n-1, k-1) + C(n-1, k)
// C(n, 0) = C(n, n) = 1
//
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>

int BinomialCoefficient(int n, int k) {
    assert(k >= 0);
    assert(n > 0);
    assert(n >= k);

    std::vector<std::vector<int> > aux(n + 1, std::vector<int>(k + 1));
    for (int i = 0; i <= k; i++) {
        aux[0][i] = 0;
    }

    for (int i = 0; i <= n; i++) {
        aux[i][0] = 1;
        if (i <= k) aux[i][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= std::min(i, k); j++) {
            aux[i][j] = aux[i - 1][j - 1] + aux[i - 1][j];
        }
    }

    return aux[n][k];
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::cout << BinomialCoefficient(5, 2) << std::endl;
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
