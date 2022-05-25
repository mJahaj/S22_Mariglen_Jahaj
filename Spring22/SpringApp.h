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
	Entity mHero{ {"Assets/Images/FrogRight.png", "Assets/Images/FrogLeft.png"} };
	std::vector<Entity> mFruits{ { {"Assets/Images/blackberry.png", 
										"Assets/Images/cherry.png" , 
										"Assets/Images/apple.png", 
										"Assets/Images/banana1.png", 
										"Assets/Images/strawberry.png"} } };
	
	
	float mEnemyVSpeed{ -2 };
	int newXPos;// update enemy x position
	int activeFruit = 0;

	int mHorizontalSpeed{ 0 }; //speed Measured in pixals per frame
	int mHeroSpeed = 7;

	int score = 0;
	
};