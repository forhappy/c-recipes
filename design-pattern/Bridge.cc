
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include <boost/shared_ptr.hpp>

class Implementor {
public:
    virtual void OperationImpl() = 0;
};

class ConcreteImplementorV1: public Implementor {
public:
    virtual void OperationImpl() {
        std::cout << "OperationImpl in ConcreteImplementorV1." << std::endl;
    }
};

class ConcreteImplementorV2: public Implementor {
public:
    virtual void OperationImpl() {
        std::cout << "OperationImpl in ConcreteImplementorV2." << std::endl;
    }
};

class Abstraction {
public:
    typedef boost::shared_ptr<Implementor> ImplementorPtr;

    Abstraction(ImplementorPtr implementor): implementor_(implementor) {}

    virtual void Operation() {}

protected:
    ImplementorPtr implementor_;
};

class RefinedAbstraction: public Abstraction {
public:
    RefinedAbstraction(Abstraction::ImplementorPtr implementor):
        Abstraction(implementor) {}

    virtual void Operation() {
        implementor_->OperationImpl();
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
    Abstraction::ImplementorPtr implementor1(new ConcreteImplementorV1());
    boost::shared_ptr<Abstraction> a(new RefinedAbstraction(implementor1));
    a->Operation();

    Abstraction::ImplementorPtr implementor2(new ConcreteImplementorV2());
    a.reset(new RefinedAbstraction(implementor2));
    a->Operation();

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
