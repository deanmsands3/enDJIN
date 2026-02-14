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
add_library(enDJIN_Engine ${Engine_SOURCE_FILES})
target_link_libraries (enDJIN_Engine enDJIN_Audio)
target_link_libraries (enDJIN_Engine enDJIN_Events)
target_link_libraries (enDJIN_Engine enDJIN_GameScreens)
target_link_libraries (enDJIN_Engine enDJIN_Util)
# target_link_libraries (enDJIN_Engine enDJIN_Entities)
target_link_libraries (enDJIN_Engine enDJIN_ResourceManagement)
target_link_libraries (enDJIN_Engine enDJIN_Tiles)

