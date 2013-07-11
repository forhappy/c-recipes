// count_if example
// g++ -std=c++0x -o count_if count_if.cc
#include <iostream>
#include <algorithm>
#include <vector>

bool IsOdd(int i) { return ((i % 2) == 1); }

int main () {
    int mycount;

    std::vector<int> myvector;
    for (int i=1; i < 10; i++) myvector.push_back(i); // myvector: 1 2 3 4 5 6 7 8 9

    mycount = static_cast<int>(count_if(myvector.begin(), myvector.end(), IsOdd));
    std::cout << "myvector contains " << mycount  << " odd values.\n";

    mycount = (int) count_if(myvector.begin(), myvector.end(),
            [](int i)->bool{ if ((i % 3) == 0) return true; else return false; });
    std::cout << "myvector contains " << mycount  << " mod three values.\n";

  return 0;
}
