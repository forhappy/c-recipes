// Given N men and N women, where each person has ranked all members of
// the opposite sex in order of preference, marry the men and women
// together such that there are no two people of opposite sex who would
// both rather have each other than their current partners. If there are
// no such people, all the marriages are “stable” (Source Wiki).
//
// Initialize all men and women to free
//
// while there exist a free man m who still has a woman w to propose to
// {
//    w = m's highest ranked such woman to whom he has not yet proposed
//    if w is free
//       (m, w) become engaged
//    else some pair (m', w) already exists
//       if w prefers m to m'
//          (m, w) become engaged
//           m' becomes free
//       else
//          (m', w) remain engaged
// }
//
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <iostream>
#include <vector>

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
