#ifndef __HERO_H__
#define __HERO_H__

#include "stdafx.h"
#include "Config.h"
#include "Entity.h"
#include "Bullet.h"
#include "Manager.h"

class Hero : public Entity
{
private:
 	Manager<Bullet> * m_pBulletManager;

public:
    Hero(int x, Manager<Bullet> * pBulletManager);

    virtual void Update();
    virtual void MoveForward();
    virtual void MoveBackwards();
    void ShootRight();
    void ShootLeft();
};

#endif