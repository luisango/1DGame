#include "stdafx.h"
#include "EnemyAI.h"

EnemyAI::EnemyAI(Manager<Enemy> * pEnemyManager, Hero * pHero)
    : m_pEnemyManager(pEnemyManager), m_pHero(pHero)
{
    m_iMaxEnemies = 2;
    m_iTotalEnemiesGenerated = 0;
}

Enemy::EnemyDirection EnemyAI::getEnemyDirection(int iPositionWhereEnemyIsGenerated)
{
    if (m_pHero->GetX() < iPositionWhereEnemyIsGenerated)
        return Enemy::EnemyDirection::LEFT;
    else
        return Enemy::EnemyDirection::RIGHT;
}

void EnemyAI::Update()
{
    if (m_iTotalEnemiesGenerated <= m_iMaxEnemies) {
        // Decide how many enemies are generated
        // Reduce generation            
        int iTotalEnemiesGenerated = (rand() < RAND_MAX / ENEMY_PROBABILITY) ? 1 : 0;

        for (int i = 0; i < iTotalEnemiesGenerated; i++)
        {
            // Generate position of the world for enemy
            int iPosition = rand() % WORLD_WIDTH_MAX + WORLD_WIDTH_MIN;

            Enemy pEnemy(iPosition, getEnemyDirection(iPosition));
            m_pEnemyManager->Add(pEnemy);
        }
    }
}