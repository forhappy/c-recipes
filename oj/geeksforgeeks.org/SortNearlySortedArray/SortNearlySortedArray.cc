#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <vector>

const int kMaxDistance = 2;

struct HeapNode {
    int data;
    size_t array_index;
    size_t current_pos;
    size_t next_pos;
    bool operator<(const HeapNode& other) const {
        return data > other.data;
    }
};

void NearlyKInsertionSort(std::vector<int>& arr)
{
    if (arr.empty()) return;

    size_t num_elements = arr.size();
    for (int i = 1; i < num_elements; i++) {
       int current_min = arr[i];
       int j = i -1;
       while(j >= 0 && arr[j] > current_min) {
           arr[j + 1] = arr[j];
           j = j - 1;
       }
       arr[j + 1] = current_min;
    }
}


std::vector<int> NearlyKHeapSort(const std::vector<int>& arr)
{

}


/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::vector<int> arr = {2, 6, 3, 12, 56, 8};
    NearlyKInsertionSort(arr);

    for_each(arr.begin(), arr.end(),[] (int i) {std::cout << i << "\t";});
    std::cout << std::endl;
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
