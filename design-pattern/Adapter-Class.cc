
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include <boost/shared_ptr.hpp>

class Target {
public:
    virtual void Request() = 0;
};

class Adaptee {
public:
    void SpecialRequest() {
        std::cout << "This is a special request." << std::endl;
    }
};

class Adapter: public Target, private Adaptee {
    virtual void Request() {
        SpecialRequest();
    }
};

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    boost::shared_ptr<Target> target(new Adapter());
    target->Request();
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
