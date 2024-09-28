#include "EsaWindowManager.h"
#include <iostream>
#include <string>

namespace Kashashi{
EsaWindowManager::EsaWindowManager(int width, int height, const std::string& title){
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	monitor = glfwGetPrimaryMonitor();
	mode = glfwGetVideoMode(monitor);

	window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (!window) {
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD" << std::endl;
		exit(EXIT_FAILURE);
	}

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

EsaWindowManager::~EsaWindowManager(){
	glfwDestroyWindow(window);
	glfwTerminate();
}

void EsaWindowManager::setLogger(std::shared_ptr<EsaLogger> logger_ptr){
	m_logger = logger_ptr;
}

void EsaWindowManager::processInput() {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
		glfwSetWindowShouldClose(window, true);
	}
	if (glfwGetKey(window, GLFW_KEY_F11) == GLFW_PRESS){
		enterVideoMode();
	}
}
bool EsaWindowManager::shouldClose() const {
	return glfwWindowShouldClose(window);
}

void EsaWindowManager::swapBuffers() {
	glfwSwapBuffers(window);
}

void EsaWindowManager::pollEvents() {
	glfwPollEvents();
}
void EsaWindowManager::enterVideoMode(){
	if (!isFullscreen) {
		glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, mode->width, mode->height, mode->refreshRate);
		isFullscreen = true;
	} else {
		glfwSetWindowMonitor(window, nullptr, 1000, 700, 1920, 1080, 60);
		isFullscreen = false;
	}
}
void EsaWindowManager::setFrameRate(int newRefreshRate){
	glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, newRefreshRate);
}

void EsaWindowManager::framebuffer_size_callback(GLFWwindow* window, int width, int height){
	glViewport(0, 0, width, height);
}

}