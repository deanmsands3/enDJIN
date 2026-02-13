/*
 * AudioEngine.h
 *
 *  Created on: Jan 6, 2015
 *      Author: Dean
 */

#ifndef SRC_ENGINE_AUDIO_AUDIOENGINE_H_
#define SRC_ENGINE_AUDIO_AUDIOENGINE_H_
#include "Engine/EventProcessor.h"
namespace enDJIN {

class AudioEngine: public EventProcessor {
public:
	AudioEngine();
	virtual ~AudioEngine();
};

} /* namespace enDJIN */

#endif /* SRC_ENGINE_AUDIO_AUDIOENGINE_H_ */
