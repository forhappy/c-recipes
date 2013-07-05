
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include <boost/shared_ptr.hpp>

class AbstractTemplate {
public:
    void Operation() {
        std::cout << "Began Doing Operations." << std::endl;
        PrimitiveOperation1();
        PrimitiveOperation2();
        std::cout << "Finished Doing Operations." << std::endl;
    }

protected:
    virtual void PrimitiveOperation1() {
        std::cout << "Basic Primitive Operation1." << std::endl;
    }

    virtual void PrimitiveOperation2() {
        std::cout << "Basic Primitive Operation2." << std::endl;
    }
};

class ConcreteTemplate: public AbstractTemplate {
protected:
    virtual void PrimitiveOperation1() {
        std::cout << "Refined Primitive Operation1." << std::endl;
    }

    virtual void PrimitiveOperation2() {
        std::cout << "Refined Primitive Operation2." << std::endl;
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
    boost::shared_ptr<AbstractTemplate> at(new ConcreteTemplate());
    at->Operation();
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
