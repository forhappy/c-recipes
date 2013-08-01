#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

void AllPermutations(char *src, int start, int end)
{
    if (start == end) {
        std::for_each(src, src + end + 1, [] (char c) { std::cout << c;});
        std::cout << std::endl;
    }
    else {
        for (int j = start; j <= end; j++) {
            std::swap(*(src + start), *(src + j));
            AllPermutations(src, start + 1, end);
            std::swap(*(src + start), *(src + j));
        }
    }
}

int main()
{
   char src[] = "ABC";
   AllPermutations(src, 0, 2);
   return 0;
}
