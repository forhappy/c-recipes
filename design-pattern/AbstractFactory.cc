
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <boost/shared_ptr.hpp>

class RoadsterAbstractVehile {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
};

class DasAutoRoadsterVehile: public RoadsterAbstractVehile {
public:
    virtual void start() {
        std::cout << "DasAuto RoadsterVehile starts." << std::endl;
    }

    virtual void stop() {
        std::cout << "DasAuto RoadsterVehile stops." << std::endl;
    }
};

class FordRoadsterVehile: public RoadsterAbstractVehile {
public:
    virtual void start() {
        std::cout << "Ford RoadsterVehile starts." << std::endl;
    }

    virtual void stop() {
        std::cout << "Ford RoadsterVehile stops." << std::endl;
    }
};

class BizAbstractVehile {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
};

class DasAutoBizVehile: public BizAbstractVehile {
public:
    virtual void start() {
        std::cout << "DasAuto BizVehile starts." << std::endl;
    }

    virtual void stop() {
        std::cout << "DasAuto BizVehile stops." << std::endl;
    }

};

class FordBizVehile: public BizAbstractVehile {
public:
    virtual void start() {
        std::cout << "Ford BizVehile starts." << std::endl;
    }

    virtual void stop() {
        std::cout << "Ford BizVehile stops." << std::endl;
    }
};

class VehileAbstractFactory {
public:
    virtual RoadsterAbstractVehile* CreateRoadsterVehile() = 0;
    virtual BizAbstractVehile* CreateBizVehile() = 0;
};

class DasAutoFactory: public VehileAbstractFactory {
    virtual RoadsterAbstractVehile* CreateRoadsterVehile() {
        return new DasAutoRoadsterVehile();
    }
    virtual BizAbstractVehile* CreateBizVehile() {
        return new DasAutoBizVehile();
    }
};

class FordFactory: public VehileAbstractFactory {
    virtual RoadsterAbstractVehile* CreateRoadsterVehile() {
        return new FordRoadsterVehile();
    }
    virtual BizAbstractVehile* CreateBizVehile() {
        return new FordBizVehile();
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
    boost::shared_ptr<VehileAbstractFactory> dasauto_factory(new DasAutoFactory());
    boost::shared_ptr<VehileAbstractFactory> ford_factory(new FordFactory());

    boost::shared_ptr<RoadsterAbstractVehile>
        dasauto_roadster(dasauto_factory->CreateRoadsterVehile());
    (*dasauto_roadster).start();
    dasauto_roadster->stop();

    boost::shared_ptr<BizAbstractVehile>
        dasauto_biz(dasauto_factory->CreateBizVehile());
    (*dasauto_biz).start();
    dasauto_biz->stop();

    boost::shared_ptr<RoadsterAbstractVehile>
        ford_roadster(ford_factory->CreateRoadsterVehile());
    (*ford_roadster).start();
    ford_roadster->stop();

    boost::shared_ptr<BizAbstractVehile>
        ford_biz(ford_factory->CreateBizVehile());
    (*ford_biz).start();
    ford_biz->stop();

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
