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
#include "../../views/views.h"

void executeBoard(std::string * args, Game game);

void executePlay(std::string * args, Game *game);

void executeImport(std::string * args, Game *game);

void executeSave(std::string * args, Game *game);


#endif /* FEATURES_GAMEPLAY_GAMEPLAY_H_ */
