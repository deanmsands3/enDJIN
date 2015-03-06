/*
 * Game.h
 *
 *  Created on: Aug 24, 2014
 *      Author: Dean
 */

#ifndef GAME_H_
#define GAME_H_
#include <stdexcept>
#include <boost/filesystem.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
//#include <SFGUI/SFGUI.hpp>
#include <SFML/Graphics.hpp>
#include <Thor/Particles/ParticleSystem.hpp>
#include <Thor/Particles/EmissionInterface.hpp>
#include <Thor/Vectors/PolarVector2.hpp>
#include <Thor/Math/Random.hpp>
#include <Thor/Time/CallbackTimer.hpp>
#include "Util/Util.h"
#include "ConfigParser.h"
#include "DataParser.h"
#include "GameScreens/GameScreens.h"

namespace enDJIN{
	class Game {
		static FILE* pLogFile;
		static bool enableLogging(std::string logFileName);
		static bool gameOn(std::string index_xml);
		static Game *_instance;
		DataParser *dataparser;
		ConfigParser *config;
		sf::RenderWindow *renderWin;
		GameScreenFactory *gsf;
		GameScreen *currentGameScreen;
		void setup(const std::string &index_json);
		void loop();
		Game(const std::string &index_json);
	public:
		static const Game* getInstance();
		static Game* init(const std::string &index_json);
		virtual ~Game();
	};
};
#endif /* GAME_H_ */
