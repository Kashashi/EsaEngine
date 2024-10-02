#include "EsaLogger.h"

#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <chrono>
#include <ctime>

namespace Kashashi{
EsaLogger::~EsaLogger(){
	if (m_logFile.is_open()){
		m_logFile.close();
	}
}
void EsaLogger::LoggerInitialization(const std::string& fileName,const std::string& pathName){
	setFileName(fileName);
	setPathName(pathName);
	m_logFile.open(m_pathName / m_fileName, std::ios_base::app);
	if (!m_logFile.is_open()){
		std::cerr << "Failed to open log file." << std::endl;
	}
}
void EsaLogger::setFileName(const std::string& fileName){
	m_fileName = utf8_to_wstring(fileName);
}
void EsaLogger::setPathName(const std::string& pathName){
	m_pathName = utf8_to_utf16(pathName);
}
void EsaLogger::writeLog(std::function<std::string()> ExtraInfomation){
	auto now = std::chrono::system_clock::now();
	auto now_time = std::chrono::system_clock::to_time_t(now);
	m_logFile << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%M:%S") << ":" << ExtraInfomation() << std::endl;
}
}