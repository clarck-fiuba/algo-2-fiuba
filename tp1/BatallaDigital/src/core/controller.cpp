/*
 * controller.cpp
 *
 *  Created on: Mar 28, 2023
 *      Author: clarckmonclair
 */

#include "controller.h"

void run(){
	bool quitGame = false;
	std::string input = "";
	std::string args[MAX_ARGS] = {};
	do{
		input = getUserInput("Enter a command:");
		if (input == "q" || input == "quit"){
			quitGame = true;
			std::cout<<"Quitting game...!\n";
		}else{
			execute(args);
		}
	}while(!quitGame);
}

void execute(std::string args[]){
	std::cout<<"running game...!\n";
	printStrArray(args);
}

