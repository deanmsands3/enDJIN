ENGINE_NAME = LeJeNND (Luke e Jenn e Neal Nick Dean) ENGINE
#Include common defines
include $(SRC_FOLDER)Makefile.header

#Determine appropriate system
ifdef SystemRoot
	#We're in Windows
	_BUILD_PLATFORM = win
else
	ifdef SYSTEMROOT
		#We're in MSYS2
		_BUILD_PLATFORM = msys2
	else
		ifeq ($(shell uname), Linux)
			#Linux
			_BUILD_PLATFORM = linux
		else
			ifeq ($(shell uname), Darwin)
				#Mac OSX
				_BUILD_PLATFORM = osx
			endif
		endif
	endif
endif
#Include Platform Specific Makefile
_PLATFORM_MAKEFILE = Makefile.$(_BUILD_PLATFORM)
include $(SRC_FOLDER)$(_PLATFORM_MAKEFILE)
include $(SRC_FOLDER)Makefile.footer
