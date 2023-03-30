/*
 * ui.h
 *
 *  Created on: Mar 28, 2023
 *      Author: clarck
 */

#ifndef UI_UI_H_
#define UI_UI_H_

#include <string>
#include <iostream>
#include "utils.h"



std::string* getUserStrInput(int maxArgs);
int * getUserIntInput(int maxArgs);
int * getBoardPosition(string prompt, int dimension);

#endif /* UI_UI_H_ */
