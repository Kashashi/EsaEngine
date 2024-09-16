#ifndef __LOGGER_H_
#define __LOGGER_H_


#include <fstream>
#include <string>

namespace Kashashi{
	class logger{
	public:
		logger();
		~logger();
		void write(const std::string& 紀錄文字);
	private:
		std::ofstream logFile;

	};
}
#endif//__LOGGER_H_