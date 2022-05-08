#pragma once

#include "SpriteImplementation.h"
#include "GameUtil.h"

namespace Game
{

	class GAME_API Sprite
	{
	public:
		Sprite(const std::string& filename);

		int GetWidth() const;
		int GetHeight() const;

		void Bind();
	private:
		SpriteImplementation* mImplementation;
	};
}
