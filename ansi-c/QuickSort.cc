/*
 * ========================================================================
 *
 *       Filename:  QuickSort.cc
 *
 *    Description:  dummy quick sort implementation.
 *
 *        Created:  08/08/2013 10:53:47 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <vector>

int Partition(int arr[], int low, int high)
{
    int x = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= x) {
            i++;
            std::swap(arr[i + 1], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

int Partition2(int arr[], int low, int high)
{
    int x = arr[high];
    int i = low;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= x) {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    std::swap(arr[i], arr[high]);
    return i;
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high) {
        int p = Partition(arr, low, high);
        QuickSort(arr, low, p - 1);
        QuickSort(arr, p + 1, high);
    }
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    int arr[] = {2, 3, 4, 1, 6, 9, 3, 4, 2, 1, 10};
    QuickSort(arr, 0, 10);
    std::for_each(arr, arr + 10, [] (int i) {std::cout << i << "\t";});
    std::cout << std::endl;
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
