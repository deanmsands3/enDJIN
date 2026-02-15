set(gamescreens_SOURCE_FILES
	GameScreen.cpp
	GameScreenFactory.cpp
	GameScreenFactory.h
	GameScreen.h
	GameScreens.h
	LoadingScreen.cpp
	LoadingScreen.h
	MenuScreen.cpp
	MenuScreen.h
	PlayScreen.cpp
	PlayScreen.h
	SplashScreen.cpp
	SplashScreen.h
)
add_library(enDJIN_GameScreens ${gamescreens_SOURCE_FILES})
target_include_directories(enDJIN_GameScreens  PRIVATE ${SFML_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS} ${JSONCPP_INCLUDE_DIRS})

