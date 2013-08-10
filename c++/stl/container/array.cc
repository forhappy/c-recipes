/*
 * ========================================================================
 *
 *       Filename:  array.cc
 *
 *    Description:  array example.
 *
 *        Created:  08/09/2013 11:59:35 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <array>
#include <algorithm>
#include <iostream>

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    // Initialization.
    std::array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::array<int, 10> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


    // Iterator.
    std::for_each(arr.begin(), arr.end(),
            [] (int i) {std::cout << i << "\t";});
    std::cout << std::endl;

    std::for_each(arr.rbegin(), arr.rend(),
            [] (int i) {std::cout << i << "\t";});
    std::cout << std::endl;

    std::for_each(arr.cbegin(), arr.cend(),
            [] (int i) {std::cout << i << "\t";});
    std::cout << std::endl;

    std::for_each(arr.crbegin(), arr.crend(),
            [] (int i) {std::cout << i << "\t";});
    std::cout << std::endl;


    // Capacity.
    std::cout << "array size: " << arr.size() << std::endl;
    std::cout << "array max_size: " << arr.max_size() << std::endl;
    std::cout << "array empty?: " << arr.empty() << std::endl;


    // Element access
    std::cout << arr[1] << arr[2] << arr[3] << std::endl;
    arr[1] = 111;
    arr[2] = 111;
    arr[3] = 111;
    std::cout << arr[1] << arr[2] << arr[3] << std::endl;
    std::cout << "array front: " << arr.front() << " array back: " << arr.back() << std::endl;
    std::cout << *(arr.data() + 2) << std::endl;


    // Modifiers
    arr.fill(2113);
    std::for_each(arr.cbegin(), arr.cend(),
            [] (int i) {std::cout << i << "\t";});
    std::cout << std::endl;

    arr.swap(arr2);
    std::for_each(arr.cbegin(), arr.cend(),
            [] (int i) {std::cout << i << "\t";});
    std::cout << std::endl;


    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
