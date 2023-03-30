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
	std::cout << "usage:\n\t"
				 "v,version:\t Display the software version\n\t"
				 "h,help   :\t Show list of commands\n\t"
				 "p,play   :\t Move a soldier\n\t"
				 "b,board  :\t Display board and score\n\t"
				 "s,save   :\t Save the current game in a file\n\t"
				 "i,import :\t Import a game from a file\n\t"
				 "q,quit   :\t Quit game\n\n\t"
				 "<command> [<args>]\n\n";
}

void displayBoard(string **board, int dimension){
	for(int x=0;x<dimension;++x){
		for(int y=0;y<dimension;++y){
			cout << "|" << board[x][y];
		}
		cout << endl;
	}
}
