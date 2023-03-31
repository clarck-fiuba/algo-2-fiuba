/*
 * game.h
 *
 *  Created on: Mar 29, 2023
 *      Author: clarck
 */

#ifndef FEATURES_GAMEPLAY_GAME_H_
#define FEATURES_GAMEPLAY_GAME_H_

#include <iostream>
#include <fstream>


#define DIMENSION 20
#define MAX_SOLDIER 4
#define MAX_PLAYER 2

using namespace std;


struct Game {
	string board[DIMENSION][DIMENSION];
	int lockTimer[DIMENSION][DIMENSION];
	int score[MAX_PLAYER];
	int soldiers[MAX_PLAYER];
	string player;
	string winner;
};

bool isPosLock(int pos[2], Game game);

bool hasEnemy(int pos[2], Game game);

bool hasBomb(int pos[2], Game game);

bool hasSoldier(int pos[2], Game game);

bool hasMate(int pos[2], Game game);

bool hasWinner(Game game);

bool moveSoldier(int src[2], int dest[2], Game *game);

void killSoldier(string player, Game *game);

void setBomb(int pos[2], Game *game);

void initGame(Game *game);

void switchPlayer(Game *game);

void onQuitGameSession(Game game);

void updateLockTimer(int pos[2], int count, Game *game);

void decreaseLockTimer(Game *game);

void updateScore(string player, Game *game);

void updateWinner(Game *game);

void clearPosition(int pos[2], Game *game);

void exportGame(Game game);

void lockPath(int pos[2], Game *game);


#endif /* FEATURES_GAMEPLAY_GAME_H_ */
