/*
 * ========================================================================
 *
 *       Filename:  bitset.cc
 *
 *    Description:  bitset example.
 *
 *        Created:  08/10/2013 08:05:22 AM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <bitset>
#include <iostream>

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    // Construct.
    std::bitset<32> bs1;
    std::bitset<32> bs2(0xffffffff);
    std::bitset<64> bs3(std::string("101000101"));
    std::bitset<64> bs4(std::string("101000101"));

    // Bit access.
    std::cout << bs2[3] << std::endl;
    std::cout << bs2[4] << std::endl;
    std::cout << bs3[4] << std::endl;

    // Bit operations.
    bs3.set();
    std::cout << bs3 << std::endl;
    bs3.set(2, false);
    std::cout << bs3 << std::endl;
    bs3.flip(12);
    std::cout << bs3 << std::endl;
    bs3.flip();
    std::cout << bs3 << std::endl;

    // Bitset operations.
    std::cout << bs2 << std::endl;
    std::cout << bs2.to_ulong() << std::endl;
    std::cout << bs3.to_ulong() << std::endl;
    std::cout << bs2.to_string() << std::endl;
    std::cout << bs3.to_string() << std::endl;

    std::cout << bs3.count() << std::endl;
    std::cout << bs3.size() << std::endl;
    std::cout << bs3.none() << std::endl;
    std::cout << bs3.any() << std::endl;
    std::cout << bs3.test(1) << std::endl;


    // Bitset operators.
    bs3.flip();
    bs3 &= bs4;
    std::cout << bs3 << std::endl;
    bs3 |= bs4;
    std::cout << bs3 << std::endl;
    bs3 ^= bs4;
    std::cout << bs3 << std::endl;
    bs3.flip();
    bs3 <<= 5;
    std::cout << (bs3 << 4) << std::endl;
    std::cout << (bs3 >> 4) << std::endl;
    std::cout << ~bs3 << std::endl;
    std::cout << (bs3 == bs4) << std::endl;
    std::cout << (bs3 != bs4) << std::endl;

    std::bitset<64> bs5 = bs3 & bs4;
    std::bitset<64> bs6 = bs3 | bs4;
    std::bitset<64> bs7 = bs3 ^ bs4;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
