#ifndef __ESALOGGER_H_
#define __ESALOGGER_H_

#include <functional>
#include <filesystem>
#include <fstream>
#include <string>
#include "stringConverter.h"

namespace Kashashi{
class EsaLogger{
public:
	EsaLogger();
	~EsaLogger();
	void LoggerInitialization(const std::string& fileName, const std::string& pathName = ".");
	void setFileName(const std::string& fileName);
	void setPathName(const std::string& pathName);
	void writeLog(const std::string& 紀錄文字, std::function<std::string()> ExtraInfomation = [](){return "No Extra Infomation";});
private:
	std::filesystem::path m_pathName;
	std::wstring m_fileName;
	std::ofstream m_logFile;
};
}
#endif//__ESALOGGER_H_