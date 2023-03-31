/*
 * views.h
 *
 *  Created on: Mar 28, 2023
 *      Author: clarckmonclair
 */

#ifndef VIEWS_VIEWS_H_
#define VIEWS_VIEWS_H_

using namespace std;

void displayUsage();

void drawLine();

void displayBanner();

void displayBoard(string  board[][20], int dimension);

void displayTable(string items[]);

void displayScore(int * score, int maxPlayer);

void displayCoordinates(int coords[2]);


#endif /* VIEWS_VIEWS_H_ */
