#include <GLFW/glfw3.h>
#include "gamewindow.h"

int main (void)
{
	GLFWwindow* window;

	/* My game window */
	GameWindow* gameWindow;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Juego en OpenGL", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	gameWindow = new GameWindow(true, window);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (gameWindow->getRunning()) {

		/* Render here */

		gameWindow->render();
		gameWindow->update();

		/* Poll for and process events */
		glfwPollEvents();

		gameWindow->setRunning(!glfwWindowShouldClose(window));
	}

	delete gameWindow;

	glfwTerminate();
	return 0;
}
