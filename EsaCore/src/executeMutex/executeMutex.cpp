#include "executeMutex.h"
#include "stringConverter.h"


namespace Kashashi{
executeMutex::executeMutex(shared_ptr<loggerInterface> logger): m_logger(logger){}
executeMutex::~executeMutex(){
	ReleaseMutex(hMutex);
	CloseHandle(hMutex);	
}
bool executeMutex::initialize(const std::string& executeName){
	hMutex = CreateMutex(NULL, TRUE, utf8_to_wstring(executeName).c_str());
	if (GetLastError() == ERROR_ALREADY_EXISTS) {
		(*m_logger).writeLog([](){return "Another instance is already running.";});
		return false;
	}
	return true;
}
}