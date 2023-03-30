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
	return game.board[x][y] != " ";
}

bool hasBomb(int x, int y, Game game){
	return game.board[x][y] == "x";
}

void initBoard(Game *game){
	game->board = new string*[DIMENSION];
	for(int x=0;x < DIMENSION;++x){
		game->board[x]=new string[DIMENSION];
	}
}

void initGame(Game *game){
	initBoard(game);
	game->player = "1";

	for(int x=0;x < DIMENSION;++x){
		for(int y=0;y < DIMENSION;++y){
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


void moveSoldier(int srcX, int srcY, int destX, int destY, Game *game){
	if (!hasEnemy(destX, destY, *game)){
		if (!hasBomb(destX, destY, *game)){
			setBomb(srcX, srcY, game);
			game->board[destX][destY] = game->player;
			switchPlayer(game);
		}
	}
}

void switchPlayer(Game *game){
	string currentPlayer = game->player;
	game->player = (currentPlayer == "1") ? "2": "1";
	cout << "Switched Player" << currentPlayer << " to Player"<< game->player;
}

void killSoldier(int x, int y, Game *game){
	game->board[x][y] = " ";
}

void setBomb(int x, int y, Game *game){
	game->board[x][y] = "x";
}
