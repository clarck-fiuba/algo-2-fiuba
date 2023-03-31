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
	displayBanner();
	displayUsage();

	Game game;
	std::string command;
	bool quitGame = false;
	std::string input[1];

	std::cout << "Enter a command:\n" ;

	initGame(&game);

	do{
		std::cout << "> ";
		getUserStrInput(input);
		command = input[0];
		if (input[0] == "q" || command == "quit"){
			quitGame = true;
			std::cout << "Quitting game!\n";
		}else if (command == "h" || command == "help"){
			executeHelp(input);
		}else if (command == "v" || command == "version"){
			executeVersion(input);
		}else if (command == "b" || command == "board"){
			executeBoard(input, game);
		}else if (command == "p" || command == "play"){
			executePlay(input, &game);
		}else if (command == "s" || command == "save"){
			executeSave(input, &game);
		}else if (command == "i" || command == "import"){
			executeImport(input, &game);
		}

	}while(!quitGame);
	return 0;
}
