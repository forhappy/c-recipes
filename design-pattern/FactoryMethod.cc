
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include <boost/shared_ptr.hpp>

class Product {
public:
    virtual void run() = 0;
};

class ConcreteProduct:public Product{
public:
    virtual void run() {
        std::cout << "hello my product." << std::endl;
    }
};

class Creator {
public:
    virtual Product* CreateProduct() = 0;
};

class ConcreteCreator: public Creator {
public:
    virtual Product* CreateProduct() {
        return new ConcreteProduct();
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
    boost::shared_ptr<Creator> creator(new ConcreteCreator());
    boost::shared_ptr<Product> product(creator->CreateProduct());

    product->run();
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
