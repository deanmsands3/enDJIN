//============================================================================
// Name        : enDJIN.cpp
// Author      : Dean M. Sands, III
// Version     :
// Copyright   : I will set your lawn flamingos on fire.
// Description : Hello World in C, Ansi-style
//============================================================================

#include "Game.h"
const std::string indexFile="index.json";
int main(int argc, char *argv[]) {
	Game *theGame = new Game(indexFile);
	delete theGame;
	return 0;
}
