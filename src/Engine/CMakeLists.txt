add_subdirectory(Audio)
add_subdirectory(Events)
add_subdirectory(GameScreens)

set(Engine_SOURCE_FILES
	ConfigParser.cpp
	ConfigParser.h
	DataParser.cpp
	DataParser.h
	Engine.h
	EventProcessor.cpp
	EventProcessor.h
	Game.cpp
	Game.h
	KeyMappings.cpp
	KeyMappings.h
	Level.cpp
	Level.h
	TileEngine.cpp
	TileEngine.h
	TileMap.cpp
	TileMap.h
)
add_library(server ${Engine_SOURCE_FILES})
target_link_libraries (Engine Audio)
target_link_libraries (Engine Events)
target_link_libraries (Engine GameScreens)
target_link_libraries (Engine Util)
target_link_libraries (Engine Entities)
target_link_libraries (Engine ResourceManagement)
target_link_libraries (Engine Tiles)

