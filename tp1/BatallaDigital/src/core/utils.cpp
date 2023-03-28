/*
 * utils.cpp
 *
 *  Created on: Mar 28, 2023
 *      Author: clarckmonclair
 */

#include "utils.h"


void printStrArray(std::string args[]){
	int size = sizeof(args) / sizeof(std::string);
	std::cout << "[";
	for (int i=0; i< size; ++i){
		std::cout << args[i] << ",";
	}
	std::cout << "]"<<std::endl;
}
