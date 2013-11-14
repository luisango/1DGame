#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(int x, Bullet::BulletDirection direction) 
	: Entity(x, BULLET_SPEED, BULLET_AVATAR), m_iDirection(direction), m_bIsOutOfRange(false) { }

void Bullet::Update()
{
    if (!m_bIsOutOfRange)
        if (m_iDirection == RIGHT)
            MoveForward();
        else 
            MoveBackwards();
}

void Bullet::MoveForward()
{
    if ((m_iX + m_iSpeed) < WORLD_WIDTH_MAX)
        m_iX += m_iSpeed;
    else {
        m_bIsOutOfRange = true;
        m_iX = -1;
    }
}

void Bullet::MoveBackwards()
{
    if ((m_iX - m_iSpeed) > WORLD_WIDTH_MIN)
        m_iX -= m_iSpeed;
    else {
        m_bIsOutOfRange = true;
        m_iX = -1;
    }
}

bool Bullet::IsOutOfRange()
{
	return m_bIsOutOfRange;
}

void Bullet::HasCollide()
{
    m_bIsOutOfRange = true;
    m_iX = -1;
}

Bullet::BulletDirection Bullet::GetDirection()
{
	return m_iDirection;
}