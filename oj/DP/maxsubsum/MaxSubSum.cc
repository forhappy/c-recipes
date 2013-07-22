#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int MaxSubsequenceSum(const std::vector<int>& arr) {
    std::vector<int> max_sum(arr.size());

    max_sum[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        max_sum[i] = std::max(max_sum[i - 1] + arr[i], arr[i]);
    }

    return max_sum[arr.size() - 1];
}


/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::vector<int> arr = {-2, 3, -5, 2, -1, 2, 6, 4, -3, 4};
    std::cout << MaxSubsequenceSum(arr) << std::endl;
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
