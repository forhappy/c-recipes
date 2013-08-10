/*
 * ========================================================================
 *
 *       Filename:  deque.cc
 *
 *    Description:  deque example.
 *
 *        Created:  08/10/2013 08:41:39 AM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <deque>
#include <iostream>

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    // Constructor.
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    std::deque<int> dq1;
    std::for_each(dq1.begin(), dq1.end(),
            [] (int i) { std::cout << i << "\t"; });
    std::cout << std::endl;

    std::deque<int> dq2(4);
    std::for_each(dq2.begin(), dq2.end(),
            [] (int i) { std::cout << i << "\t"; });
    std::cout << std::endl;

    std::deque<int> dq3(4, -1);
    std::for_each(dq3.begin(), dq3.end(),
            [] (int i) { std::cout << i << "\t"; });
    std::cout << std::endl;

    std::deque<int> dq4(vec.begin(), vec.end());
    std::for_each(dq4.begin(), dq4.end(),
            [] (int i) { std::cout << i << "\t"; });
    std::cout << std::endl;

    std::deque<int> dq5(dq4);
    std::for_each(dq5.begin(), dq5.end(),
            [] (int i) { std::cout << i << "\t"; });
    std::cout << std::endl;

    std::deque<int> dq6({1, 2, 3, 4, 5});
    std::for_each(dq6.begin(), dq6.end(),
            [] (int i) { std::cout << i << "\t"; });
    std::cout << std::endl;

    std::deque<int> dq7(std::move(dq6));

    std::for_each(dq6.begin(), dq6.end(),
            [] (int i) { std::cout << i << "\t"; });
    std::cout << std::endl;

    std::for_each(dq7.begin(), dq7.end(),
            [] (int i) { std::cout << i << "\t"; });
    std::cout << std::endl;

    // Iterators.
    std::for_each(dq7.begin(), dq7.end(),
            [] (int i) { std::cout << i << "\t"; });
    std::cout << std::endl;

    std::for_each(dq7.rbegin(), dq7.rend(),
            [] (int i) { std::cout << i << "\t"; });
    std::cout << std::endl;

    std::for_each(dq7.cbegin(), dq7.cend(),
            [] (int i) { std::cout << i << "\t"; });
    std::cout << std::endl;

    std::for_each(dq7.crbegin(), dq7.crend(),
            [] (int i) { std::cout << i << "\t"; });
    std::cout << std::endl;

    // Capacity.
    std::cout << "dq7: " << dq7.size() << std::endl;
    std::cout << "dq7: " << dq7.max_size() << std::endl;
    dq7.resize(1);
    std::cout << "dq7: " << dq7.size() << std::endl;
    std::cout << "dq7: " << dq7.empty() << std::endl;
    dq7.shrink_to_fit();

    // Element access.
    std::cout << dq4[1] << dq4[2] << std::endl;
    std::cout << dq4.at(1) << dq4.at(2) << std::endl;
    std::cout << "front: " << dq4.front() << " back: " << dq4.back() << std::endl;

    // Modifiers.
    dq7.assign(16, -1);
    std::for_each(dq7.crbegin(), dq7.crend(),
            [] (int i) { std::cout << i << "\t"; });
    std::cout << std::endl;

    dq7.assign(vec.begin(), vec.end());
    std::for_each(dq7.crbegin(), dq7.crend(),
            [] (int i) { std::cout << i << "\t"; });
    std::cout << std::endl;

    dq7.assign({1, 2, 3, 4, 5});
    std::for_each(dq7.crbegin(), dq7.crend(),
            [] (int i) { std::cout << i << "\t"; });
    std::cout << std::endl;

    dq7.push_back(11111);
    dq7.push_front(11111);
    std::for_each(dq7.crbegin(), dq7.crend(),
            [] (int i) { std::cout << i << "\t"; });
    std::cout << std::endl;

    dq7.pop_back();
    dq7.pop_front();
    std::for_each(dq7.crbegin(), dq7.crend(),
            [] (int i) { std::cout << i << "\t"; });
    std::cout << std::endl;

    dq7.insert(dq7.begin() + 2, 2222);
    dq7.insert(dq7.begin() + 5, 23, 1111);
    dq7.insert(dq7.begin() + 5, vec.begin(), vec.end());
    dq7.insert(dq7.begin() + 5, {1, 4, 42, 42, 42, 4});
    std::for_each(dq7.crbegin(), dq7.crend(),
            [] (int i) { std::cout << i << "\t"; });
    std::cout << std::endl;

    dq7.erase(dq7.begin() + 1);
    dq7.erase(dq7.begin(), dq7.end());
    std::for_each(dq7.begin(), dq7.end(),
            [] (int i) { std::cout << i << "\t"; });
    std::cout << std::endl;

    dq7.clear();
    dq7.emplace_front(1);
    dq7.emplace_front(2);
    dq7.emplace(dq7.begin() + 1, 11);
    std::for_each(dq7.begin(), dq7.end(),
            [] (int i) { std::cout << i << "\t"; });
    std::cout << std::endl;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */

