#include "stdafx.h"
#include "RainDrop.h"

RainDrop::RainDrop(int x, int speed, char avatar) 
    : Entity(x, speed, avatar)
{
	m_iAnimationDelay       = RAIN_ANIMATION_DELAY;
    m_iAnimationDelayStatus = 0;
}

void RainDrop::Update() 
{
    bool m_AnimationFrameCompleted = m_iAnimationDelayStatus == m_iAnimationDelay;

	if (m_cAvatar == '\'' && m_AnimationFrameCompleted)
		m_cAvatar = ':';
	else if (m_cAvatar == ':' && m_AnimationFrameCompleted)
		m_cAvatar = '.';
    else if (m_cAvatar == '.' && m_AnimationFrameCompleted)
		m_cAvatar = '_';
	else if (m_cAvatar == '_' && m_AnimationFrameCompleted)
        m_iX = -1;

    if (m_AnimationFrameCompleted)
        m_iAnimationDelayStatus = 0;
    else
        m_iAnimationDelayStatus++;
}

void RainDrop::Draw()
{
    if (m_iX != -1)
        Entity::Draw();
}

void RainDrop::MoveForward() { }

void RainDrop::MoveBackwards() { }