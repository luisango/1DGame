#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "stdafx.h"
#include "Config.h"

class Entity 
{
protected:
    int  m_iX;
    int  m_iSpeed;
    char m_cAvatar;

public:
    Entity(int x, int speed, char avatar);

    virtual void Update();
    virtual void Draw();
    virtual void MoveForward();
    virtual void MoveBackwards();
    virtual void HasCollide();
    int GetX();
};

#endif