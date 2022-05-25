#include "SpringApp.h"

SpringApp::SpringApp()
{
	SetKeyPressedCallback([this](const Game::KeyPressedEvent& e) {
		switch (e.GetKeyCode())
		{
		case GAME_KEY_LEFT:
			mHorizontalSpeed = mHeroSpeed * -1;
			mHero.SetActiveImage(1);//left image
			break;
		case GAME_KEY_RIGHT:
			mHorizontalSpeed = mHeroSpeed;
			mHero.SetActiveImage(0);// right image
			break;
		}
		});

	SetKeyReleasedCallback([this](const Game::KeyReleasedEvent& e) {
		mHorizontalSpeed = 0;
		});

	srand(time(0));
	
	newXPos = (rand() % 800);
		
	
	mFruits[0].SetX(newXPos);
	mFruits[0].SetY(600);
}

void SpringApp::OnUpdate()
{
	mHero.SetX(mHero.GetX() + mHorizontalSpeed);

	if (mFruits[0].GetY() < 0)
		mEnemyVSpeed *= -1;
	else if (mFruits[0].GetY() > Game::GameWindow::GetWindow()->GetHeight() - mFruits[0].GetHeight())
		mEnemyVSpeed *= -1;

	mFruits[0].SetY(mFruits[0].GetY() + mEnemyVSpeed);
	if (Collide(mHero, mFruits[0]))
	{
		
		newXPos = (rand() % 800);
		mFruits[0].SetX(newXPos);
		mFruits[0].SetY(600);
		activeFruit = (rand() % 5);
		mFruits[0].SetActiveImage(activeFruit);
		mHeroSpeed++;
		mEnemyVSpeed -= .25;
		score++;
	}

	if (mFruits[0].GetY() <= 0)// If enemy hits floor game over
	{
		std::cout << "Score: " << score <<std::endl;
		exit(0);
	}	

	mHero.Draw();
	mFruits[0].Draw();
}

bool SpringApp::Collide(const Entity& one, const Entity& another)
{// x = left border
	int oneLeft{ one.GetX() };
	int oneRight{ one.GetX() + one.GetWidth() };
	int anotherLeft{ another.GetX() };
	int anotherRight{ another.GetX() + another.GetWidth() };

	int oneBottom{ one.GetY() };
	int oneTop{ one.GetY() + one.GetHeight() };
	int anotherBottom{ another.GetY() };
	int anotherTop{ another.GetY() + another.GetHeight() };


	bool collideX{ false };
	if ((oneLeft <= anotherLeft && anotherLeft <= oneRight) ||
		(anotherLeft <= oneLeft && oneLeft <= anotherRight))
		collideX = true;

	bool collideY{ false };
	if ((oneBottom <= anotherBottom && anotherBottom <= oneTop) ||
		(anotherBottom <= oneBottom && oneBottom <= anotherTop))
		collideY = true;

	return collideX && collideY;
}
