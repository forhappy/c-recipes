#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>


// const std::vector<size_t> kCoinValue = {1, 2, 5, 10, 50, 100};
const std::vector<size_t> kCoinValue = {1, 2, 3, 5, 7, 11};

int MakeChange(size_t total) {
    std::vector<size_t> min_change(total + 1, UINT_MAX);

    min_change[0] = 0;
    min_change[1] = 1;
    for (size_t i = 2; i <= total; i++) {
        size_t curr_min_change = UINT_MAX;
        for (size_t j = 0; j < kCoinValue.size(); j++) {
            if (i >= kCoinValue[j] && curr_min_change > min_change[i - kCoinValue[j]])
                curr_min_change = min_change[i - kCoinValue[j]];
        }
        min_change[i] = curr_min_change + 1;
    }

    return min_change[total];
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::cout << MakeChange(63) << std::endl;
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
