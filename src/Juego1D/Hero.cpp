#include "stdafx.h"
#include "Hero.h"

Hero::Hero(int x, Manager<Bullet> * pBulletManager) 
	: Entity(x, HERO_SPEED, HERO_AVATAR), m_pBulletManager(pBulletManager) { }

void Hero::Update() 
{
    if (IsAlive())
	    if (m_cAvatar == (char)198)
		    m_cAvatar = (char)204;
	    else if (m_cAvatar == (char)181)
		    m_cAvatar = (char)185;
	    else
		    m_cAvatar = HERO_AVATAR;
}

void Hero::MoveForward()
{
    if (IsAlive())
        if ((m_iX + m_iSpeed) < WORLD_WIDTH_MAX)
            m_iX += m_iSpeed;
        else
            m_iX = WORLD_WIDTH_MAX - 1;
}

void Hero::MoveBackwards()
{
    if (IsAlive())
        if ((m_iX - m_iSpeed) > WORLD_WIDTH_MIN)
            m_iX -= m_iSpeed;
        else
            m_iX = WORLD_WIDTH_MIN;
}

void Hero::ShootRight()
{
    if (IsAlive()) {
	    Bullet pBullet(m_iX + 1, Bullet::BulletDirection::RIGHT);
	    m_pBulletManager->Add(pBullet);

        m_cAvatar = (char)198;
    }
}

void Hero::ShootLeft()
{
    if (IsAlive()) {
	    Bullet pBullet(m_iX - 1, Bullet::BulletDirection::LEFT);
	    m_pBulletManager->Add(pBullet);

        m_cAvatar = (char)181;
    }
}

void Hero::HasCollide()
{
    m_iX = -1;
}

bool Hero::IsAlive()
{
    return m_iX != -1;
}