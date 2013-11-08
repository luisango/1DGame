#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "stdafx.h"
#include "Config.h"
#include "Entity.h"

class Enemy : public Entity
{
public:
    static enum EnemyDirection { LEFT, RIGHT };

private:
    Enemy::EnemyDirection m_iDirection;
    int m_iAnimationDelay;
    int m_iAnimationDelayStatus;

public:
    Enemy(int x, Enemy::EnemyDirection direction);

    virtual void Update();
    virtual void MoveForward();
    virtual void MoveBackwards();
};

#endif