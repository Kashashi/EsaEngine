#include "Esapch.h"

#include "EsaCore.h"



namespace Kashashi{
	EsaCore::EsaCore(const 軟體資料& 特化數據){
		m_Logger = std::make_shared<EsaLogger>();
		(*m_Logger).LoggerInitialization("錯誤.記錄檔");
	}
	EsaCore::~EsaCore(){}
	void EsaCore::run(){
		(*m_Logger).writeLog("程式開始執行");
		MainWindow = std::make_unique<EsaWindowManager>(1920,1080,"EsaEngine");
		m_textManager = std::make_shared<textManager>(m_Logger);
		m_textRender = std::make_unique<textRender>(m_textManager, m_Logger);
		(*MainWindow).setLogger(m_Logger);
		while(!(*MainWindow).shouldClose()){
			(*MainWindow).processInput();
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			(*m_textRender).textDrow(u"你好", 500.0f, 500.0f, 1.0f, glm::vec3(0.5f, 0.8f, 0.2f));
			(*MainWindow).pollEvents();
			(*MainWindow).swapBuffers();
		}
		MainWindow.reset();
	}
}
