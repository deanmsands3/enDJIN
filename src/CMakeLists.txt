cmake_minimum_required (VERSION 2.8.11)
project(enDJIN_executable)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
include(LibFindMacros)

#INCLUDES = -I /usr/include/python2.7 -I /usr/include/jsoncpp -I  $(SRC_FOLDER)
#TARGET = enDJIN
#SFML_LIBS= -lsfml-system -lsfml-window -lsfml-graphics  -lsfml-network  -lsfml-audio -lsfgui
#UTIL_LIBS= -ljsoncpp -lssl
#BOOST_LIBS= -lboost_filesystem -lboost_system
##Libraries to be linked in.
#LIBS =  $(SFML_LIBS) $(UTIL_LIBS) $(BOOST_LIBS)

#Subfolders
add_subdirectory (Util)
add_subdirectory (Engine)
add_subdirectory (Entities)
add_subdirectory (ResourceManagement)
add_subdirectory (Tiles)

set(enDJIN_SOURCE_FILES enDJIN.cpp)

#Executable
add_executable (enDJIN ${enDJIN_SOURCE_FILES})

#Link in dependency libraries
set(Engine_LIBS Engine)

## Link libraries
set(BOOST_LIBS file_system system)
find_package(Boost COMPONENTS ${BOOST_LIBS} REQUIRED)
find_package(JsonCPP REQUIRED)
include_directories(${JsonCPP_INCLUDE_DIRS})

set(UTIL_LIBS ${JsonCPP_LIBRARIES})
set(LIBS ${Engine_LIBS} ${SFML_LIBS} ${UTIL_LIBS} ${Boost_LIBRARIES})

target_link_libraries(enDJIN ${LIBS})


