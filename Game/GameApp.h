#pragma once
#include "GameUtil.h"
// namespace 
namespace Game
{
	class GAME_API GameApp
	{
	public:
		void Run();
		virtual void OnUpdate();

	private:

	};
}
