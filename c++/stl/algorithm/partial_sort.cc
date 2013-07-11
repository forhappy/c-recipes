// partial_sort example
#include <iostream>
#include <algorithm>
#include <vector>

bool myfunction(int i,int j) {
    return (i < j);
}

int main () {
    int myints[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> myvector(myints, myints + 9);
    std::vector<int>::iterator it;

    // using default comparison (operator <):
    partial_sort(myvector.begin(), myvector.begin()+5, myvector.end());

    // using function as comp
    partial_sort(myvector.begin(), myvector.begin()+5, myvector.end(), myfunction);

    // print out content:
    std::cout << "myvector contains:";
    for (it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << " " << *it;

    std::cout << std::endl;

    return 0;
}
