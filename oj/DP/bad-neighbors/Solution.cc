// http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=dynProg
//
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>

int MaxDonations(const std::vector<int>& donations) {
    assert(donations.size() > 0);

    std::vector<int>::size_type donations_table_size = donations.size();
    std::vector<int> aux1(donations_table_size, 0);
    std::vector<int> aux2(donations_table_size, 0);

    aux1[0] = donations[0];
    aux1[1] = donations[0];
    for (int j = 2; j < donations_table_size - 1; j++) {
        aux1[j] = std::max(aux1[j - 2] + donations[j], aux1[j - 1]);
    }

    aux2[0] = 0;
    aux2[1] = donations[1];
    for (int j = 2; j < donations_table_size; j++) {
        aux2[j] = std::max(aux2[j - 2] + donations[j], aux2[j - 1]);
    }

    return std::max(aux1[donations_table_size - 2],
            aux2[donations_table_size - 1]);
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::vector<int> donations1 = {10, 3, 2, 5, 7, 8};
    std::vector<int> donations2 = {11, 15};
    std::vector<int> donations3 = {7, 7, 7, 7, 7, 7, 7};
    std::vector<int> donations4 = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    std::vector<int> donations5 = {94, 40, 49, 65, 21, 21, 106, 80, 92,
        81, 679, 4, 61, 6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61,
        397, 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72};

    std::cout << MaxDonations(donations1) << std::endl;
    std::cout << MaxDonations(donations2) << std::endl;
    std::cout << MaxDonations(donations3) << std::endl;
    std::cout << MaxDonations(donations4) << std::endl;
    std::cout << MaxDonations(donations5) << std::endl;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
