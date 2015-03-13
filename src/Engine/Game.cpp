/*
 * Game.cpp
 *
 *  Created on: Aug 24, 2014
 *      Author: Dean
 */

#include "Game.h"

namespace enDJIN{
//bool Game::enableLogging(std::string logFileName){
//	try
//	{
//		pLogFile=std::fopen(logFileName.c_str(), "a");
//		if(pLogFile==NULL) throw std::runtime_error("Could not create log file.");
//		Output2FILE::Stream() = pLogFile;
//		FILELog::ReportingLevel() = FILELog::FromString("DEBUG1");
//		FILE_LOG(logINFO)<<"Logger started"<<std::endl;
//	}catch(std::exception &e){
//		std::cerr<<e.what()<<std::endl;
//		return FAILURE;
//	}
//	return SUCCESS;
//}
bool Game::enableLogging(std::string logFileName){
	try
	{
	    logging::add_file_log
	    (
	        keywords::file_name = "enDJIN_%N.log",                                        /*< file name pattern >*/
	        keywords::rotation_size = 10 * 1024 * 1024,                                   /*< rotate files every 10 MiB... >*/
	        keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0), /*< ...or at midnight >*/
	        keywords::format = "[%TimeStamp%]: %Message%"                                 /*< log record format >*/
	    );

	    logging::core::get()->set_filter
	    (
	        logging::trivial::severity >= logging::trivial::info
	    );
	    logging::add_common_attributes();


	}catch(std::exception &e){
		std::cerr<<e.what()<<std::endl;
		return FAILURE;
	}
	return SUCCESS;
}


bool Game::gameOn(std::string index_xml) {
	//Run the game
	try{
		enDJIN::Game *theGame = enDJIN::Game::init(index_xml);
		delete theGame;
	}catch (const std::exception& e)
	{

		return FAILURE;
	}
	return SUCCESS;
}
Game::Game(const std::string &index_json) {
	setup(index_json);
	loop();
}

const Game* Game::getInstance() {
	if(Game::_instance==nullptr) throw std::runtime_error("Game Object not initialized!");
	return (const Game*)Game::_instance;
}

Game* Game::init(const std::string& index_json) {
	if(Game::_instance==nullptr){Game::_instance=new Game(index_json);}
	return Game::_instance;
}

Game::~Game() {
	delete gsf;
	renderWin->close();
	delete renderWin;
	delete config;
	delete dataparser;
}

void Game::setup(const std::string &index_json){
	DataParser::setDataFolder("Data");
	dataparser=new DataParser(index_json);
	// Initialize the Config Parser
	config = new ConfigParser(dataparser->getJSONRoot("config"));
	KeyMappings *keyMap=config->generateKeyMap();
	// Create SFML's window.
	renderWin=new sf::RenderWindow(
			sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ),
			"enDJIN"
			);
	//Determine which gamestate is active
	GameScreen::setDataPath("GameScreens");
//	GameScreen::setDataPath();

	gsf=GameScreenFactory::getInstance(dataparser->getJSONRoot("gamescreens"));

	//Load gamestate
	currentGameScreen=gsf->getInitialGameScreen(renderWin,keyMap);
	delete keyMap;
}
void Game::loop(){
	bool running=true;
	while(running){
		while(currentGameScreen->updateGameScreen()){}
		GameScreen *oldGameScreen=currentGameScreen;
		currentGameScreen=oldGameScreen->getNextGameScreen();
		delete oldGameScreen;
		running =(currentGameScreen!=nullptr);
	}
}

Game* Game::_instance=nullptr;
} //enDJIN namespace
;


