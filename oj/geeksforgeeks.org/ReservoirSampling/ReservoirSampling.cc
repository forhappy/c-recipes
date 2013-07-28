// Reservoir sampling is a family of randomized algorithms for randomly
// choosing k samples from a list of n items, where n is either a very
// large or unknown number.
//
#include<cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> ReserviorSampling(
        const std::vector<int>& stream,
        size_t sampling_counts) {
    assert(sampling_counts > 0);

    srand(time(NULL));
    std::vector<int> reservior(stream.begin(),
            stream.begin() + sampling_counts);

    for (int i = sampling_counts; i < stream.size(); i++) {
        int index = rand() % (i + 1);
        if (index < sampling_counts)
            reservior[index] = stream[i];
    }

    return reservior;
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::vector<int> stream;
    for (int i = 0; i < 1000000; i++)
        stream.push_back(i);

    const std::vector<int> sampling = ReserviorSampling(stream, 20000);

    for_each(sampling.begin(), sampling.end(),
            [](int i) {std::cout << i << "\t" << std::endl;});

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
