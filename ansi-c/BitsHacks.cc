// http://graphics.stanford.edu/~seander/bithacks.html
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

///////////////////// Compute the sign of an integer //////////////////////////

int v;      // we want to find the sign of v
int sign;   // the result goes here 

// CHAR_BIT is the number of bits per byte (normally 8).
sign = -(v < 0);  // if v < 0 then -1, else 0. 
// or, to avoid branching on CPUs with flag registers (IA32):
sign = -(int)((unsigned int)((int)v) >> (sizeof(int) * CHAR_BIT - 1));
// or, for one less instruction (but not portable):
sign = v >> (sizeof(int) * CHAR_BIT - 1); 
sign = +1 | (v >> (sizeof(int) * CHAR_BIT - 1));  // if v < 0 then -1, else +1

sign = (v != 0) | -(int)((unsigned int)((int)v) >> (sizeof(int) * CHAR_BIT - 1));
// Or, for more speed but less portability:
sign = (v != 0) | (v >> (sizeof(int) * CHAR_BIT - 1));  // -1, 0, or +1
// Or, for portability, brevity, and (perhaps) speed:
sign = (v > 0) - (v < 0); // -1, 0, or +1
///////////////////////////////////////////////////////////////////////////////


///////////////////// Detect if two integers have opposite signs /////////////
int x, y;               // input values to compare signs
bool f = ((x ^ y) < 0); // true iff x and y have opposite signs
///////////////////////////////////////////////////////////////////////////////


//////// Compute the integer absolute value (abs) without branching ///////////
int v;           // we want to find the absolute value of v
unsigned int r;  // the result goes here 
int const mask = v >> sizeof(int) * CHAR_BIT - 1;
r = (v + mask) ^ mask;
///////////////////////////////////////////////////////////////////////////////


///////////////////// Compute the minimum (min) or maximum (max) of two integers without branching /////////////
int x;  // we want to find the minimum of x and y
int y;   
int r;  // the result goes here 
r = y ^ ((x ^ y) & -(x < y)); // min(x, y)
r = x ^ ((x ^ y) & -(x < y)); // max(x, y)
///////////////////////////////////////////////////////////////////////////////


///////////////////// Determining if an integer is a power of 2 ///////////////
unsigned int v; // we want to see if v is a power of 2
bool f;         // the result goes here 
f = (v & (v - 1)) == 0;
///////////////////////////////////////////////////////////////////////////////


///////////////////// Sign extending from a constant bit-width ////////////////
int x; // convert this from using 5 bits to a full int
int r; // resulting sign extended number goes here
struct {signed int x:5;} s;
r = s.x = x;
///////////////////////////////////////////////////////////////////////////////


///////////////////// Sign extending from a variable bit-width ////////////////
unsigned b; // number of bits representing the number in x
int x;      // sign extend this b-bit number to r
int r;      // resulting sign-extended number
int const m = 1U << (b - 1); // mask can be pre-computed if b is fixed
x = x & ((1U << b) - 1);  // (Skip this if bits in x above position b are already zero.)
r = (x ^ m) - m;
///////////////////////////////////////////////////////////////////////////////


///////////////////// Sign extending from a variable bit-width in 3 operations /////////////
unsigned b; // number of bits representing the number in x
int x;      // sign extend this b-bit number to r
int r;      // resulting sign-extended number
#define M(B) (1U << ((sizeof(x) * CHAR_BIT) - B)) // CHAR_BIT=bits/byte
static int const multipliers[] = 
{
  0,     M(1),  M(2),  M(3),  M(4),  M(5),  M(6),  M(7),
  M(8),  M(9),  M(10), M(11), M(12), M(13), M(14), M(15),
  M(16), M(17), M(18), M(19), M(20), M(21), M(22), M(23),
  M(24), M(25), M(26), M(27), M(28), M(29), M(30), M(31),
  M(32)
}; // (add more if using more than 64 bits)
static int const divisors[] = 
{
  1,    ~M(1),  M(2),  M(3),  M(4),  M(5),  M(6),  M(7),
  M(8),  M(9),  M(10), M(11), M(12), M(13), M(14), M(15),
  M(16), M(17), M(18), M(19), M(20), M(21), M(22), M(23),
  M(24), M(25), M(26), M(27), M(28), M(29), M(30), M(31),
  M(32)
}; // (add more for 64 bits)
#undef M
r = (x * multipliers[b]) / divisors[b];
///////////////////////////////////////////////////////////////////////////////


///////////////////// Conditionally set or clear bits without branching /////////////
bool f;         // conditional flag
unsigned int m; // the bit mask
unsigned int w; // the word to modify:  if (f) w |= m; else w &= ~m; 

w ^= (-f ^ w) & m;

// OR, for superscalar CPUs:
w = (w & ~m) | (-f & m);
///////////////////////////////////////////////////////////////////////////////


///////////////////// Conditionally negate a value without branching //////////
bool fDontNegate;  // Flag indicating we should not negate v.
int v;             // Input value to negate if fDontNegate is false.
int r;             // result = fDontNegate ? v : -v;

r = (fDontNegate ^ (fDontNegate - 1)) * v;
///////////////////////////////////////////////////////////////////////////////


///////////////////// Merge bits from two values according to a mask //////////
unsigned int a;    // value to merge in non-masked bits
unsigned int b;    // value to merge in masked bits
unsigned int mask; // 1 where bits from b should be selected; 0 where from a.
unsigned int r;    // result of (a & ~mask) | (b & mask) goes here

r = a ^ ((a ^ b) & mask); 
///////////////////////////////////////////////////////////////////////////////


///////////////////// Counting bits set (naive way) ///////////////////////////
unsigned int v; // count the number of bits set in v
unsigned int c; // c accumulates the total bits set in v

for (c = 0; v; v >>= 1)
{
  c += v & 1;
}
///////////////////////////////////////////////////////////////////////////////


///////////////////// Counting bits set by lookup table ///////////////////////
static const unsigned char BitsSetTable256[256] = 
{
#   define B2(n) n,     n+1,     n+1,     n+2
#   define B4(n) B2(n), B2(n+1), B2(n+1), B2(n+2)
#   define B6(n) B4(n), B4(n+1), B4(n+1), B4(n+2)
    B6(0), B6(1), B6(1), B6(2)
};

unsigned int v; // count the number of bits set in 32-bit value v
unsigned int c; // c is the total bits set in v

// Option 1:
c = BitsSetTable256[v & 0xff] + 
    BitsSetTable256[(v >> 8) & 0xff] + 
    BitsSetTable256[(v >> 16) & 0xff] + 
    BitsSetTable256[v >> 24]; 

// Option 2:
unsigned char * p = (unsigned char *) &v;
c = BitsSetTable256[p[0]] + 
    BitsSetTable256[p[1]] + 
    BitsSetTable256[p[2]] + 
    BitsSetTable256[p[3]];


// To initially generate the table algorithmically:
BitsSetTable256[0] = 0;
for (int i = 0; i < 256; i++)
{
  BitsSetTable256[i] = (i & 1) + BitsSetTable256[i / 2];
}
///////////////////////////////////////////////////////////////////////////////


///////////////////// Counting bits set, Brian Kernighan's way ////////////////
unsigned int v; // count the number of bits set in v
unsigned int c; // c accumulates the total bits set in v
for (c = 0; v; c++)
{
  v &= v - 1; // clear the least significant bit set
}
///////////////////////////////////////////////////////////////////////////////


///////////////////// Counting bits set in 14, 24, or 32-bit words using 64-bit instructions /////////////
unsigned int v; // count the number of bits set in v
unsigned int c; // c accumulates the total bits set in v

// option 1, for at most 14-bit values in v:
c = (v * 0x200040008001ULL & 0x111111111111111ULL) % 0xf;

// option 2, for at most 24-bit values in v:
c =  ((v & 0xfff) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
c += (((v & 0xfff000) >> 12) * 0x1001001001001ULL & 0x84210842108421ULL) 
     % 0x1f;

// option 3, for at most 32-bit values in v:
c =  ((v & 0xfff) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
c += (((v & 0xfff000) >> 12) * 0x1001001001001ULL & 0x84210842108421ULL) % 
     0x1f;
c += ((v >> 24) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
///////////////////////////////////////////////////////////////////////////////


///////////////// Counting bits set, in parallel  /////////////////////////////
unsigned int v; // count bits set in this (32-bit value)
unsigned int c; // store the total here
static const int S[] = {1, 2, 4, 8, 16}; // Magic Binary Numbers
static const int B[] = {0x55555555, 0x33333333, 0x0F0F0F0F, 0x00FF00FF, 0x0000FFFF};

c = v - ((v >> 1) & B[0]);
c = ((c >> S[1]) & B[1]) + (c & B[1]);
c = ((c >> S[2]) + c) & B[2];
c = ((c >> S[3]) + c) & B[3];
c = ((c >> S[4]) + c) & B[4];
///////////////////////////////////////////////////////////////////////////////


///////////////// Count bits set (rank) from the most-significant bit upto a given position  //////////////////////
uint64_t v;       // Compute the rank (bits set) in v from the MSB to pos.
unsigned int pos; // Bit position to count bits upto.
uint64_t r;       // Resulting rank of bit at pos goes here.

// Shift out bits after given position.
r = v >> (sizeof(v) * CHAR_BIT - pos);
// Count set bits in parallel.
// r = (r & 0x5555...) + ((r >> 1) & 0x5555...);
r = r - ((r >> 1) & ~0UL/3);
// r = (r & 0x3333...) + ((r >> 2) & 0x3333...);
r = (r & ~0UL/5) + ((r >> 2) & ~0UL/5);
// r = (r & 0x0f0f...) + ((r >> 4) & 0x0f0f...);
r = (r + (r >> 4)) & ~0UL/17;
// r = r % 255;
r = (r * (~0UL/255)) >> ((sizeof(v) - 1) * CHAR_BIT);
///////////////////////////////////////////////////////////////////////////////


///////////////// Select the bit position (from the most-significant bit) with the given count (rank)  //////////////////////
uint64_t v;          // Input value to find position with rank r.
unsigned int r;      // Input: bit's desired rank [1-64].
unsigned int s;      // Output: Resulting position of bit with rank r [1-64]
uint64_t a, b, c, d; // Intermediate temporaries for bit count.
unsigned int t;      // Bit count temporary.

// Do a normal parallel bit count for a 64-bit integer,                     
// but store all intermediate steps.                                        
// a = (v & 0x5555...) + ((v >> 1) & 0x5555...);
a =  v - ((v >> 1) & ~0UL/3);
// b = (a & 0x3333...) + ((a >> 2) & 0x3333...);
b = (a & ~0UL/5) + ((a >> 2) & ~0UL/5);
// c = (b & 0x0f0f...) + ((b >> 4) & 0x0f0f...);
c = (b + (b >> 4)) & ~0UL/0x11;
// d = (c & 0x00ff...) + ((c >> 8) & 0x00ff...);
d = (c + (c >> 8)) & ~0UL/0x101;
t = (d >> 32) + (d >> 48);
// Now do branchless select!                                                
s  = 64;
// if (r > t) {s -= 32; r -= t;}
s -= ((t - r) & 256) >> 3; r -= (t & ((t - r) >> 8));
t  = (d >> (s - 16)) & 0xff;
// if (r > t) {s -= 16; r -= t;}
s -= ((t - r) & 256) >> 4; r -= (t & ((t - r) >> 8));
t  = (c >> (s - 8)) & 0xf;
// if (r > t) {s -= 8; r -= t;}
s -= ((t - r) & 256) >> 5; r -= (t & ((t - r) >> 8));
t  = (b >> (s - 4)) & 0x7;
// if (r > t) {s -= 4; r -= t;}
s -= ((t - r) & 256) >> 6; r -= (t & ((t - r) >> 8));
t  = (a >> (s - 2)) & 0x3;
// if (r > t) {s -= 2; r -= t;}
s -= ((t - r) & 256) >> 7; r -= (t & ((t - r) >> 8));
t  = (v >> (s - 1)) & 0x1;
// if (r > t) s--;
s -= ((t - r) & 256) >> 8;
s = 65 - s;
///////////////////////////////////////////////////////////////////////////////


///////////////// Reverse bits the obvious way ////////////////////////////////
unsigned int v;     // input bits to be reversed
unsigned int r = v; // r will be reversed bits of v; first get LSB of v
int s = sizeof(v) * CHAR_BIT - 1; // extra shift needed at end

for (v >>= 1; v; v >>= 1)
{   
  r <<= 1;
  r |= v & 1;
  s--;
}
r <<= s; // shift when v's highest bits are zero
///////////////////////////////////////////////////////////////////////////////


///////////////// Reverse bits in word by lookup table ////////////////////////
static const unsigned char BitReverseTable256[256] = 
{
#   define R2(n)     n,     n + 2*64,     n + 1*64,     n + 3*64
#   define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16)
#   define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 )
    R6(0), R6(2), R6(1), R6(3)
};

unsigned int v; // reverse 32-bit value, 8 bits at time
unsigned int c; // c will get v reversed

// Option 1:
c = (BitReverseTable256[v & 0xff] << 24) | 
    (BitReverseTable256[(v >> 8) & 0xff] << 16) | 
    (BitReverseTable256[(v >> 16) & 0xff] << 8) |
    (BitReverseTable256[(v >> 24) & 0xff]);

// Option 2:
unsigned char * p = (unsigned char *) &v;
unsigned char * q = (unsigned char *) &c;
q[3] = BitReverseTable256[p[0]]; 
q[2] = BitReverseTable256[p[1]]; 
q[1] = BitReverseTable256[p[2]]; 
q[0] = BitReverseTable256[p[3]];
///////////////////////////////////////////////////////////////////////////////


///////////////// Reverse the bits in a byte with 3 operations (64-bit multiply and modulus division): //////////////////////
unsigned char b; // reverse this (8-bit) byte
 
b = (b * 0x0202020202ULL & 0x010884422010ULL) % 1023;
///////////////////////////////////////////////////////////////////////////////


///////////////// Reverse the bits in a byte with 4 operations (64-bit multiply, no division): //////////////////////
b = ((b * 0x80200802ULL) & 0x0884422110ULL) * 0x0101010101ULL >> 32;
///////////////////////////////////////////////////////////////////////////////


///////////////// Reverse the bits in a byte with 7 operations (no 64-bit):  //////////////////////
b = ((b * 0x0802LU & 0x22110LU) | (b * 0x8020LU & 0x88440LU)) * 0x10101LU >> 16; 
///////////////////////////////////////////////////////////////////////////////


///////////////// Reverse an N-bit quantity in parallel in 5 * lg(N) operations: //////////////////////
unsigned int v; // 32-bit word to reverse bit order

// swap odd and even bits
v = ((v >> 1) & 0x55555555) | ((v & 0x55555555) << 1);
// swap consecutive pairs
v = ((v >> 2) & 0x33333333) | ((v & 0x33333333) << 2);
// swap nibbles ... 
v = ((v >> 4) & 0x0F0F0F0F) | ((v & 0x0F0F0F0F) << 4);
// swap bytes
v = ((v >> 8) & 0x00FF00FF) | ((v & 0x00FF00FF) << 8);
// swap 2-byte long pairs
v = ( v >> 16             ) | ( v               << 16);
///////////////////////////////////////////////////////////////////////////////


///////////////// Compute modulus division by 1 << s without a division operator //////////////////////
const unsigned int n;          // numerator
const unsigned int s;
const unsigned int d = 1U << s; // So d will be one of: 1, 2, 4, 8, 16, 32, ...
unsigned int m;                // m will be n % d
m = n & (d - 1); 
///////////////////////////////////////////////////////////////////////////////


///////////////// Find the log base 2 of an integer with the MSB N set in O(N) operations (the obvious way) //////////////////////
unsigned int v; // 32-bit word to find the log base 2 of
unsigned int r = 0; // r will be lg(v)

while (v >>= 1) // unroll for more speed...
{
  r++;
}
///////////////////////////////////////////////////////////////////////////////


///////////////// Find the log base 2 of an integer with a lookup table //////////////////////
static const char LogTable256[256] = 
{
#define LT(n) n, n, n, n, n, n, n, n, n, n, n, n, n, n, n, n
    -1, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
    LT(4), LT(5), LT(5), LT(6), LT(6), LT(6), LT(6),
    LT(7), LT(7), LT(7), LT(7), LT(7), LT(7), LT(7), LT(7)
};

unsigned int v; // 32-bit word to find the log of
unsigned r;     // r will be lg(v)
register unsigned int t, tt; // temporaries

if (tt = v >> 16) {
  r = (t = tt >> 8) ? 24 + LogTable256[t] : 16 + LogTable256[tt];
} else {
  r = (t = v >> 8) ? 8 + LogTable256[t] : LogTable256[v];
}
///////////////////////////////////////////////////////////////////////////////


///////////////// Round up to the next highest power of 2 /////////////////////
v--;
v |= v >> 1;
v |= v >> 2;
v |= v >> 4;
v |= v >> 8;
v |= v >> 16;
v++;
///////////////////////////////////////////////////////////////////////////////

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
