// find_if example
// g++ -std=c++0x -o find_if find_if.cc
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

bool IsOdd (int i) {
    return ((i % 2) == 1);
}

class IsEven {
public:
    IsEven() {
        std::cout << "Constructor IsEven" << std::endl;
    }

    bool operator()(int i) {
        return ((i % 2) == 0);
    }
};

int main () {
    std::vector<int> myvector;
    std::vector<int>::iterator it;

    for (int i = 0; i < 100; i++) {
        myvector.push_back(i);
    }

    it = find_if(myvector.begin(), myvector.end(), IsOdd);
    std::cout << "The first odd value is " << *it << std::endl;

    it = find_if(myvector.begin(), myvector.end(), IsEven());
    std::cout << "The first even value is " << *it << std::endl;

    it = find_if(myvector.begin(), myvector.end(),
            [](int i)->bool { if (i == 2) return true; else return false; });
    std::cout << "The first 2 is " << *it << std::endl;

  return 0;
}
