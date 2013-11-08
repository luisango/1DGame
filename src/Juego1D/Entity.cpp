#include "stdafx.h"
#include "Entity.h"

Entity::Entity(int x, int speed, char avatar) 
    : m_iX(x), m_iSpeed(speed), m_cAvatar(avatar) { }

void Entity::Draw()
{
    printf("%c", m_cAvatar);
}

int Entity::GetX()
{
    return m_iX;
}