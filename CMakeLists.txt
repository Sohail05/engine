cmake_minimum_required (VERSION 3.1.0)

# set a default build type if none was provided
# this has to be done before the project() instruction!
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

project (game)

set (GAME game)
set (VERSION_MAJOR 0)
set (VERSION_MINOR 1)

set (SOURCES_DIR "src")
set (OTHER_LIBRARIES "")
set (LINKER_FLAGS "")

set (CMAKE_USE_RELATIVE_PATHS false)
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

# Detect the OS
if(${CMAKE_HOST_WIN32})
    set(WINDOWS 1)
elseif(${CMAKE_HOST_APPLE})
    set(MACOSX 1)
elseif(${CMAKE_HOST_UNIX})
    set(LINUX 1)
else()
    message(FATAL_ERROR "Unsupported operating system")
    return()
endif()

#################################################################################################################
# ================================================ SFML SETUP ================================================= #
#################################################################################################################

if (WINDOWS)
    set (BUILD_STATIC FALSE CACHE BOOL "TRUE to build static version of sfeMovie")
endif()

if (BUILD_STATIC)
    set (SFML_STATIC_LIBRARIES TRUE)
endif()

find_package (SFML 2 COMPONENTS graphics window system audio REQUIRED)
message(STATUS "SFML libraries: ${SFML_LIBRARIES}")
message(STATUS "Additional dependencies: ${SFML_DEPENDENCIES}")

#################################################################################################################
# ================================================ GAME SETUP ================================================= #
#################################################################################################################

file(GLOB SOURCE_FILES ${SOURCES_DIR}/[a-z,A-Z]*.[c,h]*)

source_group(Sources FILES ${SOURCE_FILES})

set(GAME_INCLUDE_DIRS "${SFML_INCLUDE_DIR};")
include_directories (${GAME_INCLUDE_DIRS})

add_definitions(-D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS -DSFE_EXPORTS)

add_executable(${GAME} ${SOURCE_FILES})

# Define the libraries game should link against
if (BUILD_STATIC)
    set_target_properties(${GAME} PROPERTIES
        COMPILE_DEFINITIONS SFML_STATIC)
else()
    target_link_libraries(${GAME} PRIVATE ${SFML_LIBRARIES} ${OTHER_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

include (${CMAKE_SOURCE_DIR}/cmake/Install.cmake)

# add an option for building the documentation
set(BUILD_DOC FALSE CACHE BOOL "Set to true to build the documentation")
if(BUILD_DOC)
    add_subdirectory(doxygen)
endif()