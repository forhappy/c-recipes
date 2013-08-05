/*
 * ========================================================================
 *
 *       Filename:  TestThreadSafeStack.cc
 *
 *    Description:  Test thread-safe stack.
 *
 *        Created:  08/05/2013 09:57:47 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "ThreadSafeStack.h"



/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    ccia::ThreadSafeStack<int> stack;
    stack.push(2);
    stack.push(3);

    stack.pop();
    stack.pop();
    stack.pop();

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
