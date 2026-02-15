cmake_minimum_required (VERSION 3.10)
project(enDJIN
	VERSION 0.0.0.1
	LANGUAGES CXX
)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(CMAKE_CXX_STANDARD 20)

#Executable
add_executable (enDJIN enDJIN.cpp)
set_property(TARGET enDJIN PROPERTY CXX_STANDARD 20)

#Link in dependency libraries
set(Engine_LIBS enDJIN_Engine)

## SFML
### Configure SFML
set(SFML_STATIC_LIBRARIES FALSE CACHE BOOL "Use static SFML librares")
### General compiler options
if (SFML_STATIC_LIBRARIES)
	target_compile_definitions(enDJIN PRIVATE -DSFML_STATIC)
endif()

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

## Link libraries

find_package(Boost COMPONENTS system REQUIRED CONFIG)
find_package(jsoncpp  REQUIRED)

target_include_directories(enDJIN PRIVATE ${SFML_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS} ${JSONCPP_INCLUDE_DIRS})

#Subfolders
add_subdirectory (Util)
add_subdirectory (Engine)
# add_subdirectory (Entities)
add_subdirectory (ResourceManagement)
add_subdirectory (Tiles)



target_link_libraries(enDJIN PRIVATE
	${Engine_LIBS}
	sfml-system
	sfml-window
	sfml-graphics
	sfml-network
	sfml-audio
	enDJIN_Util
	JsonCpp::JsonCpp
	${Boost_LIBRARIES}
)
