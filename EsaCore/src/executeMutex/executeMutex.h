#ifndef __EXECUTEMUTEX_H__
#define __EXECUTEMUTEX_H__

#include "binaryMutexInterface.h"
#include "loggerInterface.h"

#include <windows.h>
#include <memory>

namespace Kashashi{
class executeMutex: public binaryMutexInterface{
public:
	executeMutex(shared_ptr<loggerInterface> logger);
	virtual ~executeMutex() override;
	virtual bool initialize(const std::string& executeName) override;
private:
	HANDLE hMutex;
	shared_ptr<loggerInterface> m_logger;
};
}

#endif//__EXECUTEMUTEX_H__