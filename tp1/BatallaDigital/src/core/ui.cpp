/*
 * ui.cpp
 *
 *  Created on: Mar 28, 2023
 *      Author: clarck
 */
#include "ui.h"


std::string * getUserStrInput(int maxArgs){
	std::string * args = new std::string[maxArgs];
	std::cin >> args[0];
	return args;
}



int * getUserIntInput(int maxArgs){
	int * args = new int[maxArgs];
	std::cin >> args[0];
	return args;
}

int * getBoardPosition(string prompt, int dimension){
	int * position = new int[2];
	do{
		cout << prompt;
		cin >> position[1] >> position[0];
		if (!cin){
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid Input\n\n";
			continue;
		}
		position[0]-=1;
		position[1]-=1;
		if(!isValidPosition(position, dimension)) cout << "Invalid Position\n\n";
	}while(!isValidPosition(position, dimension));

	return position;
}
