#include <vector>

#include "config.h"
#include "reflect.h"

int main()
{
	config::Config config;
	bool ret = config.ReadConfig("myini.ini");
	if (ret == false)
	{
		printf("Error::ReadConfig::Cfg=%s", "myconfig.ini");
		return 1;
	}

	std::string username = config.ReadString("GENERAL", "UserName", "");
	std::string password = config.ReadString("GENERAL", "PassWord", "");
	std::cout << "[GENREAL]" << std::endl;
	std::cout << "Username=" << username << std::endl;
	std::cout << "PassWord=" << password << std::endl;

	return 0;
}

