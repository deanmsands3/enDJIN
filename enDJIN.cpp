//============================================================================
// Name        : enDJIN.cpp
// Author      : Dean M. Sands, III
// Version     :
// Copyright   : I will set your lawn flamingos on fire.
// Description : Hello World in C, Ansi-style
//============================================================================

#include "Engine/Game.h"
#include <boost/filesystem.hpp>
const std::string indexFile="Data/index.json";
int main(int argc, char *argv[]) {

	enDJIN::Game *theGame = new enDJIN::Game(indexFile);
	delete theGame;
	return 0;
}
