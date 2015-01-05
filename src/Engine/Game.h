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
#include <SFGUI/SFGUI.hpp>
#include <SFML/Graphics.hpp>
#include <Thor/Particles/ParticleSystem.hpp>
#include <Thor/Particles/EmissionInterface.hpp>
#include <Thor/Vectors/PolarVector.hpp>
#include <Thor/Math/Random.hpp>
#include <Thor/Time/CallbackTimer.hpp>
#include "Util/Util.h"
#include "ConfigParser.h"
#include "DataParser.h"
#include "GameScreens/GameScreens.h"

namespace enDJIN{
	class Game {
		DataParser *dataparser;
		ConfigParser *config;
		sf::RenderWindow *renderWin;
		GameScreenFactory *gsf;
		GameScreen *currentGS;
		void setup(const std::string &index_json);
		void loop();
	public:
		Game(const std::string &index_json);
		virtual ~Game();
	};
};
#endif /* GAME_H_ */
