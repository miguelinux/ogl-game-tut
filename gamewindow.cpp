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
}

void GameWindow::update()
{
}
