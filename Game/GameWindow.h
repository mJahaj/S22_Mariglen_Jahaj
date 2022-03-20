#pragma once

#include "WindowImplementation.h"
#include "GameUtil.h"

namespace Game {


	class GAME_API GameWindow
	{
		// Singleton 

	public:
		static void Init();
		static GameWindow* GetWindow();

		

		bool CreateWindow(int width, int height, const std::string& windowName);
		void SwapBuffers();
		void CollectEvents();
		int GetWidth() const;
		int GetHeight() const;



	private:
		inline static GameWindow* mInstance{ nullptr };// exists by itself not attached to class instance

		GameWindow();

		WindowImplementation* mWindow{ nullptr };//purely abstract class

	};
}

// GameWindow::GetWindow()->GetWidth(); From anywhere in game engine
