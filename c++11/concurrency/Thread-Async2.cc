
#include <stdio.h>
#include <stdlib.h>

#include <cmath>
#include <future>
#include <iostream>

std::string ThreadTask(std::string const& s) {
    return s;
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::string s = "hello";
    // std::future<std::string> f(std::async(
    //             std::launch::deferred, ThreadTask, std::ref(s)));

    std::future<std::string> f(std::async(
                std::launch::deferred, ThreadTask, std::ref(s)));
    s = "byebye, ";

    std::cout << s << std::endl;
    std::cout << f.get() << " world" << std::endl;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
