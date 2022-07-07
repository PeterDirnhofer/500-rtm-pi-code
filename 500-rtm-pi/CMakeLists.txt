cmake_minimum_required(VERSION 3.13)
include_directories(src/header)
file(GLOB SOURCES "src/*.cpp")
add_executable(rtm_pi ${SOURCES})
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
################################################################################
### Find the pigpio shared libraries.
################################################################################

# Find the path to the pigpio includes.
find_path(pigpio_INCLUDE_DIR 
        NAMES pigpio.h pigpiod_if.h pigpiod_if2.h
        HINTS /usr/local/include)
        
# Find the pigpio libraries.
find_library(pigpio_LIBRARY 
        NAMES libpigpio.so
        HINTS /usr/local/lib)
find_library(pigpiod_if_LIBRARY 
        NAMES libpigpiod_if.so
        HINTS /usr/local/lib)
find_library(pigpiod_if2_LIBRARY 
        NAMES libpigpiod_if2.so
        HINTS /usr/local/lib)
    
# Set the pigpio variables to plural form to make them accessible for 
# the paramount cmake modules.
set(pigpio_INCLUDE_DIRS ${pigpio_INCLUDE_DIR})
set(pigpio_INCLUDES     ${pigpio_INCLUDE_DIR})

# Handle REQUIRED, QUIET, and version arguments 
# and set the <packagename>_FOUND variable.
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(pigpio 
    DEFAULT_MSG 
    pigpio_INCLUDE_DIR pigpio_LIBRARY pigpiod_if_LIBRARY pigpiod_if2_LIBRARY)

## bcm2835
find_library( bcm2835_lib bcm2835 OTHER_PARAMETERS_THAT_YOU_REQUIRE_SEE_DOCUMENTATION_LINK )
include_directories( LIST_OF_REQUIRED_INCLUDE_DIRECTORIES_SEE_DOCUMENTATION_LINK ) 

target_link_libraries(rtm_pi bcm2835 pigpio)

