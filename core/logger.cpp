#include "logger.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <chrono>
#include <ctime>

namespace Kashashi{
	logger::logger(){
		logFile.open("錯誤.記錄檔", std::ios_base::ate);
	}

	logger::~logger(){
		if (logFile.is_open()){
			logFile.close();
		}
	}
	void logger::write(const std::string& 紀錄文字){
		auto now = std::chrono::system_clock::now();
		auto now_time = std::chrono::system_clock::to_time_t(now);
		logFile << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%M:%S") << ": " << 紀錄文字 << std::endl;
	}
}