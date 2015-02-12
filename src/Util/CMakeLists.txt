add_subdirectory(Log)
add_subdirectory(Types)

set(util_SOURCE_FILES
	Util.h
)
add_library(util ${util_SOURCE_FILES})
