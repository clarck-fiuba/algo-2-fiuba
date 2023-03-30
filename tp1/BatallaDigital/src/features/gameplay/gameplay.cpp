/*
 * gameplay.cpp
 *
 *  Created on: Mar 28, 2023
 *      Author: clarckmonclair
 */

#include "gameplay.h"

void onQuitGameSession(Game game){
	cout << "Player " << game.player << " abandoned\n";
	if (game.winner == ""){
		cout << "No winner!!!\n";
	}else{
		cout << "Player " << game.winner << " win!!!\n";
	}
}

void executeBoard(std::string *args, Game game){
	displayBoard(game.board, DIMENSION);
}

void executePlay(std::string *args, Game *game){
	bool keep = true;
	int * srcPosition = new int[2];
	int * destPosition = new int[2];
	int step = 0;
	do{
		displayBoard(game->board, DIMENSION);

		cout <<"Player "<< game->player << "\nSelect your soldier (-1 to quit): \n> ";
		cin >> srcPosition[0];

		if (srcPosition[0] < 0) {
			onQuitGameSession(*game);
			break;
		}

		cin >> srcPosition[1];
		cout << "\nSelect new position (-1 to quit): \n> ";
		cin >> destPosition[0];

		if (destPosition[0] < 0) {
			onQuitGameSession(*game);
			break;
		}

		cin >> destPosition[1];

		moveSoldier(srcPosition[0], srcPosition[1], destPosition[0], destPosition[0], game);
//		displayBoard(game->board, DIMENSION);

		cout << "switching player\n";
		switchPlayer(game);

		++step;
		keep = step <= 2;
	}while(keep);
}

void executeImport(std::string *args, Game *game){
	cout << "Import\n";
}

void executeSave(std::string *args, Game *game){
	cout << "Save\n";
}
