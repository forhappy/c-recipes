// http://www.geeksforgeeks.org/dynamic-programming-set-11-egg-dropping-puzzle
//
//  k ==> Number of floors
//  n ==> Number of Eggs
//  DropEggs(n, k) ==> Minimum number of attempts needed to find the critical
//                    floor in worst case.
//  DropEggs(n, k) = 1 + min{max(DropEggs(n - 1, x - 1), DropEggs(n, k - x)):
//                 x in {1, 2, ..., k}}
//
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>

#include <iostream>
#include <algorithm>
#include <vector>

// n: eggs, k: floors.
int DropEggs(int n, int k) {
    assert(n > 0);
    assert(k >= 0);

    std::vector<std::vector<int> > aux(n + 1, std::vector<int>(k + 1));
    for (int i = 0; i <= k; i++) {
        // we have only one egg, we need i attempts for the i^th floor.
        aux[1][i] = i;
    }

    for (int i = 1; i <= n; i++) {
        // we have eggs > 1, but we need 0 attempts for 0^th floor and
        // 1 attempts for the 1^th floor.
        aux[i][0] = 0;
        aux[i][1] = 1;
    }

    for (int i = 2; i <= n; i++) { // from the 2 eggs to n eggs.
        for (int j = 2; j <= k; j++) { // from the 2^th floor to k^th floor.
            aux[i][j] = INT_MAX;
            int t = 0;
            for (int x = 1; x <= j; x++) {
                t = 1 + std::max(aux[i - 1][x -1], aux[i][j - x]);
                if (t < aux[i][j])
                    aux[i][j] = t;
            }
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
    // n: eggs, k: floors
    int n = 2, k = 36;
    std::cout << DropEggs(n, k) << std::endl;
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
