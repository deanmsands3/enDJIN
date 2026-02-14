#add_subdirectory(Log)
add_subdirectory(Types)

set(util_SOURCE_FILES
	Util.h
)
add_library(enDJIN_Util ${util_SOURCE_FILES})
target_link_libraries (enDJIN_Util enDJIN_Types)
