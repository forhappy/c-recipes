#include <stdio.h>
#include <stdlib.h>

int divide(int dividend, int divisor) {
    if (divisor == 1) return dividend;
    if (dividend > 0 && dividend < divisor) return 0;
    else if (dividend > 0 && divisor > 0) {
        return divide(dividend - divisor, divisor) + 1;
    } else if (dividend < 0 && divisor > 0) {
        return -divide(-dividend, divisor);
    } else if (dividend > 0 && divisor < 0) {
        return -divide(dividend, -divisor);
    } else {
        return divide(-dividend, -divisor);
    }
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    printf("%d\n", divide(7, 5));
    printf("%d\n", divide(7, 2));
    printf("%d\n", divide(7, -5));
    printf("%d\n", divide(7, -15));
    printf("%d\n", divide(-7, -15));
    printf("%d\n", divide(-7, -2));

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */

