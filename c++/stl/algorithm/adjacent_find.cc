// adjacent_find example
#include <iostream>
#include <algorithm>
#include <vector>

bool myfunction(int i, int j) {
    return (i == j);
}

int main () {
    int myints[] = {10, 20, 30, 30, 20, 10, 10, 20};
    std::vector<int> myvector(myints,myints+8);
    std::vector<int>::iterator it;

    // using default comparison:
    it = std::adjacent_find(myvector.begin(), myvector.end());

    if (it != myvector.end())
        std::cout << "the first consecutive repeated elements are: " << *it << std::endl;

    //using predicate comparison:
    it = std::adjacent_find(++it, myvector.end(), myfunction);

    if (it != myvector.end())
        std::cout << "the second consecutive repeated elements are: " << *it << std::endl;

    return 0;
}
