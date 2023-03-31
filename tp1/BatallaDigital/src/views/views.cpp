/*
 * views.cpp
 *
 *  Created on: Mar 28, 2023
 *      Author: clarckmonclair
 */

#include <iostream>
#include "views.h"



void drawLine(int size){
	for (int i=0;i<size;++i){
		std::cout<<"=";
	}
	std::cout<<std::endl;
}

void displayBanner(){
	drawLine(50);
	std::cout<<"Batalla Digital"<<std::endl;
	drawLine(50);
	std::cout<<std::endl;
}

void displayUsage(){
	std::cout << "uso:\n"
					"v,version:\t Muestra la versión del software\n"
					"h,ayuda:\t Mostrar lista de comandos\n"
					"p,play :\t Inicia el juego\n"
					"b,tablero:\t Mostrar tablero y puntuación\n"
					"q,salir:\t Salir del juego\n\n"
					"<comando> [<argumentos>]\n\n";
}

void displayBoard(string board[][20], int dimension){
	cout << endl;
	for(int x=0;x < dimension;++x){
		for(int y=0;y < dimension;++y){
			cout << "|" << board[x][y] << "";
		}
		cout << "|"<< endl;
	}
	cout << endl;
}

void displayCoordinates(int coords[2]){
	cout << "("<< coords[0]<<","<< coords[1]<<")\n";
}


void displayScore(int * score, int maxPlayer){
	drawLine(40);
	for (int i = 0; i < maxPlayer; ++i){
		cout << "Player"<< i + 1 << ": "<< score[i] << endl;
	}
	drawLine(40);
}
