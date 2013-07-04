
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include <boost/shared_ptr.hpp>

class Component {
public:
    virtual void operation() = 0;
};

class Decorator: public Component {
public:
    Decorator(boost::shared_ptr<Component> component):
        component_(component) {}
    virtual ~Decorator() {}
protected:
    boost::shared_ptr<Component> component_;
};

class ConcreteComponent: public Component {
public:
    virtual void operation() {
        std::cout << "hello, I'm a basic operation" << std::endl;
    }
};

class ConcreteDecoratorV1: public Decorator {
public:
    ConcreteDecoratorV1(boost::shared_ptr<Component> component):
        Decorator(component) {}
    virtual void operation() {
        component_->operation();
        addBehavior();
    }

    void addBehavior() {
        std::cout << "I'm an added operation version 1." << std::endl;
    }

    virtual ~ConcreteDecoratorV1() {}
};

class ConcreteDecoratorV2: public Decorator {
public:
    ConcreteDecoratorV2(boost::shared_ptr<Component> component):
        Decorator(component) {}
    virtual void operation() {
        component_->operation();
        addBehavior();
    }

    void addBehavior() {
        std::cout << "I'm an added operation version 2." << std::endl;
    }

    virtual ~ConcreteDecoratorV2() {}
};

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    boost::shared_ptr<Component> ccptr(new ConcreteComponent);
    boost::shared_ptr<Decorator> cdptr1(new ConcreteDecoratorV1(ccptr));
    boost::shared_ptr<Decorator> cdptr2(new ConcreteDecoratorV2(ccptr));

    std::cout << "====    Using decorator V1. ====" << std::endl;
    cdptr1->operation();

    std::cout << "================================" << std::endl;

    std::cout << "====    Using decorator V2. ====" << std::endl;
    cdptr2->operation();

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
