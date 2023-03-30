/*
 * game.cpp
 *
 *  Created on: Mar 29, 2023
 *      Author: clarck
 */

#include "game.h"



bool isPosLock(int pos[2], Game game){
	return game.lockTimer[pos[0]][pos[1]] > 0;
}

bool hasSoldier(int pos[2], Game game){
	return game.board[pos[0]][pos[1]] == game.player;
}

bool hasEnemy(int pos[2], Game game){
	string occupant = game.board[pos[0]][pos[1]];
	return occupant != game.player && occupant != " " && occupant != "x";
}

bool hasBomb(int pos[2], Game game){
	return game.board[pos[0]][pos[1]] == "x";
}

bool hasWinner(Game game){
	return game.winner != "";
}

void initBoard(Game *game){
	game->board = new string*[DIMENSION];
	for(int x=0;x < DIMENSION;++x){
		game->board[x]=new string[DIMENSION];
	}
}

void initLockTimer(Game *game){
	game->lockTimer = new int*[DIMENSION];
	for(int x=0;x < DIMENSION;++x){
		game->lockTimer[x]=new int[DIMENSION];
	}
}

void initGame(Game *game){
	initBoard(game);
	initLockTimer(game);

	game->player = "1";
	game->score = new int[MAX_PLAYER];

	for(int x=0;x < DIMENSION;++x){
		for(int y=0;y < DIMENSION;++y){
			game->board[x][y]=" ";
		}
	}

	int offset = (DIMENSION - MAX_SOLDIER) / 2;
	for(int i = 0; i < MAX_SOLDIER; ++i){
		int pos = i + offset;
		game->board[0][pos] = "1";
		game->board[DIMENSION-1][pos] = "2";
	}

}


bool moveSoldier(int src[2], int dest[2], Game *game){
	if(hasEnemy(dest, *game)){
		cout << "Enemy detected, both soldier will died!!!\n";
		killSoldier(src, game);
		killSoldier(dest, game);
	}else if(hasBomb(dest, *game)){
		cout << "!!!Explosion!!!, soldier died!!!";
		killSoldier(src, game);
		killSoldier(dest, game);
		updateLockTimer(dest, 5, game);
	}else{
		setBomb(src, game);
		game->board[dest[0]][dest[1]] = game->player;
	}
	return true;
}

void switchPlayer(Game *game){
	string currentPlayer = game->player;
	game->player = (currentPlayer == "1") ? "2": "1";
	//cout << "Switched Player" << currentPlayer << " to Player"<< game->player << endl;
}

void killSoldier(int pos[2], Game *game){
	game->board[pos[0]][pos[1]] = " ";
}

void setBomb(int pos[2], Game *game){
	game->board[pos[0]][pos[1]] = "x";
}

void onQuitGameSession(Game game){
	cout << "Player " << game.player << " abandoned\n";
	if (game.winner == ""){
		cout << "No winner!!!\n";
	}else{
		cout << "Player " << game.winner << " win!!!\n";
	}
}

void updateLockTimer(int pos[2], int count, Game *game){
	game->lockTimer[pos[0]][pos[1]] = count;
}

void decreaseLockTimer(Game *game){
	for(int x=0;x<DIMENSION;++x){
		for(int y=0;y<DIMENSION;++y){
			if (game->lockTimer[x][y] > 0) {
				game->lockTimer[x][y] -= 1;
			}
		}
	}
}


void updateScore(string player, Game *game){
	if (player == "1") {
		game->score[0] +=1;
	}else if (player=="2"){
		game->score[1] +=1;
	}
}



void updateWinner(Game *game){
	if (game->score[0]>3) {
		game->winner = "1";
	}else if (game->score[1]>3){
		game->winner = "2";
	}
}
