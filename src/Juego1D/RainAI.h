#ifndef __RAINAI_H__
#define __RAINAI_H__

#include "stdafx.h"
#include "Config.h"
#include "Manager.h"
#include "RainDrop.h"

class RainAI
{
private:
    Manager<RainDrop> * m_pRainDropManager;

public:
    RainAI(Manager<RainDrop> * pRainDropManager);

    void Update();
};

#endif