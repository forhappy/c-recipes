// Efficient program to calculate e^x.
// e^x = 1 + x/1! + x^2/2! + x^3/3! + ... + x^n/n! + ...
//     = 1 + x/1(1 + x/2(1 + x/3(1 + x/4(...))))
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>

double Exponential(int n, double x)
{
    double sum = 1.0;
    for (int i = n - 1; i > 0; i--) {
        sum = 1 + x * sum / i;
    }
    return sum;
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::cout << Exponential(10, 1) << std::endl;
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
