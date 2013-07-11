#include <time.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, const char *argv[]) {
    srand(time(NULL));
    std::vector<int> v;

    for (int i = 0; i < 10000000; i++) {
        v.push_back(rand());
    }

    std::cout << "*************before make heap*************" << std::endl;
    for_each(v.begin(), v.end(), [](int i){ std::cout << i << std::endl; });

    std::cout << "***********heap has been made*************" << std::endl;
    make_heap(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](int i){ std::cout << i << std::endl; });

    std::cout << "********pop one element from heap*********" << std::endl;
    pop_heap(v.begin(), v.end()); v.pop_back();
    for_each(v.begin(), v.end(), [](int i){ std::cout << i << std::endl; });

    std::cout << "********push one element from heap********" << std::endl;
    v.push_back(100); push_heap(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](int i){ std::cout << i << std::endl; });

    std::cout << "****************sort heap*****************" << std::endl;
    sort_heap(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](int i){ std::cout << i << std::endl; });
}
