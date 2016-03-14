#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

class GameWindow
{
	private:
		bool _running;

	public:
		void setRunning(bool newRunning);
		bool getRunning();

		GameWindow(bool running);

		void render();
		void update();
};

#endif
