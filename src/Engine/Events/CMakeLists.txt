set(events_SOURCE_FILES
	Event.cpp
	Event.h
	EventHandler.cpp
	EventHandler.h
	Events.h
	EventTriggerHandler.cpp
	EventTriggerHandler.h
)
add_library(Events ${events_SOURCE_FILES})
