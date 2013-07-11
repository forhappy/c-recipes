// find_first_of example
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>

bool comp_case_insensitive(char c1, char c2) {
    return (tolower(c1) == tolower(c2));
}

int main () {
    int mychars[] = {'a', 'b', 'c', 'A', 'B', 'C'};
    std::vector<char> myvector(mychars, mychars+6);
    std::vector<char>::iterator it;

    int match[] = {'A', 'B', 'C'};

    // using default comparison:
    it = std::find_first_of(myvector.begin(), myvector.end(), match, match + 3);

    if (it != myvector.end())
        std::cout << "first match is: " << *it << std::endl;

    // using predicate comparison:
    it = std::find_first_of(myvector.begin(), myvector.end(),
                        match, match+3, comp_case_insensitive);

    if (it != myvector.end())
        std::cout << "first match is: " << *it << std::endl;

    return 0;
}
