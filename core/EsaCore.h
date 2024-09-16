#ifndef __ESACORE_H_
#define __ESACORE_H_

#include <memory>
#include <string>

#include "logger.h"
#include "windowManager.h"

namespace Kashashi{
	class EsaCore{
	public:
		EsaCore();
		~EsaCore();
		void run();
		void writeLog(const std::string& logText);
	private:
		logger* Logger = nullptr;
		std::unique_ptr<windowManager> MainWindow;
	};
}
#endif//__ESACORE_H_