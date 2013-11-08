#include "stdafx.h"

#include "RainAI.h"

RainAI::RainAI(Manager<RainDrop> * pRainDropManager)
    : m_pRainDropManager(pRainDropManager) { }

void RainAI::Update()
{
    // Generate how many rain drops are generated
    int iTotalRainDropsGenerated = (rand() < RAND_MAX / RAIN_PROBABILITY) ? 1 : 0;

    for (int i = 0; i < iTotalRainDropsGenerated; i++)
    {

        // Generate position of the world for the rain drop
        int iPosition = rand() % WORLD_WIDTH_MAX + WORLD_WIDTH_MIN;

        RainDrop pRainDrop(iPosition, 0, '\'');
        m_pRainDropManager->Add(pRainDrop);
    }
}