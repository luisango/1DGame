#ifndef __GAMEPADCONTROLLER_H__
#define __GAMEPADCONTROLLER_H__

#include "stdafx.h"
#include "Config.h"
//#include "Game.h" // TODO: OJITO AQUI, ESTO INCLUYE GAME; GAME NECESITA DE GAMEPAD CONTROLLER; BUCLE INFINITO; AGUJERO NEGRO; FIN DEL MUNDO
class Game;

class GamepadController
{
private:
    Game * m_pGame;

public:
	GamepadController(Game * pGame);

    void ProcessInput();
};

#endif