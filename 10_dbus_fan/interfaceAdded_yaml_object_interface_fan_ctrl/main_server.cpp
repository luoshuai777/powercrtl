#include <boost/asio.hpp>
#include <xyz/openbmc_project/fanctrl/server.hpp>
#include <phosphor-logging/lg2.hpp>
#include <sdbusplus/asio/connection.hpp>
#include <sdbusplus/asio/object_server.hpp>
#include <sdbusplus/asio/property.hpp>
#include <sdbusplus/bus/match.hpp>

#include <iostream>
#include <fstream>
#include<string.h>

using namespace std;

namespace xyz::openbmc_project::test
{
using TestInherit =
    sdbusplus::server::object::object<sdbusplus::xyz::openbmc_project::server::test>;

class Test : public TestInherit
{
  public:
    Test(sdbusplus::bus_t& bus, const char* path) : TestInherit(bus, path)
    {
        std::cout << "Test::Test()" << std::endl;
	char data[30];
        string str;

	ifstream infile;
	infile.open("/sys/class/hwmon/hwmon1/pwm1");
	infile.getline(data,10);
	str = data;
	fanCtrl0(str);
	infile.close();
	memset(data,0,sizeof(data));
	str.clear;

        infile.open("/sys/class/hwmon/hwmon1/pwm2");
        infile.getline(data,10);
        str = data;
        fanCtrl1(str);
        infile.close();
        memset(data,0,sizeof(data));
        str.clear;

        infile.open("/sys/class/hwmon/hwmon1/pwm3");
        infile.getline(data,10);
        str = data;
        fanCtrl2(str);
        infile.close();
        memset(data,0,sizeof(data));
        str.clear;

        infile.open("/sys/class/hwmon/hwmon1/pwm4");
        infile.getline(data,10);
        str = data;
        fanCtrl3(str);
        infile.close();
        memset(data,0,sizeof(data));
        str.clear;
    }
    ~Test()
    {
        std::cout << "Test::~Test()" << std::endl;
    }
};

} // namespace xyz::openbmc_project::test

int main(int, char const**)
{
    boost::asio::io_context io;
    auto bus = std::make_shared<sdbusplus::asio::connection>(io);

    // If you want emit a interfaces added/removed signal, add this before
    // create object
    sdbusplus::server::manager_t objManager(*bus,
                                            "/xyz/openbmc_project/my_fan_interface");
    xyz::openbmc_project::test::Test test1(
		*bus, "/xyz/openbmc_project/my_fan_interface/fanctrl");
        
    bus->request_name("xyz.openbmc_project.fan_ctrl_service");
    io.run();
    return 0;
}
