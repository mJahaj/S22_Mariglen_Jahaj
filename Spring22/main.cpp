#include "Game.h"

//inherit your application class from our application class that we 
//give and then use out GAME_APPLICATION_START macro and supply your application class name for it

class SpringApp : public Game::GameApp
{
	//whatever happens on each run of game loop should be specified in OnUpdate()

};
GAME_APPLICATION_START(SpringApp);