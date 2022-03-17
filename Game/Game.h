#pragma once
//Everything user will need
#include "GameApp.h"
#include "GameWindow.h"

//macro creation
#define GAME_APPLICATION_START(classname) \
\
int main()\
{\
	classname game;\
	game.Run();\
}