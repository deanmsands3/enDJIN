cmake_minimum_required (VERSION 2.8.11)
project(enDJIN_executable)


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
target_link_libraries (enDJIN Engine)





