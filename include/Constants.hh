//
// Created by tonell_m on 21/01/17.
//

#ifndef BASIC_CONSTANTS_HPP
#define BASIC_CONSTANTS_HPP

#include <string>

const int TILE_WIDTH = 64;
const int TILE_HEIGHT = 64;
const int CHARACTER_HEIGHT = 1 * TILE_HEIGHT;
const int CHARACTER_WIDTH = 1 * TILE_WIDTH;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 15 * TILE_HEIGHT;

const float CHAR_SPEED = 0.166666;

const std::string WINDOW_NAME = "Global Game Jam 2017";

const std::string MAP_PATH = "resources/map.tmx";

const std::string BACKGROUND_PATH = "resources/background.png";
const double BACKGROUND_SCROLLING = 0.5f;
const int FOREGROUND_SCROLLING = 3;


const int SPELL_COOLDOWN = 60;
const int SPELL_DEFAULT_POWER = 10;
const int PLAYER_START_X = 0;
const int PLAYER_START_Y = 0;

typedef enum {
	STILL,
	GOLEFT,
	GORIGHT,
	GOUP
} Move;

typedef enum {
	NONE,
	ATTRACT,
	REPULSE
} Spell_;

#endif //BASIC_CONSTANTS_HPP
