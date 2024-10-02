#ifndef __ESALOGGER_H_
#define __ESALOGGER_H_

#include <functional>
#include <filesystem>
#include <fstream>
#include <string>

#include "stringConverter.h"

//載入介面
#include "loggerInterface.h"
#include "loggerSettingInterface.h"

namespace Kashashi{
class EsaLogger: public loggerInterface, public loggerSettingInterface{
public:
	EsaLogger() = default;
	~EsaLogger() override;
	void LoggerInitialization(const std::string& fileName, const std::string& pathName = ".") override;
	void setFileName(const std::string& fileName) override;
	void setPathName(const std::string& pathName) override;
	void writeLog(std::function<std::string()> ExtraInfomation = [](){return "No Data";}) override;
private:
	std::filesystem::path m_pathName;
	std::wstring m_fileName;
	std::ofstream m_logFile;
};
}
#endif//__ESALOGGER_H_