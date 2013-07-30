// Partition problem is to determine whether a given set can be
// partitioned into two subsets such that the sum of elements in
// both subsets is same.
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>

int CanPatitioned(const std::vector<int>& arr) {
    assert(arr.size() != 0);

    int sumup = 0;
    for_each(arr.begin(), arr.end(), [&sumup] (int i) { sumup += i; });
    if (sumup % 2 == 1) return 0;

    size_t aux_table_column_size = sumup / 2 + 1;
    std::vector<std::vector<int> > aux(arr.size(),
            std::vector<int>(aux_table_column_size));

    for (int current_sum = 0; current_sum < aux_table_column_size;
            current_sum++) {
        if (arr[0] == current_sum) aux[0][current_sum] = 1;
        else aux[0][current_sum] = 0;
    }

    for (int i = 1; i < arr.size(); i++) {
        for (int current_sum = 0; current_sum < aux_table_column_size; current_sum++) {
            if (current_sum > arr[i]) {
                aux[i][current_sum] = aux[i - 1][current_sum] || aux[i - 1][current_sum - arr[i]];
            } else aux[i][current_sum] = aux[i - 1][current_sum];
        }
    }

    int can_patitioned = aux[arr.size() - 1][aux_table_column_size - 1];

    return can_patitioned;
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::vector<int> arr = {1, 2, 9, 4};
    std::vector<int> arr2 = {3, 1, 1, 2, 2, 1};
    std::cout << CanPatitioned(arr) << std::endl;
    std::cout << CanPatitioned(arr2) << std::endl;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
