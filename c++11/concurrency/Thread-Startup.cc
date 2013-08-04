#include <stdio.h>
#include <stdlib.h>

#include <iostream>       // std::cout
#include <thread>         // std::thread

void thread_task() {
    std::cout << "hello thread" << std::endl;
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::thread t(thread_task);
    t.join();

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */

