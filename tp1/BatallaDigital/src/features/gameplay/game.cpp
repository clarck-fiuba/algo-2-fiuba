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

void initScore(int score[]){
	for (int i=0;i < MAX_PLAYER; ++i){
		score[i] = 0;
	}
}

void initLockTimer(int lock[][DIMENSION]){
	for (int i=0;i < DIMENSION; ++i){
		for (int j=0;j < DIMENSION; ++j){
			lock[i][j] = 0;
		}
	}
}

void initBoard(string board[][DIMENSION]){
	for (int i=0;i < DIMENSION; ++i){
		for (int j=0;j < DIMENSION; ++j){
			board[i][j] = " ";
		}
	}
}

void initSoldier(int soldiers[]){
	for (int i=0;i < MAX_PLAYER; ++i){
		soldiers[i] = MAX_SOLDIER;
	}
}

void initGame(Game *game){
	initScore(game->score);
	initLockTimer(game->lockTimer);
	initBoard(game->board);
	initSoldier(game->soldiers);
	game->player = "1";
	game->winner = "";
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
		clearPosition(src, game);
		clearPosition(dest, game);
		updateScore(game->player, game);
		killSoldier("1", game);
		killSoldier("2", game);
	}else if(hasBomb(dest, *game)){
		cout << "!!!Explosion!!!, soldier died!!!\n";
		clearPosition(src, game);
		clearPosition(dest, game);//clean bomb
		killSoldier(game->player, game);
		updateLockTimer(dest, 5, game);
		updateScore(game->player, game);
	}else{
		setBomb(src, game);
		game->board[dest[0]][dest[1]] = game->player;
	}
	return true;
}

void switchPlayer(Game *game){
	string currentPlayer = game->player;
	game->player = (currentPlayer == "1") ? "2": "1";
}

void clearPosition(int pos[2], Game *game){
	game->board[pos[0]][pos[1]] = " ";
}

void killSoldier(string player, Game *game){
	if (player == "1"){
		game->soldiers[0] -= 1;
	}else if (player == "2"){
		game->soldiers[1] -=1 ;
	}
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
		game->score[1] +=1;
	}else if (player == "2"){
		game->score[0] +=1;
	}
}


void updateWinner(Game *game){
	if (game->soldiers[0] <= 0 || game->soldiers[1] <= 0){
		if (game->score[0] > game->score[1]) {
			game->winner = "1";
		}else if (game->score[0] < game->score[1]){
			game->winner = "2";
		}else{
			game->winner = "";
		}
	}
}

void saveBoardToFile(string suffix, string content){
	string filename = "batalla-digital-"+suffix+".txt";
	ofstream file(filename);
	file << content;
	file.close();
}

string getBoardContent(string player, Game game){
	string content = "";
	for(int x=0;x < DIMENSION;++x){
		for(int y=0;y < DIMENSION;++y){
			string cell = "| ";
			if (game.board[x][y] == player ||
				game.board[x][y] == "x"){
				cell = "|"+game.board[x][y];
			}
			content.append(cell);
		}
		content.append("|\n");
	}
	content.append("\n");
	return content;
}

void exportGame(Game game){
	for(int i=1;i <= MAX_PLAYER; ++i){
		string name = "player" + to_string(i);
		saveBoardToFile(name, getBoardContent(to_string(i), game));
	}
}
