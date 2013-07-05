
#include <stdio.h>
#include <stdlib.h>

#include <boost/shared_ptr.hpp>

class Computer {
public:
    void run() {
        std::cout << "hello computer" << std::endl;
    }
};

class AbstractComputerBuilder {
public:
    virtual void BuildCPU() = 0;
    virtual void BuildMemory() = 0;
    virtual void BuildMainBoard() = 0;
    virtual void BuildDisk() = 0;

    virtual Computer GetComputer() = 0;
};

class AsusComputerBuilder: public AbstractComputerBuilder {
public:
    virtual void BuildCPU() {
        std::cout << "ASUS: buiding CPU" << std::endl;
    }
    virtual void BuildMemory() {
        std::cout << "ASUS: buiding Memory" << std::endl;
    }
    virtual void BuildMainBoard() {
        std::cout << "ASUS: buiding Main Board" << std::endl;
    }
    virtual void BuildDisk() {
        std::cout << "ASUS: buiding Disk" << std::endl;
    }

    Computer GetComputer() {
        return Computer();
    }

};

class Director {
public:
    Director(boost::shared_ptr<AbstractComputerBuilder> builder): builder_(builder) {}

    void Construct() {
        builder_->BuildCPU();
        builder_->BuildMemory();
        builder_->BuildMainBoard();
        builder_->BuildDisk();
    };

private:
    boost::shared_ptr<AbstractComputerBuilder> builder_;
};

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    boost::shared_ptr<AbstractComputerBuilder>
        builder(new AsusComputerBuilder());

    boost::shared_ptr<Director> director(new Director(builder));

    director->Construct();

    Computer computer = builder->GetComputer();

    computer.run();

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
