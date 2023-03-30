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


#define MAX_ARGS 4

std::string* getUserStrInput(int maxArgs);
int * getUserIntInput(int maxArgs);

#endif /* UI_UI_H_ */
