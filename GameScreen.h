/*
 * GameState.h
 *
 *  Created on: Sep 12, 2014
 *      Author: Dean
 */

#ifndef GAMESCREEN_H_
#define GAMESCREEN_H_
namespace enDJIN{
	class GameScreen {
	public:
		GameScreen();
		virtual ~GameScreen();
		GameScreen *updateGameScreen();
	};
};
#endif /* GAMESCREEN_H_ */
