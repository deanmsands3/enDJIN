/*
 * AudioEventHandler.h
 *
 *  Created on: Jan 6, 2015
 *      Author: Dean
 */

#ifndef SRC_ENGINE_AUDIO_AUDIOEVENTHANDLER_H_
#define SRC_ENGINE_AUDIO_AUDIOEVENTHANDLER_H_
#include <SFML/Audio.hpp>
#include "Engine/Events/EventHandler.h"
namespace enDJIN {

class AudioEventHandler: public EventHandler {
public:
	AudioEventHandler();
	virtual ~AudioEventHandler();
};

} /* namespace enDJIN */

#endif /* SRC_ENGINE_AUDIO_AUDIOEVENTHANDLER_H_ */
