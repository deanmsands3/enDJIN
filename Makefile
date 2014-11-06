ifdef SystemRoot
	#We're in Windows
	include Makefile.win
else
	ifeq ($(shell uname), Linux)
		#Linux
		include Makefile.linux
	else
		ifeq ($(shell uname), Darwin)
			#Mac OSX
			include Makefile.osx
		endif
	endif
endif
