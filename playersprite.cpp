#include "playersprite.h"

PlayerSprite::PrivateSprite(GLuint textureBufferID, Vector2 position):
	Sprite(textureBufferID, position)
{

}

void PlayerSprite::update()
{
	if (glfwGetKey(GLFW_KEY_UP)) {
		_position = addVector2(_position, makeVector2(0.0f, 1.5f));
	}
	if (glfwGetKey(GLFW_KEY_DOWN)) {
		_position = addVector2(_position, makeVector2(0.0f, -1.5f));
	}
	if (glfwGetKey(GLFW_KEY_LEFT)) {
		_position = addVector2(_position, makeVector2(-1.5f, 0.0f));
	}
	if (glfwGetKey(GLFW_KEY_RIGHT)) {
		_position = addVector2(_position, makeVector2(1.5f, 0.0f));
	}
}

