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
	std::cout << "usage:\n"
				 "v,version:\t Display the software version\n"
				 "h,help   :\t Show list of commands\n"
				 "p,play   :\t Move a soldier\n"
				 "b,board  :\t Display board and score\n"
				 "s,save   :\t Save the current game in a file\n"
				 "i,import :\t Import a game from a file\n"
				 "q,quit   :\t Quit game\n\n"
				 "<command> [<args>]\n\n";
}

void displayBoard(string **board, int dimension){
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

void displayTable(string items[]){

}

void displayScore(int * score, int maxPlayer){
	drawLine(20);
	for (int i = 0; i < maxPlayer; ++i){
		cout << "Player"<< i + 1 << ": "<< score[i] << endl;
	}
	drawLine(20);
}
