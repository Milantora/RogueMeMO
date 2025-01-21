module;
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

import <string>;
import <iostream>;

module RogueGraphicEngine;
namespace RogueGraphicEngine
{
	//private fields

	static bool shouldStop = false;
	void (*stopCallback)(int) = nullptr;
	GLFWwindow* window = nullptr;

	//public fields


	//private methods

	void keyCallback(GLFWwindow*, int, int, int, int);

	//public methods defines

	void Init(std::string name, int w, int h)
	{
		std::cout << "Graphic Engine running!\n";
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

		window = glfwCreateWindow(w, h, name.c_str(), nullptr, nullptr);
		if (window == nullptr)
		{
			std::cout << "glfw error\n";
			return;
		}
		glfwMakeContextCurrent(window);

		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
		{
			std::cout << "glew error\n";
			return;
		}

		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);

		glfwSetKeyCallback(window, keyCallback);

		GLfloat r = 0.4, g = 0.2, b = 0.65, p = 0.0002;

		while (!ShouldStop())
		{
			glfwPollEvents();

			glClearColor(r, g, b, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			r = (r >= 1) ? 0 : r + p;
			g = (g >= 1) ? 0 : g + p;
			b = (b >= 1) ? 0 : b + p;

			glfwSwapBuffers(window);
		}
		glfwTerminate();
	}

	void setStopCallback(void (*cb)(int))
	{
		stopCallback = cb;
	}

	bool ShouldStop()
	{
		return shouldStop;
	}

	void Terminate()
	{
		shouldStop = true;
		glfwSetWindowShouldClose(window, GL_TRUE);
		std::cout << "Graphic Engine ded :<\n";
		stopCallback(0);
	}

	//private methods defines

	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		{
			Terminate();
		}
	}
}