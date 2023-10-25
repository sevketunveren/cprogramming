cmake_minimum_required(VERSION 3.22)
project(CCh10S5)
file(GLOB_RECURSE HEADERS
	"${PROJECT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE SOURCES
	"${PROJECT_SOURCE_DIR}/src/*.h"
	"${PROJECT_SOURCE_DIR}/src/*.c")
include_directories("${PROJECT_SOURCE_DIR}/include") 
add_executable(CCh10S5 ${SOURCES} ${HEADERS})
