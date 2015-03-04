//============================================================================
// Name        : enDJIN.cpp
// Author      : Dean M. Sands, III
// Version     :
// Copyright   : I will set your lawn flamingos on fire.
// Description : Hello World in C, Ansi-style
//============================================================================

#include <boost/filesystem.hpp>
#include "Engine/Game.h"
const std::string indexFile="index.json";
const std::string loggingFile="enDJIN.log";
int main(int argc, char *argv[]) {
	return
			//Enable logging
			(enDJIN::Game::enableLogging(loggingFile)==FAILURE)?
					FAILURE:
			//Game on!
					enDJIN::Game::gameOn(indexFile);


}
