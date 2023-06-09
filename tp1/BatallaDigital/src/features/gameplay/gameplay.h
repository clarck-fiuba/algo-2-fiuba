/*
 * gameplay.h
 *
 *  Created on: Mar 28, 2023
 *      Author: clarckmonclair
 */

#ifndef FEATURES_GAMEPLAY_GAMEPLAY_H_
#define FEATURES_GAMEPLAY_GAMEPLAY_H_


#include <iostream>
#include "game.h"
#include "../../core/ui.h"
#include "../../core/utils.h"
#include "../../views/views.h"

using namespace std;

void executeBoard(string * args, Game game);

void executePlay(string * args, Game *game);


#endif /* FEATURES_GAMEPLAY_GAMEPLAY_H_ */
