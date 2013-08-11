// Multiply two integers without using multiplication,
// division and bitwise operators, and no loops.
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>

int Multiply(int x, int y)
{
    if (y == 0) return 0;
    if (y > 0) return x + Multiply(x, y - 1);
    else return -Multiply(x, -y);
}
/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::cout << Multiply(4, 5) << std::endl;
    std::cout << Multiply(4, -5) << std::endl;
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
