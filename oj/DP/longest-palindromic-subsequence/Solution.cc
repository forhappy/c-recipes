// Given a sequence, find the length of the longest palindromic
// subsequence in it.
//
// Let X[0..n-1] be the input sequence of length n and L(0, n-1) be
// the length of the longest palindromic subsequence of X[0..n-1].
//
// If last and first characters of X are same,
// then L(0, n-1) = L(1, n-2) + 2.
// Else L(0, n-1) = MAX (L(1, n-1), L(0, n-2)).

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>

int LongestPalindromicSubsequence(const std::string& src) {
    if (src.empty()) return 0;

    std::vector<int>::size_type src_len = src.size();
    std::vector<std::vector<int> > aux_table(src_len,
            std::vector<int>(src_len));

    for (int i = 0; i < src_len; i++) {
        aux_table[i][i] = 1;
        if (i + 1 < src_len) {
            if (src[i] == src[i + 1])
                aux_table[i][i + 1] = 2;
            else aux_table[i][i + 1] = 1;
        }
    }

    for (int gap = 2; gap < src_len; gap++) {
        for (int i = 0; i < src_len - gap; i++) {
            if (src[i] == src[i + gap]) aux_table[i][i + gap] =
                aux_table[i + 1][i + gap - 1] + 2;
            else aux_table[i][i + gap] = std::max(aux_table[i][i + gap - 1],
                    aux_table[i + 1][i + gap]);
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
    std::string src1 = "abxcba";
    std::string src2 = "geeks for geeks";

    std::cout << LongestPalindromicSubsequence(src1) << std::endl;
    std::cout << LongestPalindromicSubsequence(src2) << std::endl;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
