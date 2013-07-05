
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include <boost/shared_ptr.hpp>

class AbstractStrategy {
public:
    virtual void operation() = 0;
};

class ConcreteStrategyV1: public AbstractStrategy {
    virtual void operation() {
        std::cout << "ConcreteStrategyV1 operation()." << std::endl;
    }
};

class ConcreteStrategyV2: public AbstractStrategy {
    virtual void operation() {
        std::cout << "ConcreteStrategyV2 operation()." << std::endl;
    }
};

class ConcreteStrategyV3: public AbstractStrategy {
    virtual void operation() {
        std::cout << "ConcreteStrategyV3 operation()." << std::endl;
    }
};

class Context {
public:
    Context() {}

    Context(boost::shared_ptr<AbstractStrategy> strategy):
        strategy_(strategy) {}

    void setContext(boost::shared_ptr<AbstractStrategy> strategy) {
        strategy_ = strategy;
    }

    void doOperation() {
        strategy_->operation();
    }

    ~Context() {}

private:
    boost::shared_ptr<AbstractStrategy> strategy_;
};

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    boost::shared_ptr<AbstractStrategy> strategy1(new ConcreteStrategyV1());
    boost::shared_ptr<AbstractStrategy> strategy2(new ConcreteStrategyV2());
    boost::shared_ptr<AbstractStrategy> strategy3(new ConcreteStrategyV3());

    boost::shared_ptr<Context> context(new Context(strategy1));
    context->doOperation();

    context->setContext(strategy2);
    context->doOperation();

    context->setContext(strategy3);
    context->doOperation();

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
