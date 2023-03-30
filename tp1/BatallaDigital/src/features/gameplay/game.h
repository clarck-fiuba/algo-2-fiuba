/*
 * game.h
 *
 *  Created on: Mar 29, 2023
 *      Author: clarck
 */

#ifndef FEATURES_GAMEPLAY_GAME_H_
#define FEATURES_GAMEPLAY_GAME_H_

#include <iostream>
#define DIMENSION 20

using namespace std;


struct Game{
	string **board;
	int** lockTimer;
};

bool isPositionLock(Game *game);

bool hasEnemy(Game *game);

bool hasBomb(Game *game);

void moveSoldier(Game *game);

void killSoldier(Game *game);

void setBomb(Game *game);

void initGame(Game *game);

#endif /* FEATURES_GAMEPLAY_GAME_H_ */
