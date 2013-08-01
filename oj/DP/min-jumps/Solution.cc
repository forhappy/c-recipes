// Given an array of integers where each element represents the max number
// of steps that can be made forward from that element. Write a function
// to return the minimum number of jumps to reach the end of the array
// (starting from the first element). If an element is 0, then cannot move
// through that element.
//
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>

#include <iostream>
#include <algorithm>
#include <vector>

int MinJumps(const std::vector<int>& arr) {
    assert(arr.size() > 0);

    std::vector<int> aux(arr.size());
    aux[0] = 0;
    for (int i = 1; i < arr.size(); i++) {
        int current_min_jumps = INT_MAX;
        for (int j = 0; j < i; j++) {
            int t = j + arr[j];
            if (t >= i) {
                if (current_min_jumps > aux[j] + 1)
                current_min_jumps = aux[j] + 1;
            }
        }
        aux[i] = current_min_jumps;
    }

    return aux[arr.size() - 1];
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    std::cout << MinJumps(arr) << std::endl;
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
