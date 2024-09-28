#ifndef __ESAWINDOWMANAGER_H_
#define __ESAWINDOWMANAGER_H_

#include <string>
#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "EsaLogger.h"

namespace Kashashi{
	class EsaWindowManager{
	public:
		EsaWindowManager(int width, int height, const std::string& title);
		void setLogger(std::shared_ptr<EsaLogger> logger_ptr);
		~EsaWindowManager();
		void processInput();
		bool shouldClose() const;
		void swapBuffers();
		void pollEvents();
		void enterVideoMode();
		void setFrameRate(int newRefreshRate);
	private:
		bool isFullscreen;
		std::shared_ptr<EsaLogger> m_logger;
		GLFWwindow* window = nullptr;
		GLFWmonitor* monitor = nullptr;
		const GLFWvidmode* mode;
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	};
}
#endif//__ESAWINDOWMANAGER_H_