
#include <stdio.h>
#include <stdlib.h>

#include <cstring>
#include <iostream>
#include <algorithm>

int MinSteps(unsigned int n) {
    int r = -1;
    int *memo = new int[n + 1];
    memset(memo, 0, sizeof(int) * n);
    memo[0] = 0, memo[1] = 0;

    for (int i = 2; i <= n; i++) {
        memo[i] = 1 + memo[i - 1];
        if ( i % 2 == 0) memo[i] = std::min(memo[i], 1 + memo[i / 2]);
        if ( i % 3 == 0) memo[i] = std::min(memo[i], 1 + memo[i / 3]);
    }

    r = memo[n];

    delete[] memo;
    return r;
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{

    std::cout << MinSteps(10) << std::endl;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
