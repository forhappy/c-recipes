// Given three strings A, B and C. Write a function that checks whether C
// is an interleaving of A and B. C is said to be interleaving A and B, if
// it contains all characters of A and B and order of all characters in
// individual strings is preserved.
//
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>

bool IsInterLeavedOfTwoStrings(const char* first,
        const char* second, const char* target) {
    if (!(*first || *second || *target)) return true;
    if (*target == '\0') return false;

    return ((*first == *target) && IsInterLeavedOfTwoStrings(first + 1, second, target + 1)) ||
        ((*second == *target) && IsInterLeavedOfTwoStrings(first, second + 1, target + 1));
}

bool IsInterLeavedOfTwoStrings2(const std::string& first,
        const std::string& second, const std::string& target) {
    if (first.empty() && second.empty() && target.empty()) return true;

    std::string::size_type first_size  = first.size();
    std::string::size_type second_size = second.size();
    std::string::size_type target_size = target.size();

    if (first_size + second_size != target_size) return false;
    if (first_size == 0) return !second.compare(target);
    if (second_size == 0) return !first.compare(target);

    std::vector<std::vector<int> > aux(second_size + 1,
            std::vector<int>(first_size + 1));

    aux[0][0] = 0;
    for (int i = 1; i <= first_size; i++) {
        if (target[i - 1] == first[i - 1]) aux[0][i] = 1;
        else aux[0][i] = 0;
    }
    for (int i = 1; i <= second_size; i++) {
        if (target[i - 1] == second[i - 1]) aux[i][0] = 1;
        else aux[i][0] = 0;
    }

    for (int i = 1; i <= second_size; i++) {
        for (int j = 1; j <= first_size; j++) {
            if ((target[i + j - 1] == first[j - 1])
                    && (target[i + j - 1] != second[i - 1])) {
                aux[i][j] = aux[i][j - 1];
            } else if ((target[i + j - 1] != first[j - 1])
                    && (target[i + j - 1] == second[i - 1])) {
                aux[i][j] = aux[i - 1][j];
            } else if ((target[i + j - 1] == first[j - 1])
                    && (target[i + j - 1] == second[i - 1])) {
                aux[i][j] = aux[i][j - 1] || aux[i - 1][j];
            }
        }
    }

    return aux[second_size][first_size];
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    const char* first = "XXZB";
    const char* second = "XXYZ";
    const char* target = "XXZXBXYZ";

    std::cout << IsInterLeavedOfTwoStrings(first, second, target) << std::endl;
    std::cout << IsInterLeavedOfTwoStrings2(first, second, target) << std::endl;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
