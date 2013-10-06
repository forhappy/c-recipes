/*
 * ========================================================================
 *
 *       Filename:  Main.cc
 *
 *    Description:  main routine.
 *
 *        Created:  10/05/2013 10:49:03 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */


#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "LRUCache.h"

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    lrucache::LRUCache<int, int> cache(3);

    cache.put(1, 2);
    std::cout << cache.get(1) << std::endl;

    cache.put(11, 22);

    cache.put(111, 222);

    cache.put(1111, 2222);

    std::cout << cache.get(1) << std::endl;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
