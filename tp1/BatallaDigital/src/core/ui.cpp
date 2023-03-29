/*
 * ui.cpp
 *
 *  Created on: Mar 28, 2023
 *      Author: clarck
 */
#include "ui.h"


std::string * getUserInput(){
	std::string * args = new std::string[MAX_ARGS];
	std::cin >> args[0];

	if (args[0] == "p" || args[0] == "play"){
		std::cout << args[0] << std::endl;
		std::cin >> args[1];
		std::cin >> args[2];
		std::cin >> args[3];
	}

	return args;
}
