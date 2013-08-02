
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    int a = 34;
    int b = 45;
    int v = 55;
    std::cout << (b ^ ((a ^ b) & -(a < b))) << std::endl;
    std::cout << (a ^ ((b ^ a) & -(a < b))) << std::endl;
    std::cout << (v & (v - 1)) << std::endl;

    int c;
    for (c = 0; v; c++) {
        v &= v - 1;
    }

    std::cout << c << std::endl;
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
