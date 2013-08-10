/*
 * ========================================================================
 *
 *       Filename:  forward_list.cc
 *
 *    Description:  forward_list example.
 *
 *        Created:  08/10/2013 10:33:08 AM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <forward_list>
#include <iostream>
#include <vector>

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    // Constructor.
    std::vector<int> a1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> a2({1, 2, 3, 4, 5, 6, 7, 8, 9});

    std::forward_list<int> fl1;
    std::forward_list<int> fl2(16);
    std::forward_list<int> fl3(16, -1);
    std::forward_list<int> fl4(a1.begin(), a2.end());
    std::forward_list<int> fl5(fl4);
    std::forward_list<int> fl6(std::move(fl5));
    std::forward_list<int> fl7({1, 2, 3, 4, 5, 6, 7, 8});

    // Iterator.
    for_each(fl7.begin(), fl7.end(),
            [] (int i) {std::cout << i << " "; });
    std::cout << std::endl;

    for_each(fl7.cbegin(), fl7.cend(),
            [] (int i) {std::cout << i << " "; });
    std::cout << std::endl;

    // Capacity.
    std::cout << fl7.empty() << std::endl;
    std::cout << fl7.max_size() << std::endl;

    // Element access.
    std::cout << fl7.front() << std::endl;

    // Modifiers.
    fl7.assign(a2.begin(), a2.end());
    for_each(fl7.cbegin(), fl7.cend(),
            [] (int i) {std::cout << i << " "; });
    std::cout << std::endl;

    fl7.assign(16, 2);
    for_each(fl7.cbegin(), fl7.cend(),
            [] (int i) {std::cout << i << " "; });
    std::cout << std::endl;

    fl7.assign({1});
    for_each(fl7.cbegin(), fl7.cend(),
            [] (int i) {std::cout << i << " "; });
    std::cout << std::endl;

    fl7.emplace_front(10);
    fl7.push_front(12);
    fl7.emplace_after(fl7.before_begin(), 12);
    fl7.emplace_after(fl7.before_begin(), 14);
    fl7.insert_after(fl7.before_begin(), 12);
    fl7.erase_after(fl7.before_begin());
    fl7.erase_after(fl7.begin(), fl7.end());
    for_each(fl7.cbegin(), fl7.cend(),
            [] (int i) {std::cout << i << " "; });
    std::cout << std::endl;

    fl7.emplace_after(fl7.before_begin(), 14);
    fl7.resize(16);
    fl7.resize(32, -1);
    for_each(fl7.cbegin(), fl7.cend(),
            [] (int i) {std::cout << i << " "; });
    std::cout << std::endl;
    fl7.clear();

    // Operations.
    fl7.splice_after(fl7.before_begin(), fl3, fl3.begin(), fl3.end());
    fl7.splice_after(fl7.before_begin(), fl3);

    fl7.remove(12);
    fl7.unique();
    fl7.sort();
    fl7.reverse();
    fl7.merge(fl6);

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
