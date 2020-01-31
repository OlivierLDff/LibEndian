#
#   LibEndian CMake script by Olivier Le Doeuff

#
## CMAKE INPUT
#
#   - LIBENDIAN_TARGET : Name of the library target. Default : "LibEndian"
#   - LIBENDIAN_PROJECT : Name of the project. Default : "LibEndian"
#   - LIBENDIAN_BUILD_SHARED : Build shared library [ON OFF]. Default: OFF.
#   - LIBENDIAN_BUILD_STATIC : Build static library [ON OFF]. Default: ON.
#   - LIBENDIAN_USE_NAMESPACE : If the library compile with a namespace [ON OFF]. Default: OFF.
#   - LIBENDIAN_NAMESPACE : Namespace for the library. Only relevant if LIBENDIAN_USE_NAMESPACE is ON. Default: "Endn".
#   - LIBENDIAN_BUILD_DOC : Build the LibEndian Doc [ON OFF]. Default: OFF.
#   - LIBENDIAN_DOXYGEN_BT_REPOSITORY : Repository of DoxygenBt. Default : "https://github.com/OlivierLDff/DoxygenBootstrapped.git"
#   - LIBENDIAN_DOXYGEN_BT_TAG : Git Tag of DoxygenBt. Default : "v1.3.1"

#
## CMAKE OUTPUT
#
#   - LIBENDIAN_TARGET : Output target to link to. Default: LibEndian
#   - LIBENDIAN_VERSION : Current version of the library
#

#
## VERSION
#   - 1.0.0 : 06/12/2018 : Initial Work
#   - 1.0.2 : 10/12/2018 : Fix filename
#   - 1.1.0 : 30/01/2020 : Use bswap32/64 if byte is aligned

# ┌──────────────────────────────────────────────────────────────────┐
# │                       CMAKE PROPERTIES                           │
# └──────────────────────────────────────────────────────────────────┘

cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

# ┌──────────────────────────────────────────────────────────────────┐
# │                       PROJECT SETTINGS                           │
# └──────────────────────────────────────────────────────────────────┘

set(LIBENDIAN_TARGET "LibEndian" CACHE STRING "Target Name" )
set(LIBENDIAN_PROJECT "LibEndian" CACHE STRING "Project Name")
set(LIBENDIAN_BUILD_SHARED OFF CACHE BOOL "Build shared lib for LibEndian" )
if(NOT LIBENDIAN_BUILD_SHARED)
    set(LIBENDIAN_BUILD_STATIC ON CACHE BOOL "Build static lib for LibEndian" )
else()
    set(LIBENDIAN_BUILD_STATIC OFF CACHE BOOL "Build static lib for LibEndian" )
endif()
set(LIBENDIAN_USE_NAMESPACE ON CACHE BOOL "If the library compile with a namespace.")
set(LIBENDIAN_NAMESPACE "Endn" CACHE STRING "Namespace for the library. Only relevant if LIBENDIAN_USE_NAMESPACE is ON")
set( LIBENDIAN_FOLDER_PREFIX "Dependencies/Utils/${LIBENDIAN_TARGET}" CACHE STRING "Prefix folder for all Kratos generated targets in generated project (only decorative)" )
set(LIBENDIAN_ENABLE_BSWAP ON CACHE BOOL "Enable the use of bswap32/64 macros if required" )
set(LIBENDIAN_BUILD_DOC OFF CACHE BOOL "Build LibEndian Doc with Doxygen" )
set(LIBENDIAN_DOXYGEN_BT_REPOSITORY "https://github.com/OlivierLDff/DoxygenBootstrappedCMake.git" CACHE STRING "Repository of DoxygenBt" )
set(LIBENDIAN_DOXYGEN_BT_TAG v1.3.2 CACHE STRING "Git Tag of DoxygenBt" )

project( ${LIBENDIAN_PROJECT} C CXX )
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# ┌──────────────────────────────────────────────────────────────────┐
# │                       VERSION                                    │
# └──────────────────────────────────────────────────────────────────┘

# Project version must be set here
set(LIBENDIAN_VERSION_MAJOR 1)
set(LIBENDIAN_VERSION_MINOR 1)
set(LIBENDIAN_VERSION_PATCH 0)
set(LIBENDIAN_VERSION ${LIBENDIAN_VERSION_MAJOR}.${LIBENDIAN_VERSION_MINOR}.${LIBENDIAN_VERSION_PATCH} CACHE STRING "LibEndian Version")

if( EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.git" )
    execute_process(
        COMMAND git describe --always
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        OUTPUT_VARIABLE LIBENDIAN_VERSION_TAG
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
else()
    set(LIBENDIAN_VERSION_TAG 00000000 )
endif()
set(LIBENDIAN_VERSION_TAG_HEX 0x${LIBENDIAN_VERSION_TAG})

# ┌──────────────────────────────────────────────────────────────────┐
# │                       STATUS                                     │
# └──────────────────────────────────────────────────────────────────┘

message( STATUS  "------ ${LIBENDIAN_TARGET} Configuration ${LIBENDIAN_VERSION} ------" )

message( STATUS "LIBENDIAN_TARGET                 : ${LIBENDIAN_TARGET}" )
message( STATUS "LIBENDIAN_PROJECT                : ${LIBENDIAN_PROJECT}" )
message( STATUS "LIBENDIAN_VERSION                : ${LIBENDIAN_VERSION}" )
message( STATUS "LIBENDIAN_VERSION_TAG_HEX        : ${LIBENDIAN_VERSION_TAG_HEX}" )
message( STATUS "LIBENDIAN_BUILD_SHARED           : ${LIBENDIAN_BUILD_SHARED}" )
message( STATUS "LIBENDIAN_BUILD_STATIC           : ${LIBENDIAN_BUILD_STATIC}" )
message( STATUS "LIBENDIAN_USE_NAMESPACE          : ${LIBENDIAN_USE_NAMESPACE}" )
if(LIBENDIAN_USE_NAMESPACE)
message( STATUS "LIBENDIAN_NAMESPACE              : ${LIBENDIAN_NAMESPACE}" )
endif()

message( STATUS "LIBENDIAN_ENABLE_BSWAP           : ${LIBENDIAN_ENABLE_BSWAP}" )
message( STATUS "LIBENDIAN_BUILD_DOC              : ${LIBENDIAN_BUILD_DOC}" )

if(LIBENDIAN_BUILD_DOC)
message( STATUS "LIBENDIAN_DOXYGEN_BT_REPOSITORY  : ${LIBENDIAN_DOXYGEN_BT_REPOSITORY}" )
message( STATUS "LIBENDIAN_DOXYGEN_BT_TAG         : ${LIBENDIAN_DOXYGEN_BT_TAG}" )
endif()

message( STATUS "------ ${LIBENDIAN_TARGET} End Configuration ------" )

if((LIBENDIAN_BUILD_SHARED AND LIBENDIAN_BUILD_STATIC) OR (NOT LIBENDIAN_BUILD_SHARED AND NOT LIBENDIAN_BUILD_STATIC))
    message( FATAL_ERROR "Set either Build shared or build static to ON, can't build both at once" )
endif()

# ┌──────────────────────────────────────────────────────────────────┐
# │                       SOURCES                                    │
# └──────────────────────────────────────────────────────────────────┘

set(LIBENDIAN_SRCS
    # Main
    ${CMAKE_CURRENT_SOURCE_DIR}/src/LibEndian.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/EndianHelpers.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/LibEndian.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/LittleEndian.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/BigEndian.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/LittleEndian
    ${CMAKE_CURRENT_SOURCE_DIR}/src/BigEndian
    )

# ┌──────────────────────────────────────────────────────────────────┐
# │                       TARGET                                     │
# └──────────────────────────────────────────────────────────────────┘

if(LIBENDIAN_BUILD_SHARED)

    add_library( ${LIBENDIAN_TARGET} SHARED ${LIBENDIAN_SRCS} )
    target_compile_definitions( ${LIBENDIAN_TARGET} PRIVATE -DLIBENDIAN_SHARED )

else()

    add_library( ${LIBENDIAN_TARGET} STATIC ${LIBENDIAN_SRCS} )
    target_compile_definitions( ${LIBENDIAN_TARGET} PUBLIC -DLIBENDIAN_STATIC )

endif()

target_include_directories( ${LIBENDIAN_TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src )
target_compile_definitions( ${LIBENDIAN_TARGET} PRIVATE -DLIBENDIAN_VERSION_MAJOR=${LIBENDIAN_VERSION_MAJOR} )
target_compile_definitions( ${LIBENDIAN_TARGET} PRIVATE -DLIBENDIAN_VERSION_MINOR=${LIBENDIAN_VERSION_MINOR} )
target_compile_definitions( ${LIBENDIAN_TARGET} PRIVATE -DLIBENDIAN_VERSION_PATCH=${LIBENDIAN_VERSION_PATCH} )
target_compile_definitions( ${LIBENDIAN_TARGET} PRIVATE -DLIBENDIAN_VERSION_TAG=${LIBENDIAN_VERSION_TAG} )
target_compile_definitions( ${LIBENDIAN_TARGET} PRIVATE -DLIBENDIAN_VERSION_TAG_HEX=${LIBENDIAN_VERSION_TAG_HEX} )

if(LIBENDIAN_ENABLE_BSWAP)
    include (TestBigEndian)
    test_big_endian(IS_BIG_ENDIAN)
    target_compile_definitions( ${LIBENDIAN_TARGET} PUBLIC -DLIBENDIAN_ENABLE_BSWAP )
    if(IS_BIG_ENDIAN)
        target_compile_definitions( ${LIBENDIAN_TARGET} PUBLIC -DLIBENDIAN_IS_BIG_ENDIAN )
    endif()
endif()
if(LIBENDIAN_USE_NAMESPACE)
    target_compile_definitions( ${LIBENDIAN_TARGET} PUBLIC -DLIBENDIAN_USE_NAMESPACE )
    target_compile_definitions( ${LIBENDIAN_TARGET} PUBLIC -DLIBENDIAN_NAMESPACE=${LIBENDIAN_NAMESPACE} )
endif()

if(LIBENDIAN_FOLDER_PREFIX)
    set_target_properties(${LIBENDIAN_TARGET} PROPERTIES FOLDER ${LIBENDIAN_FOLDER_PREFIX})
endif() # LIBENDIAN_FOLDER_PREFIX

# ┌──────────────────────────────────────────────────────────────────┐
# │                       DOXYGEN                                    │
# └──────────────────────────────────────────────────────────────────┘

if(LIBENDIAN_BUILD_DOC)
    set(DOXYGEN_BOOTSTRAP_COMPANY OlivierLDff )
    set(DOXYGEN_BOOTSTRAP_PUBLISHER OlivierLDff )
    set(DOXYGEN_BOOTSTRAP_PROJECT_NAME ${LIBENDIAN_TARGET} )
    set(DOXYGEN_BOOTSTRAP_PROJECT_VERSION ${LIBENDIAN_VERSION_MAJOR}.${LIBENDIAN_VERSION_MINOR}.${LIBENDIAN_VERSION_PATCH} )
    set(DOXYGEN_BOOTSTRAP_PROJECT_BRIEF "A cross platform C++ library to get rid with of binary serialization issues." )
    set(DOXYGEN_BOOTSTRAP_PROJECT_LOGO )
    set(DOXYGEN_BOOTSTRAP_OUTPUT_DIRECTORY "Docs" )
    set(DOXYGEN_BOOTSTRAP_SRC_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/src )
    set(DOXYGEN_BOOTSTRAP_README ${CMAKE_CURRENT_SOURCE_DIR}/README.md )
    set(DOXYGEN_TARGET_PREFIX "" )
    set(DOXYGEN_TARGET_SUFFIX "Doc" )
    set(DOXYGEN_BT_REPOSITORY ${LIBENDIAN_DOXYGEN_BT_REPOSITORY} )
    set(DOXYGEN_BT_TAG ${LIBENDIAN_DOXYGEN_BT_TAG} )
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/BuildDoxygenBt.cmake)
endif()
