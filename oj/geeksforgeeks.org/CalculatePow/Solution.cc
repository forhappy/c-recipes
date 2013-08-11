// Write a C program to calculate pow(x,n)
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>

#if 1
int Pow(int x, int n)
{
    if (n == 1) return x;
    else if (n % 2 == 0) return Pow(x, n / 2) * Pow(x, n / 2);
    else return x * Pow(x, n / 2) * Pow(x, n / 2);
}
#else
int Pow(int x, int n)
{
    if (n == 0) return 1;
    else if (n % 2 == 0) return Pow(x, n / 2) * Pow(x, n / 2);
    else return x * Pow(x, n / 2) * Pow(x, n / 2);
}
#endif

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::cout << Pow(3, 7) << std::endl;
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
