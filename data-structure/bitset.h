/*
 * ========================================================================
 *
 *       Filename:  bitset.h
 *
 *    Description:  bitset implementation in c.
 *
 *        Created:  05/27/2013 11:09:43 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */
#include <limits.h>     /* for CHAR_BIT */

#define BITMASK(b) (1 << ((b) % CHAR_BIT))
#define BITSLOT(b) ((b) / CHAR_BIT)
#define BITSET(a, b) ((a)[BITSLOT(b)] |= BITMASK(b))
#define BITCLEAR(a, b) ((a)[BITSLOT(b)] &= ~BITMASK(b))
#define BITTEST(a, b) ((a)[BITSLOT(b)] & BITMASK(b))
#define BITNSLOTS(nb) ((nb + CHAR_BIT - 1) / CHAR_BIT)
/* 
 * char bitarray[BITNSLOTS(47)];
 * BITSET(bitarray, 23);
 * if(BITTEST(bitarray, 35)) ...
 *
 * */

#include <stdio.h>
#include <string.h>

#define MAX 10000

int main()
{
    char bitarray[BITNSLOTS(MAX)];
    int i, j;

    memset(bitarray, 0, BITNSLOTS(MAX));

    for(i = 2; i < MAX; i++) {
        if(!BITTEST(bitarray, i)) {
            printf("%d\n", i);
            for(j = i + i; j < MAX; j += i)
                BITSET(bitarray, j);
        }
    }
    return 0;
}

