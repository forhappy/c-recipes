// Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
#include <stdio.h>
#include <stdlib.h>

#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

int FindMinInsertions(const std::string& src) {

    std::vector<std::vector<int> > aux_table(src.length(),
            std::vector<int>(src.length(), 0));

    for (int i = 0; i < aux_table.size(); i++) {
        aux_table[i][i] = 0;
        if (i + 1 < aux_table.size()){
            if (src[i] == src[i + 1])
                aux_table[i][i + 1] = 0;
            else aux_table[i][i + 1] = 1;
        }
    }

    for (int gap = 2; gap < aux_table.size(); gap++) {
        for (int k = 0; k + gap < aux_table.size(); k++) {
            if (src[k] == src[k + gap]) aux_table[k][k + gap] =
                aux_table[k + 1][k + gap - 1];
            else {
                aux_table[k][k + gap] =
                    std::min(aux_table[k + 1][k + gap] + 1,
                            aux_table[k][k  + gap - 1] + 1);
            }
        }
    }

    return aux_table[0][aux_table.size() - 1];
}


/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::string src = "aabcba";

    std::cout << FindMinInsertions(src) << std::endl;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
