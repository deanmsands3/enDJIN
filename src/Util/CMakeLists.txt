add_subdirectory(Log)
add_subdirectory(Types)

set(util_SOURCE_FILES
	Util.h
)
add_library(Util ${util_SOURCE_FILES})
target_link_libraries (Util Types)
target_link_libraries (Util Log)

