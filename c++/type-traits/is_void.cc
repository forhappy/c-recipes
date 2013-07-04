#include <stdio.h>
#include <stdlib.h>

#include <iostream>

template<typename T, T val>
struct integal_constant {
    typedef integal_constant<T, val> type;
    typedef T value_type;
    static const value_type value = val;
};

typedef integal_constant<bool, true> true_type;
typedef integal_constant<bool, false> false_type;

template<typename T>
struct is_void: public false_type {};

template<>
struct is_void<void>: public true_type {};

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    if (is_void<int>::value) 
        std::cout << "OK" << std::endl;
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
