#ifndef __ENEMYAI_H__
#define __ENEMYAI_H__

#include "stdafx.h"
#include "Config.h"
#include "Manager.h"
#include "Hero.h"
#include "Enemy.h"

class EnemyAI
{
private:
    Manager<Enemy> * m_pEnemyManager;
    Hero * m_pHero;
    int m_iMaxEnemies;
    int m_iTotalEnemiesGenerated;

public:
    EnemyAI(Manager<Enemy> * pEnemyManager, Hero * pHero);

    Enemy::EnemyDirection getEnemyDirection(int iPositionWhereEnemyIsGenerated);
    void Update();
};

#endif