//============================================================================
// Name        : BatallaDigital.cpp
// Author      : mclarck
// Version     :
// Copyright   : All rights reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "core/ui.h"
#include "views/views.h"
#include "features/help/help.h"
#include "features/gameplay/gameplay.h"

int main() {
	Game game;
	std::string command;
	bool quitGame = false;
	std::string input[1];
	initGame(&game);
	displayBanner();
	std::cout << "Enter a command:\n" ;
	do{
		std::cout << "> ";
		getUserStrInput(input);
		command = input[0];
		if (input[0] == "q" || command == "salir"){
			quitGame = true;
			std::cout << "Saliendo del game!\n";
		}else if (command == "h" || command == "ayuda"){
			executeHelp(input);
		}else if (command == "v" || command == "version"){
			executeVersion(input);
		}else if (command == "b" || command == "tablero"){
			executeBoard(input, game);
		}else if (command == "p" || command == "play"){
			executePlay(input, &game);
		}else{
			cout << "Comando no encontrado\n";
		}
	}while(!quitGame);

	return 0;
}
