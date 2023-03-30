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
	std::cout << "Playing...\n";
}

void executeImport(std::string *args, Game *game){

	std::cout << "Import\n";
}

void executeSave(std::string *args, Game *game){
	std::cout << "Save\n";
}
