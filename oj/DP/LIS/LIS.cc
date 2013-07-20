#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <vector>

int LIS(const std::vector<int> arr) {
    for_each(arr.begin(), arr.end(), [](int i){ std::cout << i << "\t"; });
    std::cout << std::endl;
    std::vector<int> aux(arr.size(), 0);
    std::vector<int>::const_iterator it;
    for (it = arr.begin(); it != arr.end(); it++) {
        int curr = it - arr.begin();
        int curr_max = 0, curr_max_pos = 0;
        for (int i = 0; i < curr; i++) {
            if (arr[i] <= arr[curr]) {
                if (arr[i] >= curr_max) {
                    curr_max = arr[i];
                    curr_max_pos = i;
                }
            }
        }
        aux[curr] = aux[curr_max_pos] + 1;
    }
    for_each(aux.begin(), aux.end(), [](int i){ std::cout << i << "\t"; });
    std::cout << std::endl;
    return *std::max_element(aux.begin(), aux.end());
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{

    // std::vector<int> a = {1, 3, 9, 8, 4, 5, 6, 2, 7, 8, 3, 1, 2};
    std::vector<int> a = {1, 2, 3, 1, 4, 5, 3};
    int result = LIS(a);

    std::cout << "LIS: " << result << std::endl;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
