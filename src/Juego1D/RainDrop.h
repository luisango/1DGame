#ifndef __RAINDROP_H__
#define __RAINDROP_H__

#include "stdafx.h"
#include "Config.h"
#include "Entity.h"

class RainDrop : public Entity
{
private:
    int m_iAnimationDelay;
    int m_iAnimationDelayStatus;

public:
    RainDrop(int x, int speed, char avatar);

    virtual void Update();
    virtual void Draw();
    virtual void MoveForward();
    virtual void MoveBackwards();
    virtual void HasCollide();
};

#endif