#include "stdafx.h"
#include "Game.h"

Game::Game()
{
    m_iMaxWidth   = WORLD_WIDTH_MAX;
    m_iMinWidth   = WORLD_WIDTH_MIN;
		
    m_pRainDropManager = new Manager<RainDrop>();
    m_pRainAI          = new RainAI(m_pRainDropManager);
        
    m_pBulletManager = new Manager<Bullet>();
	m_pHero          = new Hero(m_iMaxWidth/2, m_pBulletManager);

    m_pEnemyManager = new Manager<Enemy>();
    m_pEnemyAI      = new EnemyAI(m_pEnemyManager, m_pHero);

    m_pGamepadController = new GamepadController(this);
}

Hero * Game::GetHero()
{
	return m_pHero;
}

void Game::ClearScreen()
{
	printf("%c", CFG_CLEAR_CHARACTER);
}
    
void Game::ProcessInput()
{
    m_pGamepadController->ProcessInput();
}

void Game::Update()
{
    // Update rain
    m_pRainAI->Update();

	// Update hero
	m_pHero->Update();

	// Update all bullets
	List<Bullet> * pBullets = m_pBulletManager->GetList();
    List<Bullet>::Node * pBullet = pBullets->First();
	List<Bullet>::Node * pBulletToDelete = NULL;

    while (pBullet)
    {
		// If bullet is out of world range
		if (pBullet->Value().IsOutOfRange()) {
			// Reference the bullet to delete
			pBulletToDelete = pBullet;

			pBullet = pBullet->Next();
			// Remove it
			//pBullets->Remove(pBulletToDelete);
			continue;
		} else
			pBullet->Value().Update();

        pBullet = pBullet->Next();
    }

    // Update enemies
    m_pEnemyAI->Update();

    // TODO: COLLISION DETECTION
    // Update all enemies
	List<Enemy> * pEnemies = m_pEnemyManager->GetList();
    List<Enemy>::Node * pEnemy = pEnemies->First();
	List<Enemy>::Node * pEnemyToDelete = NULL;

    while (pEnemy)
    {
        pEnemy->Value().Update();
        pEnemy = pEnemy->Next();
    }

    // Update all rain drops
	List<RainDrop> * pRainDrops = m_pRainDropManager->GetList();
    List<RainDrop>::Node * pRainDrop = pRainDrops->First();
	List<RainDrop>::Node * pRainDropToDelete = NULL;

    while (pRainDrop)
    {
        pRainDrop->Value().Update();
        pRainDrop = pRainDrop->Next();
    }
}

void Game::Draw()
{
	// Head the line
    ClearScreen();

	// Draw each character of the world
    for (unsigned int actual_x = m_iMinWidth; actual_x < m_iMaxWidth; actual_x++)
    {
		// Set draw entity to NULL
		Entity * pToBeDrawn = NULL;

		// Draw hero
		if (m_pHero->GetX() == actual_x)
			pToBeDrawn = m_pHero;

		// Draw bullet
		if (!pToBeDrawn) 
		{
			List<Bullet> * pBullets = m_pBulletManager->GetList();
			List<Bullet>::Node * pBullet = pBullets->First();

			while (pBullet)
			{
				if (pBullet->Value().GetX() == actual_x) {
					pToBeDrawn = &pBullet->Value();

					// Break because there is one bullet found
					break;
				}

				pBullet = pBullet->Next();
			}
		}

        // Draw enemy
		if (!pToBeDrawn) 
		{
            // Update all enemies
	        List<Enemy> * pEnemies = m_pEnemyManager->GetList();
            List<Enemy>::Node * pEnemy = pEnemies->First();
	        List<Enemy>::Node * pEnemyToDelete = NULL;

            while (pEnemy)
            {
                if (pEnemy->Value().GetX() == actual_x) {
					pToBeDrawn = &pEnemy->Value();

					// Break because there is one enemy found
					break;
				}

				pEnemy = pEnemy->Next();
            }
        }

        // Draw rain drop
		if (!pToBeDrawn) 
		{
            // Update all rain drops
	        List<RainDrop> * pRainDrops = m_pRainDropManager->GetList();
            List<RainDrop>::Node * pRainDrop = pRainDrops->First();
	        List<RainDrop>::Node * pRainDropToDelete = NULL;

            while (pRainDrop)
            {
                if (pRainDrop->Value().GetX() == actual_x) {
					pToBeDrawn = &pRainDrop->Value();

					// Break because there is one bullet found
					break;
				}

				pRainDrop = pRainDrop->Next();
            }
        }

		// If nothing has been found, print empty else print entity
		if (pToBeDrawn)
			pToBeDrawn->Draw();
		else
			printf("%c", WORLD_BLANK_AVATAR);
    }
		
	// EVADE ULTRA-HYPER-MEGA-FAST-SPEED
    Sleep(80);
}