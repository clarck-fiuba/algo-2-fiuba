/*
 * views.cpp
 *
 *  Created on: Mar 28, 2023
 *      Author: clarckmonclair
 */

#include <iostream>
#include "views.h"



void drawLine(int size){
	for (int i=0;i<size;++i){
		std::cout<<"=";
	}
	std::cout<<std::endl;
}

void displayBanner(){
	drawLine(50);
	std::cout<<"Batalla Digital"<<std::endl;
	drawLine(50);
	std::cout<<std::endl;
}

void displayUsage(){
	std::cout << "usage:\t[-v | --version] [-h | --help] [-p | --play] [-s | --save] [-i | --import] [-q | --quit]\n"
				 "\t<command> [<args>]\n\n";
}
