#ifndef __LOGGERSETTINGINTERFACE_H__
#define __LOGGERSETTINGINTERFACE_H__

#include <string>

namespace Kashashi{
class loggerSettingInterface{
public:
	loggerSettingInterface() = default;
	virtual ~loggerSettingInterface() = 0;
	void LoggerInitialization(const std::string& fileName, const std::string& pathName = ".") = 0;
	void setFileName(const std::string& fileName) = 0;
	void setPathName(const std::string& pathName) = 0;
};
}
#endif//__LOGGERSETTINGINTERFACE_H__