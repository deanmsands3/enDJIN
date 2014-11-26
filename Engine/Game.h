/*
 * Game.h
 *
 *  Created on: Aug 24, 2014
 *      Author: Dean
 */

#ifndef GAME_H_
#define GAME_H_
#include "Types.h"
#include <SFGUI/SFGUI.hpp>
#include <SFML/Graphics.hpp>
#include <Thor/Particles/ParticleSystem.hpp>
#include <Thor/Particles/EmissionInterface.hpp>
#include <Thor/Vectors/PolarVector.hpp>
#include <Thor/Math/Random.hpp>
#include <Thor/Time/CallbackTimer.hpp>
#include "ConfigParser.h"
#include "GameScreenFactory.h"
namespace enDJIN{
	class Game {
		ConfigParser *config;
		sf::RenderWindow *renderWin;
		GameScreenFactory *gsf;
	public:
		Game(const std::string &index_json);
		virtual ~Game();
	};
};
#endif /* GAME_H_ */
