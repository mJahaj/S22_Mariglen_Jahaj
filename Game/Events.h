#pragma once

#include "GameUtil.h"

namespace Game
{
	class GAME_API KeyPressedEvent
	{
	public:
		KeyPressedEvent(int codeOfKey);
		KeyPressedEvent() = delete;//forbid default construction

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

	class GAME_API KeyReleasedEvent
	{
	public:
		KeyReleasedEvent(int codeOfKey);
		KeyReleasedEvent() = delete;//forbid default construction

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

}