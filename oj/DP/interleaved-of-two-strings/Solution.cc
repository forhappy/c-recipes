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

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    const char* first = "XXZ";
    const char* second = "XXY";
    const char* target = "XXZXXXY";

    std::cout << IsInterLeavedOfTwoStrings(first, second, target) << std::endl;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
