#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "stdafx.h"

// General configuration file

/// INTERNAL SETTINGS
const char CFG_CLEAR_CHARACTER = '\r';

/// WORLD SETTINGS
const int  WORLD_WIDTH_MAX = 78;
const int  WORLD_WIDTH_MIN = 0;

/// DRAW SETTINGS
const char WORLD_BLANK_AVATAR = ' ';
const char BULLET_AVATAR      = '-';
const char ENEMY_AVATAR       = '@';
const char HERO_AVATAR        = (char)186;

/// DIFFICULTY SETTINGS
const int HERO_SPEED   = 1;
const int ENEMY_SPEED  = 1;
const int BULLET_SPEED = 2;

/// ENVIRONMENT SETTINGS
const int RAIN_PROBABILITY  = 2;
const int ENEMY_PROBABILITY = 70;

/// ANIMATION SETTINGS
const int RAIN_ANIMATION_DELAY  = 2;
const int ENEMY_ANIMATION_DELAY = 2;

/// GAMEPAD SETTINGS
// Exit
const char KEY_EXIT        = 27;
// Movement
const char KEY_LEFT        = 'a';
const char KEY_RIGHT       = 'l';
// Actions
const char KEY_SHOOT_LEFT  = 's';
const char KEY_SHOOT_RIGHT = 'k';

#endif
