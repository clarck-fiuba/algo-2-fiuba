/*
 * controller.cpp
 *
 *  Created on: Mar 28, 2023
 *      Author: clarckmonclair
 */

#include "controller.h"

void run(){
	bool quitGame = false;
	std::string args[MAX_ARGS] = {};
	do{
		args = getUserInput("Enter a command:");
		if (args[0] == "q" || args[0] == "quit"){
			quitGame = true;
			std::cout<<"Quitting game...!\n";
		}else{
			execute(args);
		}
	}while(!quitGame);
}

void execute(std::string * args){
	std::cout<<"running game...!\n";
//	printStrArray(args);
}

