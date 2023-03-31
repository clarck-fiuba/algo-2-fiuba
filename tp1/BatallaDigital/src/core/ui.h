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



void getUserStrInput(string args[]);
void getUserIntInput(int args[]);
void getBoardPosition(string prompt, int position[], int dimension);

#endif /* UI_UI_H_ */
