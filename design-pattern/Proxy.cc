
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include <boost/shared_ptr.hpp>

class Subject {
public:
    virtual void Request() = 0;
};

class RealSubject: public Subject {
public:
    virtual void Request() {
        std::cout << "hello i'm real subject." << std::endl;
    }
};

class Proxy {
public:
    typedef boost::shared_ptr<Subject> SubjectPtr;

    Proxy(SubjectPtr subject): subject_(subject) {}

    virtual void Request() {
        subject_->Request();
    }

private:
    SubjectPtr subject_;
};

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    Proxy::SubjectPtr real_subject(new RealSubject);
    boost::shared_ptr<Proxy> proxy(new Proxy(real_subject));
    proxy->Request();

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
