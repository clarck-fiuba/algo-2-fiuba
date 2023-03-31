/*
 * help.cpp
 *
 *  Created on: Mar 28, 2023
 *      Author: clarckmonclair
 */

#include "help.h"


void executeHelp(string * args){
	cout << "uso:\n"
				 "   v,version:\t Muestra la versión del software\n"
				 "   h,ayuda:\t Mostrar lista de comandos\n"
				 "   p,play :\t Inicia el juego\n"
				 "   b,tablero:\t Mostrar tablero y puntuación\n"
				 "   q,salir:\t Salir del juego\n\n"
				 "   <comando> [<argumentos>]\n\n";
}

void executeVersion(string * args){
	cout << "v1.0.0" << endl;
}
