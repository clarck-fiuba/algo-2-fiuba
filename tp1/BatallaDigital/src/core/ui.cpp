/*
 * ui.cpp
 *
 *  Created on: Mar 28, 2023
 *      Author: clarck
 */

#include <string>
#include <iostream>

std::string getUserInput(const char * prompt){
	std::string input="";
	std::cout << prompt << std::endl << "> ";
	std::cin >> input;
	std::cout << std::endl;
	return input;
}
