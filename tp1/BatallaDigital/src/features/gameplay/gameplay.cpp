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
	cout << "Playing\n";
	moveSoldier(0, 8, 1, 8, "1", game);
	displayBoard(game->board, DIMENSION);
}

void executeImport(std::string *args, Game *game){
	cout << "Import\n";
}

void executeSave(std::string *args, Game *game){
	cout << "Save\n";
}
