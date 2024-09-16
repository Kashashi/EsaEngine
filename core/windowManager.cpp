#include "windowManager.h"
#include <iostream>
#include <string>

namespace Kashashi{
windowManager::windowManager(int width, int height, const std::string& title){
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

windowManager::~windowManager(){
	glfwDestroyWindow(window);
	glfwTerminate();
}

void windowManager::processInput() {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
		glfwSetWindowShouldClose(window, true);
	}
	if (glfwGetKey(window, GLFW_KEY_F11) == GLFW_PRESS){
		enterVideoMode();
	}
}
bool windowManager::shouldClose() const {
	return glfwWindowShouldClose(window);
}

void windowManager::swapBuffers() {
	glfwSwapBuffers(window);
}

void windowManager::pollEvents() {
	glfwPollEvents();
}
void windowManager::enterVideoMode(){
	if (!isFullscreen) {
		glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, mode->width, mode->height, mode->refreshRate);
		isFullscreen = true;
	} else {
		glfwSetWindowMonitor(window, nullptr, 1000, 700, 1920, 1080, 60);
		isFullscreen = false;
	}
}
void windowManager::setFrameRate(int newRefreshRate){
	glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, newRefreshRate);
}

void windowManager::framebuffer_size_callback(GLFWwindow* window, int width, int height){
	glViewport(0, 0, width, height);
}

}