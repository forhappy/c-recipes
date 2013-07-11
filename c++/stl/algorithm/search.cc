// search algorithm example
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

bool mypredicate (int i, int j) {
    return (i == j);
}

class MyPredicate {
public:
    bool operator()(int i, int j) {
        if (i == 2 * j) return true;
        else return false;
    }
} predicate_obj;

int main () {
    std::vector<int> myvector;
    std::vector<int>::iterator it;

    // set some values:        myvector: 10 20 30 40 50 60 70 80 90
    for (int i = 1; i < 10; i++) myvector.push_back(i * 10);

    // using default comparison:
    int match1[] = {40, 50, 60, 70};
    it = search(myvector.begin(), myvector.end(), match1, match1 + 4);

    if (it != myvector.end())
        std::cout << "match1 found at position " << int(it - myvector.begin()) << std::endl;
    else
        std::cout << "match1 not found" << std::endl;

    // using predicate comparison:
    int match2[] = {10, 15, 20};
    it = search(myvector.begin(), myvector.end(), match2, match2 + 3, predicate_obj);

    if (it!=myvector.end())
        std::cout << "match2 found at position " << int(it - myvector.begin()) << std::endl;
    else
        std::cout << "match2 not found" << std::endl;

  return 0;
}
