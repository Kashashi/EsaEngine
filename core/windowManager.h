#ifndef __WINDOWMANAGER_H_
#define __WINDOWMANAGER_H_

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Kashashi{
	class windowManager{
	public:
		windowManager(int width, int height, const std::string& title);
		~windowManager();
		void processInput();
		bool shouldClose() const;
		void swapBuffers();
		void pollEvents();
		void enterVideoMode();
		void setFrameRate(int newRefreshRate);
	private:
		bool isFullscreen;
		GLFWwindow* window = nullptr;
		GLFWmonitor* monitor = nullptr;
		const GLFWvidmode* mode;
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	};
}
#endif//__WINDOWMANAGER_H_