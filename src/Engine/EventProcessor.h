/*
 * EventProcessor.h
 *
 *  Created on: Jan 5, 2015
 *      Author: Dean
 */

#ifndef SRC_ENGINE_EVENTPROCESSOR_H_
#define SRC_ENGINE_EVENTPROCESSOR_H_
#include "Events/Events.h"
#include <boost/lockfree/queue.hpp>
namespace enDJIN {

class EventProcessor {
protected:
	enDJIN::EventHandler *_eventHandler;
	boost::lockfree::queue<enDJIN::Event, boost::lockfree::capacity<32>> _messagePump;

public:
	virtual bool processQueue();
	bool getNextEvent(enDJIN::Event &nextEvent);
	bool pushEvent(const enDJIN::Event& newEvent);
	EventProcessor();
	virtual ~EventProcessor();
	const enDJIN::EventHandler* getEventHandler() const;
	void setEventHandler(enDJIN::EventHandler* eventHandler);
};

} /* namespace enDJIN */

#endif /* SRC_ENGINE_EVENTPROCESSOR_H_ */
