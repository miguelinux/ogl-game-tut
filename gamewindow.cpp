#include "gamewindow.h"


void GameWindow::setRunning(bool newRunning)
{
	_running = newRunning;
}

bool GameWindow::getRunning()
{
	return _running;
}

GameWindow::GameWindow(bool running)
{
	_running = running;
}

void GameWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	/* Swap front and back buffers */
	glfwSwapBuffers(window);
}

void GameWindow::update()
{
}
