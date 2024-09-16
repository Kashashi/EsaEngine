#include "EsaCore.h"
#include "logger.h"
#include "windowManager.h"

namespace Kashashi{
	EsaCore::EsaCore(){
		Logger = new logger();
	}
	EsaCore::~EsaCore(){
		if(Logger != nullptr){
			delete Logger;
		}
		Logger = nullptr;
	}
	void EsaCore::run(){
		MainWindow = std::make_unique<windowManager>(1920,1080,"EsaEngine");
		while(!(*MainWindow).shouldClose()){
			(*MainWindow).processInput();
			(*MainWindow).pollEvents();
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			(*MainWindow).swapBuffers();
		}
		MainWindow.reset();
	}
	void EsaCore::writeLog(const std::string& logText){
		(*Logger).write(logText);
	}
}
