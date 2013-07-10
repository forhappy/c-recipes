// for_each example
// g++ -std=c++0x -o for_each for_each.cc
#include <ostream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

void myfunction (int i) {
    std::cout << " " << i;
}

struct myclass {
  void operator() (int i) {std::cout << " " << i;}
} myobject;

void printx(std::ostream& os, int i) {
    os << " " << i;
}

int main () {
    std::function<void(int i)> f1 = std::bind(printx,
            std::ref(std::cout), std::placeholders::_1);
    std::function<void(int i)> f2 = std::bind(printx,
            std::reference_wrapper<std::ostream>(std::cout), std::placeholders::_1);

    std::vector<int> myvector;
    myvector.push_back(10);
    myvector.push_back(20);
    myvector.push_back(30);

    std::cout << "myvector contains:";
    for_each(myvector.begin(), myvector.end(), myfunction);

    std::cout << "\nmyvector contains:";
    for_each(myvector.begin(), myvector.end(), myobject);

    std::cout << "\nmyvector contains:";
    for_each(myvector.begin(), myvector.end(), [](int i) { std::cout << " " << i; });

    std::cout << "\nmyvector contains:";
    for_each(myvector.begin(), myvector.end(), f1);

    std::cout << "\nmyvector contains:";
    for_each(myvector.begin(), myvector.end(), f2);

    std::cout << std::endl;

    return 0;
}
