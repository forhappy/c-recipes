// find example
// g++ -std=c++0x -o find find.cc
#include <iostream>
#include <algorithm>
#include <vector>

int main () {
    int myints[] = {10, 20, 30, 40};
    int * p;

    // pointer to array element:
    p = std::find(myints, myints + 4, 30);
    ++p;
    std::cout << "The element following 30 is " << *p << std::endl;

    std::vector<int> myvector(myints, myints + 4);
    std::vector<int>::iterator it;

    // iterator to vector element:
    it = find(myvector.begin(), myvector.end(), 30);
    ++it;
    std:: cout << "The element following 30 is " << *it << std::endl;

    return 0;
}
