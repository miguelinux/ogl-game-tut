#include "gamewindow.h"

#define UPDATES_PER_SECOND 60

/* My game window */
GameWindow* gameWindow;

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	gameWindow->mouseButtonPressed(button, action);
}

int main (void)
{
	GLFWwindow* window;
	double lastTime, deltaTime;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Juego en OpenGL", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

#ifdef _WIN32
	/* Initialize GLEW */
	//glewExperimental = true; /* Needed for core profile */
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		glfwTerminate();
		return -2;
	}
#endif /*_WIN32*/

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glfwSetMouseButtonCallback(window, mouse_button_callback);

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
