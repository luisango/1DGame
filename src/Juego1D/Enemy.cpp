#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy(int x, Enemy::EnemyDirection direction) 
	: Entity(x, ENEMY_SPEED, ENEMY_AVATAR), m_iDirection(direction)
{
    m_iAnimationDelay       = ENEMY_ANIMATION_DELAY;
    m_iAnimationDelayStatus = 0;
}

void Enemy::Update() 
{
    if (m_iX == -1)
        return;

    // Logic update
    if (m_iDirection == RIGHT)
        MoveForward();
    else 
        MoveBackwards();

    bool m_AnimationFrameCompleted = m_iAnimationDelayStatus == m_iAnimationDelay;

    // Avatar update
	if (m_cAvatar == ENEMY_AVATAR && m_AnimationFrameCompleted)
		m_cAvatar = 'O';
	else if (m_cAvatar == 'O'  && m_AnimationFrameCompleted)
		m_cAvatar = ENEMY_AVATAR;

    if (m_AnimationFrameCompleted)
        m_iAnimationDelayStatus = 0;
    else
        m_iAnimationDelayStatus++;
}

void Enemy::MoveForward()
{
    if ((m_iX + m_iSpeed) < WORLD_WIDTH_MAX)
        m_iX += m_iSpeed;
    else
        m_iX = WORLD_WIDTH_MAX + 1;
}

void Enemy::MoveBackwards()
{
    if ((m_iX - m_iSpeed) > WORLD_WIDTH_MIN)
        m_iX -= m_iSpeed;
    else
        m_iX = WORLD_WIDTH_MIN - 1;
}

void Enemy::HasCollide()
{
    m_iX = -1;
}

Enemy::EnemyDirection Enemy::GetDirection()
{
	return m_iDirection;
}