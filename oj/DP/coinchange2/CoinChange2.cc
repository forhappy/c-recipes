// Given a value N, if we want to make change for N cents,
// and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins,
// how many ways can we make the change?
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>


// const std::vector<size_t> kCoinValue = {1, 2, 5, 10, 50, 100};
const std::vector<int> kCoinValue = {1, 2, 3, 5, 7, 11};

int MakeChange(int total) {
    int coin_value_table_size = kCoinValue.size();

    std::vector<std::vector<int> > aux_table(total + 1,
            std::vector<int>(coin_value_table_size));

    for (int i = 0; i < coin_value_table_size; i++) {
        aux_table[0][i] = 1;
    }

    for (int i = 1; i <= total; i++) {
        for (int j = 0; j < coin_value_table_size; j++) {
            int x = 0, y = 0;

            if (i >= kCoinValue[j]) x = aux_table[i - kCoinValue[j]][j];
            if (j >= 1) y = aux_table[i][j - 1];

            aux_table[i][j] = x + y;
        }
    }

    return aux_table[total][coin_value_table_size - 1];
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::cout << MakeChange(4) << std::endl;
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
