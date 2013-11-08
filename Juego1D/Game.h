#ifndef __GAME_H__
#define __GAME_H__

#include "stdafx.h"
#include "Config.h"
#include "List.h"
#include "Manager.h"
#include "Entity.h"
#include "Bullet.h"
#include "Hero.h"
#include "Enemy.h"
#include "EnemyAI.h"
#include "RainDrop.h"
#include "RainAI.h"
#include "GamepadController.h"

// Que salga (random) un enemigo y va hacia ti y si chocas con el mueres y si le toca una bala, muere.
// Meter efecto lluvia meter una nueva lista de gotas de lluvia
class Game
{
private:
    unsigned int m_iMaxWidth;
    unsigned int m_iMinWidth;
    GamepadController * m_pGamepadController;
	Hero * m_pHero;
	Manager<Bullet> * m_pBulletManager;
    RainAI * m_pRainAI;
    Manager<RainDrop> * m_pRainDropManager;
    EnemyAI * m_pEnemyAI;
    Manager<Enemy> * m_pEnemyManager;

public:
    Game();

	Hero * GetHero();
	void ClearScreen();
    void ProcessInput();
    void Update();
    void Draw();
};

#endif