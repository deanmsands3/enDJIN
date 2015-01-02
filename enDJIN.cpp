//============================================================================
// Name        : enDJIN.cpp
// Author      : Dean M. Sands, III
// Version     :
// Copyright   : I will set your lawn flamingos on fire.
// Description : Hello World in C, Ansi-style
//============================================================================

#include "Engine/Game.h"
#include <boost/filesystem.hpp>
const std::string indexFile="index.json";
int main(int argc, char *argv[]) {
	//Setup Logging
	FILE* pLogFile;
	try
	{
		pLogFile=std::fopen("LogTest.log", "a");
		if(pLogFile==NULL) throw std::runtime_error("Could not create log file.");
		Output2FILE::Stream() = pLogFile;
		FILELog::ReportingLevel() = FILELog::FromString("DEBUG1");
	}catch(std::exception &e){
		std::cerr<<e.what()<<std::endl;
		return FAILURE;
	}
	//Run the game
	try{
		enDJIN::Game *theGame = new enDJIN::Game(indexFile);
		delete theGame;
	}catch (const std::exception& e)
	{
		FILE_LOG(logERROR) << e.what() <<std::endl;
		fclose(pLogFile);
		return FAILURE;
	}
	return SUCCESS;
}
