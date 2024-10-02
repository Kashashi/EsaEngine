#ifndef __LOGGERINTERFACE_H__
#define __LOGGERINTERFACE_H__

#include <string>
#include <functional>

namespace Kashashi{
class loggerInterface{
public:
	loggerInterface() = default;
	virtual ~loggerInterface() = 0;
	void writeLog(std::function<std::string()> ExtraInfomation = [](){return "No Data";}) = 0;
};
}
#endif//__LOGGERINTERFACE_H__