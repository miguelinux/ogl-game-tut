#ifndef SPRITE_H
#define SPRITE_H

#include <GLFW/glfw3.h>
#include "vector2.h"

#define SQUARE_SIZE 100.0f

class Sprite
{
	private:
		GLuint   _textureBufferID;
		Vector2  _velocity;

	protected:
		Vector2  _position;
		GLFWwindow* _window;

	public:
		void setPosition(Vector2 newPosition);
		Vector2 getPosition();

		void setVelocity(Vector2 newVelocity);
		Vector2 getVelocity();

		Sprite(GLFWwindow* window, GLuint textureBufferID, Vector2 position);

		void render();
		virtual void update();
};

#endif
