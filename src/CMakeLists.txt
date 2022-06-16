# CMakeList.txt : CMake project for depressed-lang, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
set(  SOURCES
	"main.cpp" 
	"inst.cpp"
	"func.cpp"
	"classes.cpp"
)

set( HEADERS 
	"../include/token.h"
	
	"../include/scan.h"
	"../include/return.h"
	"../include/resolver.h"
	"../include/parser.h"
	"../include/intrptr.h"
	"../include/inst.h"
	"../include/func.h"
	
	"../include/error.h"
	"../include/environ.h"
	"../include/classes.h"
	"../include/calls.h"
)

add_executable(depressed-lang ${SOURCES} ${HEADERS} "error.cpp" "token.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET depressed-lang PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
