
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int MatrixChain(const std::vector<int>& p) {
    if (p.empty() == true) return 0;

    int aux_table_size = p.size() - 1;
    std::vector<std::vector<int> > aux_table(aux_table_size,
            std::vector<int>(aux_table_size));

    for (int i = 0; i < aux_table_size; i++) {
        aux_table[i][i] = 0;
        if (i + 1 < aux_table_size) {
            aux_table[i][i + 1] = p[i] * p[i + 1] * p[i + 2];
        }
    }

    for (int gap = 2; gap < aux_table_size; gap++) {
        for (int i = 0; i < aux_table_size - gap; i++) {
            int current_min_multiplies = INT_MAX;
            for (int j = 0; j < gap; j++) {
                int t = aux_table[i][i + j]
                    + aux_table[i + j + 1][i + gap]
                    + p[i] * p[i + j + 1] * p[i + gap + 1];
                if (t < current_min_multiplies) current_min_multiplies = t;
            }
            aux_table[i][i + gap] = current_min_multiplies;
        }
    }

    return aux_table[0][aux_table_size - 1];
}


/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::vector<int> p = {30, 35, 15, 5, 10, 20, 25};
    std::cout << MatrixChain(p) << std::endl;
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
