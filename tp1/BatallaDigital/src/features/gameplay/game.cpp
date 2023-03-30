/*
 * game.cpp
 *
 *  Created on: Mar 29, 2023
 *      Author: clarck
 */

#include "game.h"



bool isPositionLock(){
	Game game;
	return true;
}

bool hasEnemy(){
	return false;
}

bool hasBomb(){
	return false;
}

void initBoard(Game *game){
	game->board =  new string*[DIMENSION];
	for(int x=0;x<DIMENSION;++x){
		game->board[x]=new string[DIMENSION];
	}
}

void initGame(Game *game){
	initBoard(game);
	for(int x=0;x<DIMENSION;++x){
		for(int y=0;y<DIMENSION;++y){
			game->board[x][y]=" ";
		}
	}
}


void moveSoldier(){ }

void killSoldier(){ }

void setBomb(){ }
