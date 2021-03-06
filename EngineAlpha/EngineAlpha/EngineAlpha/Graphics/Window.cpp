#include "Window.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "../Core/Log.h"

namespace alpha {
	Window::Window(int windowWidth, int windowHeight, std::string windowName) : SizeX(windowWidth), SizeY(windowHeight) {
		if (!glfwInit()) {
			LOG_ERROR("GLFW Failed to initialize!");

			std::cin.get();
			exit(EXIT_FAILURE);
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		m_glfwWindow = glfwCreateWindow(windowWidth, windowHeight, windowName.c_str(), nullptr, nullptr);

		if (!m_glfwWindow) {
			LOG_ERROR("GLFW Window Failed to create!");

			std::cin.get();
			glfwTerminate();
			exit(EXIT_FAILURE);
		}
		glfwMakeContextCurrent(m_glfwWindow);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			LOG_ERROR("Failed to initialize GLAD");

			std::cin.get();
			glfwTerminate();
			exit(EXIT_FAILURE);
		}

		glEnable(GL_TEXTURE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glfwSwapInterval(1);
	}

	Window::~Window() {
		glfwTerminate();
	}

	void Window::Clear() {
		glfwGetWindowSize(m_glfwWindow, &SizeX, &SizeY);

		glViewport(0, 0, SizeX, SizeY);
		glClearColor(.5f, .5f, .5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Window::SwapBuffers() {
		glfwSwapBuffers(m_glfwWindow);
	}

	void Window::PollEvents() {
		glfwPollEvents();
	}

	GLFWwindow *Window::GetGLFWWindow() {
		return m_glfwWindow;
	}

	bool Window::IsOpen() {
		return !glfwWindowShouldClose(m_glfwWindow);
	}
}