// Given a string, a cut of the string is a palindrome partitioning
// if every substring of the partition is a palindrome.
#include <climits>
#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

bool IsPalindrome(const std::string& src) {
    if (src.size() == 0 || src.size() == 1 ) return true;

    std::string::size_type front = 0, back = src.length() - 1;
    while(front <= back) {
        if (src[front] != src[back]) return false;
        front++, back--;
    }
    return true;
}

int PalindromeCuts(const std::string& src) {
    if (src.empty()) return 0;

    size_t src_len = src.size();
    std::vector<std::vector<int> > aux_table(src_len,
            std::vector<int>(src_len));

    for (int i = 0; i < src_len; i++) {
        aux_table[i][i] = 0;
        if (i + 1 < src_len) {
            if (src[i] == src[i + 1]) aux_table[i][i + 1] = 0;
            else aux_table[i][i + 1] = 1;
        }
    }

    for (int gap = 2; gap < src_len; gap++) {
        for (int i = 0; i < src_len - gap; i++) {
            if (IsPalindrome(src.substr(i, gap))) {
                aux_table[i][i + gap] = 0;
            } else {
                int current_min_cuts = INT_MAX;
                for (int k = i; k < i + gap; k++) {
                    int current_cuts = aux_table[i][k]
                        + aux_table[k + 1][i + gap] + 1;
                    if (current_min_cuts >= current_cuts)
                        current_min_cuts = current_cuts;
                }
                aux_table[i][i + gap] = current_min_cuts;
            }
        }
    }

    return aux_table[0][src_len - 1];
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::cout << PalindromeCuts("abc") << std::endl;
    std::cout << PalindromeCuts("abccba") << std::endl;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
