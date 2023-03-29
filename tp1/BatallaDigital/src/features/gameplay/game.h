/*
 * game.h
 *
 *  Created on: Mar 29, 2023
 *      Author: clarck
 */

#ifndef FEATURES_GAMEPLAY_GAME_H_
#define FEATURES_GAMEPLAY_GAME_H_

#include <iostream>

struct {
	std::string ** board[][] = {{""}};
	int ** lockTimer[][] = {{0}};
} Game;


bool isPositionLock();

bool hasEnemy();

bool hasBomb();

void moveSoldier();

void killSoldier();

void setBomb();

#endif /* FEATURES_GAMEPLAY_GAME_H_ */
