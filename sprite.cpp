#include "sprite.h"

void Sprite::setPosition(Vector2 newPosition)
{
	_position = newPosition;
}

Vector2 Sprite::getPosition()
{
	return _position;
}

void Sprite::setVelocity(Vector2 newVelocity)
{
	_velocity = newVelocity;
}

Vector2 Sprite::getVelocity()
{
	return _velocity;
}

Sprite::Sprite(GLuint textureBufferID, Vector2 position)
{
	_textureBufferID = textureBufferID;
	_position = position;
}


void Sprite::render()
{
	glBindTexture(GL_TEXTURE_2D, _textureBufferID);

	glLoadIdentity();

	glTranslatef(_position.x, _position.y, 0);

	glDrawArrays(GL_QUADS, 0 , 4);
}

void Sprite::update()
{
	_position = addVector2(_position, _velocity);
}
