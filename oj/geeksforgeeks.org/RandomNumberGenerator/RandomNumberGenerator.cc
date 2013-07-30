// Given n numbers, each with some frequency of occurrence.
// Return a random number with probability proportional to
// its frequency of occurrence.
//
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

int RandomNumberGenerator(const std::vector<int>& arr,
        const std::vector<int>& freq) {
    assert(arr.size() == freq.size());
    std::vector<int>::size_type arr_len = arr.size();

    std::vector<int> prefix(arr_len);
    prefix[0] = freq[0];
    for (int i = 1; i < arr_len; i++) {
        prefix[i] = prefix[i - 1] + freq[i];
    }

    int r = (rand() % prefix[arr_len - 1]) + 1;
    int indexc = std::upper_bound(prefix.begin(), prefix.end(), r - 1)
        - prefix.begin();

    return arr[indexc];
}


/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    const int kNumOfTries = 150000;
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> freq = {1, 2, 3, 4, 5};

    std::map<int, int> freq_map;
    for (int i = 1; i <=arr.size(); i++) {
        freq_map[i] = 0;
    }

//     if (std::upper_bound(arr.begin(), arr.end(), 4) != arr.end())
//        std::cout << "found" << std::endl;
//    else
//        std::cout << "not found" << std::endl;
//    std::cout << *std::upper_bound(arr.begin(), arr.end(), 3) << std::endl;

    srand(time(NULL));

    for (int i = 0; i < kNumOfTries; i++) {
        int random = RandomNumberGenerator(arr, freq);
        freq_map[random] = freq_map[random] + 1;
    }

    for (std::map<int, int>::iterator it = freq_map.begin();
            it != freq_map.end(); it++) {
        std::cout << "Occurrency of " << (*it).first << ": " << (*it).second << std::endl;
    }

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
