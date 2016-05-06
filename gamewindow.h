#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

/* To use glGenBuffers and othres */
#define GL_GLEXT_PROTOTYPES
#define GLFW_INCLUDE_GLEXT

#include <GLFW/glfw3.h>
#include "sprite.h"

class GameWindow
{
	private:
		bool _running;
		GLFWwindow* _window;

		/* Frame buffer size */
		GLsizei _width;
		GLsizei _height;
		GLuint _vertexBufferID;
		GLuint _textureBufferID;
		GLuint loadAndBufferImage(const char *filename);
		Sprite *_rocket;

	public:
		void setRunning(bool newRunning);
		bool getRunning();

		GameWindow(bool running, GLFWwindow* window);

		void render();
		void update();
};

#endif
