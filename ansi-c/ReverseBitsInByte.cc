/*
 * ========================================================================
 *
 *       Filename:  ReverseBitsInByte.cc
 *
 *    Description:  Reverse bits in byte.
 *
 *        Created:  08/02/2013 09:49:52 AM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */

// http://corner.squareup.com/2013/07/reversing-bits-on-arm.html
#include <cstdio>
#include <cstdlib>

#include <cctype>
#include <cstdint>
#include <climits>

unsigned char ReverseBitsInByte(unsigned char v) {
    return (v * 0x0202020202ULL & 0x010884422010ULL) % 1023;
}

unsigned char ReverseBitsOneByOne(unsigned char v) {
    unsigned char r = v;
    int s = sizeof(v) * CHAR_BIT - 1;
    for (v >>= 1; v; v >>= 1) {
        r <<= 1; r |= v & 1; s--;
    }
    return r << s;
}


#define R2(n)     n,     n + 2*64,     n + 1*64,     n + 3*64
#define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16)
#define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 )

static const unsigned char BitReverseTable256[256] =
{
    R6(0), R6(2), R6(1), R6(3)
};

unsigned char ReverseBitsLookupTable(unsigned char v)
{
    return BitReverseTable256[v];
}


unsigned char ReverseBits4ops64bit(unsigned char v)
{
    return ((v * 0x80200802ULL) & 0x0884422110ULL) * 0x0101010101ULL >> 32;
}


unsigned char ReverseBits7ops32bit(unsigned char v)
{
    return ((v * 0x0802LU & 0x22110LU) |
            (v * 0x8020LU & 0x88440LU)) * 0x10101LU >> 16;
}


unsigned char ReverseBits5logNOps(unsigned char v)
{
    v = ((v >> 1) & 0x55) | ((v & 0x55) << 1);
    v = ((v >> 2) & 0x33) | ((v & 0x33) << 2);
    v = ((v >> 4) & 0x0F) | ((v & 0x0F) << 4);
    return v;
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    unsigned char v = 235;
    unsigned char c1 = ReverseBitsInByte(v);
    unsigned char c2 = ReverseBitsOneByOne(v);
    unsigned char c3 = ReverseBitsLookupTable(v);
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
