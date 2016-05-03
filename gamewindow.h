#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

/* To use glGenBuffers and othres */
#define GL_GLEXT_PROTOTYPES
#define GLFW_INCLUDE_GLEXT

#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

class GameWindow
{
	private:
		bool _running;
		GLFWwindow* _window;

		/* Frame buffer size */
		GLsizei _width;
		GLsizei _height;
		GLuint _vertexBufferID;
		GLuint loadAndBufferImage(const char *filename);

	public:
		void setRunning(bool newRunning);
		bool getRunning();

		GameWindow(bool running, GLFWwindow* window);

		void render();
		void update();
};

#endif
