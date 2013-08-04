
#include <stdio.h>
#include <stdlib.h>

#include <cmath>
#include <future>
#include <iostream>

double ThreadTask(int n) {
    std::cout << std::this_thread::get_id()
        << " start computing..." << std::endl;

    double ret = 0;
    for (int i = 0; i <= n; i++) {
        ret += std::sin(i);
    }

    std::cout << std::this_thread::get_id()
        << " finished computing..." << std::endl;
    return ret;
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::future<double> ret1(std::async(ThreadTask, 100000000));
    std::future<double> ret2(std::async(ThreadTask, 10));
    std::future<double> ret3(std::async(ThreadTask, 10000));
    std::future<double> ret4(std::async(ThreadTask, 100000));

    std::cout << ret3.get() << std::endl;
    std::cout << ret2.get() << std::endl;
    std::cout << ret4.get() << std::endl;
    std::cout << ret1.get() << std::endl;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
