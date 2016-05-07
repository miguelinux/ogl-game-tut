#ifndef SPRITE_H
#define SPRITE_H

#include <GLFW/glfw3.h>
#include "vector2.h"

class Sprite
{
	private:
		GLuint   _textureBufferID;
		Vector2  _position;
		Vector2  _velocity;

	public:
		void setPosition(Vector2 newPosition);
		Vector2 getPosition();

		void setVelocity(Vector2 newVelocity);
		Vector2 getVelocity();

		Sprite(GLuint textureBufferID, Vector2 position);

		void render();
		void update();
};

#endif
