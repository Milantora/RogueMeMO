#define GLEW_STATIC

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void keyCallback(GLFWwindow*, int, int, int, int);

void Init(std::string name, int w, int h)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	auto window = glfwCreateWindow(w, h, name.c_str(), nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "glfw error" << std::endl;
		return;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "glew error" << std::endl;
		return;
	}

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	glfwSetKeyCallback(window, keyCallback);

	GLfloat r = 0.4, g = 0.2, b = 0.65, p = 0.0002;

	while (!glfwWindowShouldClose(window))
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

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}