#ifndef SPRITE_H
#define SPRITE_H

#include <GLFW/glfw3.h>

typedef struct {
	GLfloat x;
	GLfloat y;
} Vector2;

class Sprite
{
	private:
		GLuint   _textureBufferID;
		Vector2  _position;

	public:
		void setPosition(Vector2 newPosition);
		Vector2 getPosition();

		Sprite(GLuint textureBufferID);

		void render();
		void update();
};

#endif
