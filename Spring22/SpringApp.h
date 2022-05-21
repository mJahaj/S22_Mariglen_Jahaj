#pragma once

#include "Game.h"
#include "Entity.h"
//class the deals with whole game application
class SpringApp : public Game::GameApp
{
	//whatever happens on each run of game loop should be specified in OnUpdate()
public:
	SpringApp();
	virtual void OnUpdate() override;

	bool Collide(const Entity& one, const Entity& another);

private:
	Entity mHero{ {"Assets/Images/RightHero.png", "Assets/Images/LeftHero.png"} };
	std::vector<Entity> mDangers{ { {"Assets/Images/Danger.png"}} };
	int mEnemyVSpeed{ -5 };



	int mHorizontalSpeed{ 0 }; //speed Measured in pixals per frame
	
};