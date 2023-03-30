/*
 * gameplay.cpp
 *
 *  Created on: Mar 28, 2023
 *      Author: clarckmonclair
 */

#include "gameplay.h"


void executeBoard(std::string *args, Game game){
	displayBoard(game.board, DIMENSION);
}

void executePlay(std::string *args, Game *game){
	bool gameOver = false;
	int * srcPosition = new int[2];
	int * destPosition = new int[2];

	do{
		displayScore(game->score, MAX_PLAYER);
		displayBoard(game->board, DIMENSION);
		srcPosition = getBoardPosition("Player"+game->player+" : Select your soldier (ctrl+c to quit): \n> ", DIMENSION);
		if (!hasSoldier(srcPosition, *game)){
			cout << "No soldier found at this position for Player"<< game->player;
		}else{
			destPosition = getBoardPosition("\nSelect new position (ctrl+c to quit): \n> ", DIMENSION);
			if(moveSoldier(srcPosition,destPosition, game)){
				switchPlayer(game);
				decreaseLockTimer(game);
			}
			updateWinner(game);
			if (hasWinner(*game)){
				displayScore(game->score, MAX_PLAYER);
				displayBoard(game->board, DIMENSION);
				cout << "Player" << game->winner << " WIN!!!!\n";
				cout << "GAME OVER!\n";
				initGame(game);
				gameOver = true;
			}
		}
	}while(!gameOver);
}

void executeImport(std::string *args, Game *game){
	cout << "Import\n";
}

void executeSave(std::string *args, Game *game){
	cout << "Save\n";
}
