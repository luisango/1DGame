#include "stdafx.h"
#include "GamepadController.h"
#include "Game.h"

GamepadController::GamepadController(Game * pGame) : m_pGame(pGame) { }

void GamepadController::ProcessInput()
{
    if (_kbhit())
    {
        // Key is pressed, so we get it
        char input = _getch();

        switch(input)
        {
        case KEY_LEFT:
            m_pGame->GetHero()->MoveBackwards();
		    break;
	    case KEY_RIGHT:
		    m_pGame->GetHero()->MoveForward();
		    break;
        case KEY_SHOOT_LEFT:
            m_pGame->GetHero()->ShootLeft();
		    break;
	    case KEY_SHOOT_RIGHT:
		    m_pGame->GetHero()->ShootRight();
		    break;
        case KEY_EXIT:
            std::exit(EXIT_FAILURE);
        }   
    }
}