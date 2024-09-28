#ifndef __ESACORE_H_
#define __ESACORE_H_

#include <memory>
#include <string>

#include "EsaLogger.h"
#include "EsaWindowManager.h"
#include "textManager.h"
#include "textRender.h"

extern int main(int argc, char* argv[]);

namespace Kashashi{

struct commandLine{
	int countOfCommandArgs = 0;
	char** argv = nullptr;
	
	const char* operator[](int index) const {
		return argv[index];
	}
};

struct 軟體資料{
	std::string 標題名稱 = "";
	commandLine cmd;
};

class EsaCore{
public:
	EsaCore(const 軟體資料& 特化數據);
	virtual ~EsaCore();
private:
	void run();
	std::shared_ptr<EsaLogger> m_Logger;
	std::shared_ptr<textManager> m_textManager;
	std::unique_ptr<EsaWindowManager> MainWindow;
	std::unique_ptr<textRender> m_textRender;
	friend int ::main(int argc, char* argv[]);
};
EsaCore* GirigaraFromHere(commandLine cmd);
}
#endif//__ESACORE_H_