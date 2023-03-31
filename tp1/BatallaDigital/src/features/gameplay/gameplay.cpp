/*
 * gameplay.cpp
 *
 *  Created on: Mar 28, 2023
 *      Author: clarckmonclair
 */

#include "gameplay.h"


void executeBoard(std::string *args, Game game){
	displayScore(game.score, MAX_PLAYER);
	displayBoard(game.board, DIMENSION);
}

void executePlay(std::string *args, Game *game){
	bool gameOver = false, bombReady = false;
	int srcPosition[2];
	int destPosition[2];
	int bombPosition[2];
	do{
		displayScore(game->score, MAX_PLAYER);
		displayBoard(game->board, DIMENSION);
		getBoardPosition("Jugador"+game->player+": Coloque su bomba (ctrl+c para salir): \n> ", bombPosition, DIMENSION);
		setBomb(bombPosition, game);
		displayScore(game->score, MAX_PLAYER);
		displayBoard(game->board, DIMENSION);
		bombReady = true;

		updateWinner(game);
		exportGame(*game);
		if (hasWinner(*game)){
			displayScore(game->score, MAX_PLAYER);
			displayBoard(game->board, DIMENSION);
			cout << "Jugador" << game->winner << " ha ganado!!!!\n";
			cout << "GAME OVER!\n";
			initGame(game);
			gameOver = true;
		}
		// solo 2 repeticiones, no voy a crear una funcion

		while(bombReady && !gameOver){
			getBoardPosition("Jugador"+game->player+": Seleccione su soldado (ctrl+c para salir): \n> ", srcPosition, DIMENSION);
			if (!hasMate(srcPosition, *game)){
				cout << "\nNo se encontró ningún soldado en esta posición para el Jugador"<< game->player << endl;
			}else{
				getBoardPosition("Jugador"+game->player+": Seleccionar nueva posición (ctrl+c para salir): \n> ", destPosition, DIMENSION);
				if(moveSoldier(srcPosition,destPosition, game)){
					switchPlayer(game);
					decreaseLockTimer(game);
				}

				updateWinner(game);
				exportGame(*game);
				if (hasWinner(*game)){
					displayScore(game->score, MAX_PLAYER);
					displayBoard(game->board, DIMENSION);
					cout << "Jugador" << game->winner << " ha ganado!!!!\n";
					cout << "GAME OVER!\n";
					initGame(game);
					gameOver = true;
				}

				bombReady=false;

			}
		};

	}while(!gameOver);
}
