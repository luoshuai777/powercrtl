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

namespace xyz::openbmc_project::powerctrl
{
using TestInherit =
    sdbusplus::server::object::object<sdbusplus::xyz::openbmc_project::server::powerctrl>;

class Test : public TestInherit
{
  public:
    Test(sdbusplus::bus_t& bus, const char* path) : TestInherit(bus, path)
    {
        std::cout << "Test::Test()" << std::endl;
	char data[0];

	ifstream infile;
	infile.open("/sys/class/gpio/gpio807/value");
	infile.getline(data,1);
      if(data[0] == '1')
            currentState("Off");
      else
            currentState("On");
	infile.close();
	memset(data,0,sizeof(data));
	str.clear();
    }
    ~Test()
    {
        std::cout << "Test::~Test()" << std::endl;
    }
};

} // namespace xyz::openbmc_project::powerctrl

int main(int, char const**)
{
    boost::asio::io_context io;
    auto bus = std::make_shared<sdbusplus::asio::connection>(io);

    // If you want emit a interfaces added/removed signal, add this before
    // create object
    sdbusplus::server::manager_t objManager(*bus,
                                            "/xyz/openbmc_project/host_power_interface");
    xyz::openbmc_project::powerctrl::Test test1(
		*bus, "/xyz/openbmc_project/host_fan_interface/powerctrl");
        
    bus->request_name("xyz.openbmc_project.power_ctrl_service");
    io.run();
    return 0;
}
