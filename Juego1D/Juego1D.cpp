// Juego1D.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Config.h"
#include "Game.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Game * pGame = new Game();

	while (1)
	{
        pGame->Draw();
        pGame->Update();
        pGame->ProcessInput();
	}

	return 0;
}

