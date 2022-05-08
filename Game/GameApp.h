#pragma once
#include "GameUtil.h"
#include "pch.h"

#define GAME_FRAMERATE 60

namespace Game
{
	class GAME_API GameApp
	{
	public:
		void Run();
		virtual void OnUpdate();

	private:
		std::chrono::milliseconds mFrameDuration{ 1000 / GAME_FRAMERATE };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}
