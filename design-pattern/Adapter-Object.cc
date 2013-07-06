
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

class Adapter: public Target{
public:
    Adapter(boost::shared_ptr<Adaptee> adaptee):
        adaptee_(adaptee) {}

    virtual void Request() {
       adaptee_->SpecialRequest();
    }

private:
    boost::shared_ptr<Adaptee> adaptee_;
};

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    boost::shared_ptr<Adaptee> adaptee(new Adaptee());
    boost::shared_ptr<Target> target(new Adapter(adaptee));
    target->Request();
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
