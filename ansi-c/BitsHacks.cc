
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

int SetBit(int x, unsigned char pos) {
    int mask = (1 << pos);
    return x | mask;
}

int ClearBit(int x, unsigned char pos) {
    int mask = (1 << pos);
    return x & ~mask;
}

int ModifyBit(int x, unsigned char pos, bool new_value) {
    int mask = (1 << pos);
    int state = int(new_value);
    return (x & ~mask) | (-state & mask);
}

int FlipBit(int x, unsigned char pos) {
    int mask = 1 << pos;
    return x ^ mask;
}

bool IsBitSet(int x, unsigned char pos) {
    x >>= pos;
    return (x & 1) != 0;
}


int NextPowerOf2(int v) {
    int c = 0;
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    c = ++v;
    return c;
}

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

    std::cout << NextPowerOf2(1000) << std::endl;
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
