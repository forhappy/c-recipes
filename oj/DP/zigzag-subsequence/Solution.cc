// http://community.topcoder.com/stat?c=problem_statement&pm=1259&rd=4493
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>

int LongestZigZagSubsequence(const std::vector<int>& arr) {
    assert(arr.size() > 0);
    if (arr.size() == 1) return 1;
    if (arr.size() == 2 && arr[0] != arr[1]) return 2;

    std::vector<int>::size_type arr_size = arr.size();
    // record the current max zigzag subsuequence length at i^th element.
    std::vector<int> aux(arr_size);
    // recodd the direction of current element and previous element,
    // 1 means the current element is greater than the previous element
    // in this zigzag subsuequence. 0 means the current element is less
    // than the previous element in this zigzag subsuequence.
    std::vector<int> direction(arr_size);

    aux[0] = 1;
    direction[0] = 0;
    if (arr[1] > arr[0]) {
        aux[1] = 2;
        direction[1] = 1;
    } else if (arr[1] < arr[0]) {
        aux[1] = 2;
        direction[1] = 0;
    } else {
        aux[1] = 1;
        direction[1] = 1;
    }

    for (int i = 2; i < arr_size; i++) {
        int current_max_zigzag_subsuequence = 0;
        bool current_direction = 0;
        for (int j = 1; j < i; j++) {
            if (arr[i] > arr[j] && direction[j] == 0) {
                if (aux[j] > current_max_zigzag_subsuequence) {
                    current_max_zigzag_subsuequence = aux[j];
                    current_direction = 1;
                }
            }
            if (arr[i] < arr[j] && direction[j] == 1) {
                if (aux[j] > current_max_zigzag_subsuequence) {
                    current_max_zigzag_subsuequence = aux[j];
                    current_direction = 0;
                }
            }
        }

        aux[i] = current_max_zigzag_subsuequence + 1;
        direction[i] = current_direction;
    }

    return *std::max_element(aux.begin(), aux.end());
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::vector<int> arr1 = { 1, 7, 4, 9, 2, 5 };
    std::vector<int> arr2 = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
    std::vector<int> arr3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::vector<int> arr4 = { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 };
    std::vector<int> arr5 = { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955,
        600, 947, 978, 46, 100, 953, 670, 862, 568, 188,
        67, 669, 810, 704, 52, 861, 49, 640, 370, 908,
        477, 245, 413, 109, 659, 401, 483, 308, 609, 120,
        249, 22, 176, 279, 23, 22, 617, 462, 459, 244 };

    std::cout << LongestZigZagSubsequence(arr1) << std::endl;
    std::cout << LongestZigZagSubsequence(arr2) << std::endl;
    std::cout << LongestZigZagSubsequence(arr3) << std::endl;
    std::cout << LongestZigZagSubsequence(arr4) << std::endl;
    std::cout << LongestZigZagSubsequence(arr5) << std::endl;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
