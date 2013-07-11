// find_end example
#include <iostream>
#include <algorithm>
#include <vector>

bool myfunction(int i, int j) {
    return (i == j);
}

int main () {
    int myints[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    std::vector<int> myvector(myints, myints + 10);
    std::vector<int>::iterator it;

    int match1[] = {1, 2, 2};

    // using default comparison:
    it = std::find_end(myvector.begin(), myvector.end(), match1, match1 + 3);

    if (it != myvector.end()) {
        std::cout << "match1 last found at position " << int(it - myvector.begin()) << std::endl;
        std::cout << *it << std::endl;
    }

    int match2[] = {4,5,1};

    // using predicate comparison:
    it = std::find_end(myvector.begin(), myvector.end(), match2, match2 + 3, myfunction);

    if (it != myvector.end()) {
        std::cout << "match2 last found at position " << int(it - myvector.begin()) << std::endl;
        std::cout << *it << std::endl;
    }

    return 0;
}
