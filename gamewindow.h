#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <GLFW/glfw3.h>

class GameWindow
{
	private:
		bool _running;
		GLFWwindow* _window;

	public:
		void setRunning(bool newRunning);
		bool getRunning();

		GameWindow(bool running, GLFWwindow* window);

		void render();
		void update();
};

#endif
