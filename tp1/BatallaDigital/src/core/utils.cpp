/*
 * utils.cpp
 *
 *  Created on: Mar 28, 2023
 *      Author: clarckmonclair
 */

#include "utils.h"


bool isValidPosition(int pos[], int dimension){
	if ((pos[0] < 0 || pos[0] > dimension-1) ||
		(pos[1] < 0 || pos[1] > dimension-1)) {
		return false;
	}
	return true;
}

void printStrArray(std::string args[], int size){
	std::cout << "[";
	for (int i=0; i< size; ++i){
		std::cout << args[i] << ",";
	}
	std::cout << "]"<<std::endl;
}

void printIntArray(int args[], int size){
	std::cout << "[";
	for (int i=0; i< size; ++i){
		std::cout << args[i] << ",";
	}
	std::cout << "]"<<std::endl;
}

