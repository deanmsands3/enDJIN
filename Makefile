ENGINE_NAME = LeJeNND (Luke e Jenn e Neal Nick Dean) ENGINE
#Include common defines
include Makefile.header

#Determine appropriate system
ifdef SystemRoot
	#We're in Windows
	_BUILD_PLATFORM = win
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

#Include Platform Specific Makefile
_PLATFORM_MAKEFILE = Makefile.$(_BUILD_PLATFORM)
include $(_PLATFORM_MAKEFILE)
include Makefile.footer
