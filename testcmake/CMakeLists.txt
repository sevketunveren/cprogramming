cmake_minimum_required (VERSION 2.6)
set(PROJECT_NAME testcmake)
set(CMAKE_CXX_STANDARD 11)
project ($PROJECT_NAME)
file(GLOB_RECURSE HEADERS
	"${PROJECT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE SOURCES
	"${PROJECT_SOURCE_DIR}/*.h"
	"${PROJECT_SOURCE_DIR}/*.cpp")
include_directories("${PROJECT_SOURCE_DIR}") 
add_executable(testcmake ${SOURCES} ${HEADERS})