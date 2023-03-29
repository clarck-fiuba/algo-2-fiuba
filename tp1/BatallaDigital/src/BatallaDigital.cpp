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
	std::string command;
	bool quitGame = false;
	std::string * input = new std::string[MAX_ARGS];
	std::cout << "Enter a command:\n" ;
	do{
		std::cout << "> ";
		input = getUserInput();
		command = input[0];
		if (input[0] == "q" || command == "quit"){
			quitGame = true;
			std::cout << "Quitting game!\n";
		}else if (command == "h" || command == "help"){
			executeHelp(input);
		}else if (command == "v" || command == "version"){
			executeVersion(input);
		}else if (command == "b" || command == "board"){
			executeBoard(input);
		}else if (command == "p" || command == "play"){
			executePlay(input);
		}else if (command == "s" || command == "save"){
			executeSave(input);
		}else if (command == "i" || command == "import"){
			executeImport(input);
		}

	}while(!quitGame);
	return 0;
}
