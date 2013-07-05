
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <map>

#include <boost/shared_ptr.hpp>

class Singleton {
public:
    Singleton();
    static Singleton* getInstance();

    static void Register(const std::string &name,
            boost::shared_ptr<Singleton> singleton);

    void Action() {
        std::cout << "hello world" << std::endl;
    }

private:
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

    static Singleton* singleton_;
    static std::map<std::string, boost::shared_ptr<Singleton> > registry_;
};

Singleton::Singleton() {}

void Singleton::Register(const std::string& name,
        boost::shared_ptr<Singleton> singleton) {
    registry_.insert(std::pair<const std::string&,
            boost::shared_ptr<Singleton> >(name, singleton));
}

Singleton* Singleton::getInstance() {
    std::string name(getenv("XXX") ? getenv("XXX") : "");
    if (name.empty()) name = "default";

    if (singleton_ == nullptr) {
        singleton_ = (registry_.find(name)->second).get();
    }
    return singleton_;
}

Singleton* Singleton::singleton_ = nullptr;
std::map<std::string, boost::shared_ptr<Singleton> > Singleton::registry_;

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    boost::shared_ptr<Singleton> p(new Singleton());
    Singleton::Register("default", p);
    Singleton* singleton = Singleton::getInstance();
    singleton->Action();

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
