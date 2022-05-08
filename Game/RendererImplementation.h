#pragma once

#include "Sprite.h"
#include "Shader.h"

namespace Game
{
	class RendererImplementation
	{
	public:
		virtual void Draw(Game::Sprite& Picture, int xPos, int yPos, int zPos, Game::Shader shader) = 0;
		virtual void ClearScreen() = 0;
	};
}