#ifndef PLAYERSPRITE_H
#define PLAYERSPRITE_H

#include "sprite.h"

class PlayerSprite : public Sprite
{
	private:

	public:
		PlayerSprite(GLuint textureBufferID, Vector2 position);

		void update();
};

#endif
