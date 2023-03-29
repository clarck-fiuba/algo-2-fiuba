/*
 * ui.cpp
 *
 *  Created on: Mar 28, 2023
 *      Author: clarck
 */
#include "ui.h"


std::string* getUserInput(const char * prompt){
	std::string* args = new std::string[MAX_ARGS];
	std::cout << prompt << std::endl << "> ";
	for(int i = 0; i < MAX_ARGS; ++i){
		std::cin >> args[i];
	}
	return args;
}
