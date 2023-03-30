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
#define MAX_SOLDIER 4

using namespace std;


struct Game {
	string **board;
	int** lockTimer;
	string player;
	string winner;
};

bool isPositionLock(int x, int y, Game *game);

bool hasEnemy(int x, int y, Game game);

bool hasBomb(int x, int y, Game game);

void moveSoldier(int srcX, int srcY, int destX, int destY, Game *game);

void killSoldier(int x, int y, Game *game);

void setBomb(int x, int y, Game *game);

void initGame(Game *game);

void switchPlayer(Game *game);

#endif /* FEATURES_GAMEPLAY_GAME_H_ */
