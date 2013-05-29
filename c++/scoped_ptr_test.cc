/*
 * ========================================================================
 *
 *       Filename:  scoped_ptr_test.cc
 *
 *    Description:  scoped_ptr_test.
 *
 *        Created:  05/29/2013 07:45:25 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */
#include "scoped_ptr.h"
 
#include <stdio.h>
#include <stdlib.h>

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    scoped_array<int> pint(new int[10]);
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
