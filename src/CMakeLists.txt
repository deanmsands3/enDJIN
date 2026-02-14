cmake_minimum_required (VERSION 3.10)
project(enDJIN_executable)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

#Subfolders
add_subdirectory (Util)
add_subdirectory (Engine)
# add_subdirectory (Entities)
add_subdirectory (ResourceManagement)
add_subdirectory (Tiles)

#Executable
add_executable (enDJIN enDJIN.cpp)

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
target_include_directories(enDJIN PRIVATE ${SFML_INCLUDE_DIRS})
set(SFML_LIBS ${SFML_LIBRARIES})

## Link libraries

find_package(Boost COMPONENTS system REQUIRED CONFIG)
find_package(jsoncpp  REQUIRED)
target_include_directories(enDJIN PRIVATE ${jsoncpp_INCLUDE_DIRS})



set(UTIL_LIBS ${jsoncpp_LIBRARIES})

target_link_libraries(enDJIN PRIVATE ${Engine_LIBS} ${SFML_LIBS} ${UTIL_LIBS} ${Boost_LIBRARIES})


