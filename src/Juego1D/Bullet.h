#ifndef __BULLET_H__
#define __BULLET_H__

#include "stdafx.h"
#include "Config.h"
#include "Entity.h"

class Bullet : public Entity
{
public:
	static enum BulletDirection { LEFT, RIGHT };

private:
    Bullet::BulletDirection m_iDirection;
	bool m_bIsOutOfRange;

public:
    Bullet(int x, Bullet::BulletDirection direction);

    virtual void Update();
    virtual void MoveForward();
    virtual void MoveBackwards();
    virtual void HasCollide();
	bool IsOutOfRange();
    Bullet::BulletDirection GetDirection();
};

#endif