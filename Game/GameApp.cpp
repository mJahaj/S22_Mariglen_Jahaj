#include "pch.h"

#include "GameApp.h"

namespace Game
{
	void GameApp::Run()		
	{
		GAME_LOG("Running ..");
		while (true)//game loop, frame rendering 
		{
			//collect user input
			//update game world based on user input
			//generate next frame
			OnUpdate();
		}
	}
	void GameApp::OnUpdate()
	{

	}
}