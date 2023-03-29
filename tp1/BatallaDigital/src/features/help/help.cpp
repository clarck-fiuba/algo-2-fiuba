/*
 * help.cpp
 *
 *  Created on: Mar 28, 2023
 *      Author: clarckmonclair
 */

#include "help.h"


void executeHelp(std::string * args){
	displayUsage();
}


void executeVersion(std::string * args){
	std::cout << "v1.0.0" << std::endl;
}
