// Given an array of n positive integers. Write a program to find the sum
// of maximum sum subsequence of the given array such that the intgers in
// the subsequence are sorted in increasing order.
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>

int MaxSumOfIncreasingSubsequence(const std::vector<int>& v) {
    if (v.empty()) return 0;

    std::vector<int> sum(v.size());
    sum[0] = v[0];

    for (int i = 1; i < v.size(); i++) {
        int current_max_sum = 0;
        for (int j = 0; j < i; j++) {
            if (v[j] <= v[i] && current_max_sum < sum[j]) {
                current_max_sum = sum[j];
            }
        }
        sum[i] = current_max_sum + v[i];
    }

    return *std::max_element(sum.begin(), sum.end());
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::vector<int> v = {1, 2, 7, 3, 6};

    std::cout << MaxSumOfIncreasingSubsequence(v) << std::endl;
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
