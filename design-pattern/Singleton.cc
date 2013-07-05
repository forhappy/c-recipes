
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

class Singleton {
public:
    static Singleton* getInstance();
    void Action() {
        std::cout << "hello world" << std::endl;
    }
protected:
    Singleton();
private:
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

    static Singleton* singleton_;
};

Singleton::Singleton() {}

Singleton* Singleton::getInstance() {
    if (singleton_ == nullptr) {
        singleton_ = new Singleton();
    }
    return singleton_;
}

Singleton* Singleton::singleton_ = nullptr;

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    Singleton* singleton = Singleton::getInstance();
    singleton->Action();

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
