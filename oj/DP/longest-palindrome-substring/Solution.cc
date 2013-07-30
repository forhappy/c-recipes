// Given a string, find the longest substring which is palindrome.
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>

int LongestPalindromicSubstring(const std::string& src) {
    assert(!src.empty());

    std::string::size_type start = 0;
    std::string::size_type max_palindorme_len = 0;
    std::string::size_type src_len = src.length();
    std::vector<std::vector<int> > aux(src_len, std::vector<int>(src_len));
    for (int i = 0; i < src_len; i++) {
        aux[i][i] = 1;
        if (i + 1 < src_len) {
            if (src[i] == src[i + 1]) {
                aux[i][i + 1] = 1;
                start = i;
                max_palindorme_len = 2;
            }
            else aux[i][i + 1] = 0;
        }
    }

    for (int gap = 2; gap < src_len; gap++) {
        for (int i = 0; i < src_len - gap; i++) {
            if (aux[i + 1][i + gap - 1] == 1 && src[i] == src[i + gap]) {
                aux[i][i + gap] = 1;
                if (max_palindorme_len < gap) {
                    start = i;
                    max_palindorme_len = gap + 1;
                }
            }
        }
    }

    std::cout << src.substr(start, max_palindorme_len) << std::endl;
    return max_palindorme_len;
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::string src1 = "helloll";
    std::string src2 = "hhhhhhhhhlsdkjffjkdslhhh";
    std::cout << LongestPalindromicSubstring(src1) << std::endl;
    std::cout << LongestPalindromicSubstring(src2) << std::endl;
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
