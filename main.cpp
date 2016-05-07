#include "gamewindow.h"

#define UPDATES_PER_SECOND 60

int main (void)
{
	GLFWwindow* window;
	double lastTime, deltaTime;

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

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	gameWindow = new GameWindow(true, window);

	glfwSwapInterval(0);

	lastTime = glfwGetTime();
	deltaTime = 0.0f;

	/* Loop until the user closes the window */
	while (gameWindow->getRunning()) {

		/* Render here */

		gameWindow->render();

		deltaTime += (glfwGetTime() - lastTime)*UPDATES_PER_SECOND;
		lastTime = glfwGetTime();

		while (deltaTime >= 1.0f) {
			gameWindow->update();
			--deltaTime;
		}

		/* Poll for and process events */
		glfwPollEvents();

		gameWindow->setRunning(!glfwWindowShouldClose(window));
	}

	delete gameWindow;

	glfwTerminate();
	return 0;
}
