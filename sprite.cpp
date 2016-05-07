#include "sprite.h"

void Sprite::setPosition(Vector2 newPosition)
{
	_position = newPosition;
}

Vector2 Sprite::getPosition()
{
	return _position;
}

Sprite::Sprite(GLuint textureBufferID, Vector2 position)
{
	_textureBufferID = textureBufferID;
	_position = position;
}


void Sprite::render()
{
	glBindTexture(GL_TEXTURE_2D, _textureBufferID);

	glDrawArrays(GL_QUADS, 0 , 4);
}

void Sprite::update()
{

}
