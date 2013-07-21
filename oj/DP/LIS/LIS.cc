#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int LIS(const std::vector<int> arr) {
    std::for_each(arr.begin(), arr.end(), [](int i) {
        std::cout << i << "\t";
    });
    std::cout << std::endl;
    std::vector<int> aux(arr.size(), 0);
    std::vector<int>::const_iterator it;
    for (it = arr.begin(); it != arr.end(); it++) {
        int curr = it - arr.begin();
        int curr_max = 0, curr_max_pos = 0;
        for (int i = 0; i < curr; i++) {
            if (arr[i] <= arr[curr]) {
                if (arr[i] >= curr_max) {
                    curr_max = arr[i];
                    curr_max_pos = i;
                }
            }
        }
        aux[curr] = aux[curr_max_pos] + 1;
    }
    std::for_each(aux.begin(), aux.end(), [](int i) {
        std::cout << i << "\t";
    });
    std::cout << std::endl;
    return *std::max_element(aux.begin(), aux.end());
}

// binary search.
static int aux_bsearch(int A[], int l, int r, int key) {
    int m;

    while(r - l > 1) {
        m = l + (r - l)/2;
        (A[m] >= key ? r : l) = m;
    }

    return r;
}

int LIS(int A[], int size) {
    // add boundary case, when array size is one

    int *tailTable = new int[size];
    int len; // always points empty slot

    memset(tailTable, 0, sizeof(tailTable[0])*size);

    tailTable[0] = A[0];
    len = 1;
    for(int i = 1; i < size; i++) {
        if( A[i] < tailTable[0] )
            // new smallest value
            tailTable[0] = A[i];
        else if( A[i] > tailTable[len-1] )
            // A[i] wants to extend largest subsequence
            tailTable[len++] = A[i];
        else
            // A[i] wants to be current end candidate of an existing subsequence
            // it will replace ceil value in tailTable
            tailTable[aux_bsearch(tailTable, -1, len-1, A[i])] = A[i];
    }

    std::for_each(tailTable, tailTable + size, [](int i) {
        std::cout << i << "\t";
    });
    std::cout << std::endl;
    delete[] tailTable;

    return len;
}

std::vector<int> LIS2(std::vector<int> arr) {

    std::vector<int> tail_table;
    tail_table.push_back(arr[0]);

    size_t len = 1;
    for(size_t i = 1; i < arr.size(); i++) {
        if( arr[i] < tail_table[0] )
            tail_table[0] = arr[i];
        else if(arr[i] > tail_table[len - 1]) {
            tail_table.push_back(arr[i]);
            len++;
        }
        else
            *std::lower_bound(tail_table.begin(), tail_table.end(), arr[i]) = arr[i];
    }
    return tail_table;
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{

    // std::vector<int> a = {1, 3, 9, 8, 4, 5, 6, 2, 7, 8, 3, 1, 2};
    // int a[] = {1, 2, 3, 1, 4, 5, 3, 6, 8, 7, 3};
    std::vector<int> av = {1, 2, 3, 1, 4, 5, 3, 6, 8, 7, 3, 9};
    // int a[] = {1, 2, 3, 1, 4, 5, 3};
    // int result = LIS(a, sizeof(a) / sizeof(int));

    // std::cout << "LIS: " << result << std::endl;
    std::vector<int> resultv = std::move(LIS2(av));

    std::cout << "Longest increasing subsequence:" << std::endl;
    std::for_each(resultv.begin(), resultv.end(), [](int i) {
        std::cout << i << "\t";
    });

    std::cout << std::endl;
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
