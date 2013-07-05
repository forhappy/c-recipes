
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <boost/enable_shared_from_this.hpp>

class Prototype: public boost::enable_shared_from_this<Prototype> {
public:
    virtual boost::shared_ptr<Prototype> Clone() {
        return shared_from_this();
    }

    virtual void func() = 0;
};

class MyObject: public Prototype {
public:
    virtual boost::shared_ptr<Prototype> Clone() {
        return shared_from_this();
    }

    virtual void func() {
        std::cout << "hello prototype" << std::endl;
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
    boost::shared_ptr<Prototype> mo(new MyObject());
    boost::shared_ptr<Prototype> mo2 = mo->Clone();
    mo->func();
    mo2->func();
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
