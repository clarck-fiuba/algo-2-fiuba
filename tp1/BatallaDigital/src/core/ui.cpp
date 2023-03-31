/*
 * ui.cpp
 *
 *  Created on: Mar 28, 2023
 *      Author: clarck
 */
#include "ui.h"


void getUserStrInput(string args[]){
	cin >> args[0];
}

void getUserIntInput(int args[]){
	std::cin >> args[0];
}

void getBoardPosition(string prompt, int position[], int dimension){
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

}
