#pragma once
#include "GameUtil.h"
#include "pch.h"
#include "Events.h"

#define GAME_FRAMERATE 60

namespace Game
{
	class GAME_API GameApp
	{
	public:
		GameApp();
		void Run();
		virtual void OnUpdate();
		void SetKeyPressedCallback(std::function<void(const KeyPressedEvent &)> keyPressedCallback);
		void SetKeyReleasedCallback(std::function<void(const KeyReleasedEvent&)> keyReleasedCallback);
	private:
		std::chrono::milliseconds mFrameDuration{ 1000 / GAME_FRAMERATE };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}
