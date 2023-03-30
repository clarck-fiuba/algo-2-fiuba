/*
 * game.cpp
 *
 *  Created on: Mar 29, 2023
 *      Author: clarck
 */

#include "game.h"



bool isPositionLock(){
	return true;
}

bool hasEnemy(int x, int y, Game game){
	return game.board[x][y] != " " && game.board[x][y] != "x";
}

bool hasBomb(int x, int y, Game game){
	return game.board[x][y] == "x";
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
	int offset = (DIMENSION - MAX_SOLDIER) / 2;
	for(int i = 0; i < MAX_SOLDIER; ++i){
		int pos = i + offset;
		game->board[0][pos] = "1";
		game->board[19][pos] = "2";
	}

}


void moveSoldier(int srcX, int srcY, int destX, int destY, string player, Game *game){
	if (!hasEnemy(srcX, srcY, *game)){
		if (!hasBomb(srcX, srcY, *game)){
			setBomb(srcX, srcY, game);
			game->board[destX][destY] = player;
		}
	}
}

void killSoldier(int x, int y, Game *game){
	game->board[x][y] = " ";
}

void setBomb(int x, int y, Game *game){
	game->board[x][y] = "x";
}
