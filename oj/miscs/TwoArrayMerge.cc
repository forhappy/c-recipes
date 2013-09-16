
#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <algorithm>
#include <iostream>


std::vector<int> merge(const std::vector<int>& first,
        const std::vector<int>& second)
{
    if (first.empty()) return second;
    if (second.empty()) {
        std::vector<int> result(first);
        std::reverse(result.begin(), result.end());
        return result;
    }

    std::vector<int> result;
    std::vector<int>::const_reverse_iterator first_it = first.crbegin();
    std::vector<int>::const_iterator second_it = second.begin();

    while(true) {
        if (first_it != first.crend() && second_it != second.end()) {
            if (*first_it < *second_it) {
                result.push_back(*first_it);
                first_it++;
            } else {
                result.push_back(*second_it);
                second_it++;
            }
        } else if (first_it == first.crend() && second_it != second.end()) {
            result.push_back(*second_it);
            second_it++;
        } else if (first_it != first.crend() && second_it == second.end()) {
            result.push_back(*first_it);
            first_it++;
        } else break;

    }

    return result;
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    // std::vector<int> first = {60, 50, 30, 20, 10, 5, 4};
    std::vector<int> first = {};
    std::vector<int> second = {1, 4, 5, 6, 7, 8, 9};
    // std::vector<int> second = {};

    std::vector<int> result = merge(first, second);

    for_each(result.begin(), result.end(), [](int i) { std::cout << i << " "; });
    std::cout << std::endl;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
