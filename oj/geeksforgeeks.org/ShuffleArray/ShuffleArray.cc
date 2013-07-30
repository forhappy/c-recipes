// Given an array, write a program to generate a random permutation of array
// elements. This question is also asked as "shuffle a deck of cards" or
// "randomize a given array".
//
#include<cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <iostream>
#include <vector>

void ShuffleArray(std::vector<int>& arr) {
    assert(arr.size() != 0);

    srand(time(0));
    for (int i = arr.size() - 1; i >=1; i--) {
        int j = rand() % (i + 1);
        std::swap(arr[i], arr[j]);
    }
    return;
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ShuffleArray(arr);

    for_each(arr.begin(), arr.end(), [] (int i) {
            std::cout << i << "\t" << std::endl;
            });

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
