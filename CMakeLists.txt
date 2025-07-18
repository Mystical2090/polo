cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if ("${CMAKE_SYSTEM_NAME}" STREQUAL "iOS" OR IOS)
    set(CMAKE_OSX_ARCHITECTURES "arm64")
else()
    set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
endif()
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

project(polo VERSION 1.0.0)

set(CPM_DOWNLOAD_VERSION 0.38.3)
if(CPM_SOURCE_CACHE)
    set(CPM_DOWNLOAD_LOCATION "${CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
elseif(DEFINED ENV{CPM_SOURCE_CACHE})
    set(CPM_DOWNLOAD_LOCATION "$ENV{CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
else()
    set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
endif()

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
    message(STATUS "Downloading CPM.cmake to ${CPM_DOWNLOAD_LOCATION}")
    file(DOWNLOAD
        https://github.com/cpm-cmake/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake
        ${CPM_DOWNLOAD_LOCATION}
    )
endif()

include(${CPM_DOWNLOAD_LOCATION})

CPMAddPackage("gh:matcool/gd-imgui-cocos#653e533")

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    src/hacks/misc/Solidwavetrail.cpp
    src/hacks/misc/NoWavepulse.cpp
    src/hacks/misc/everytinghurtsandnosolids.cpp
    src/hacks/misc/commenthistory.cpp
    src/hacks/Player/Noclip.cpp
    src/hacks/Player/jumphack.cpp
    src/hacks/misc/safemode.cpp
    src/hacks/Player/ignore-inputs.cpp
    src/hacks/misc/speedhack.cpp
    src/hacks/misc/iconhack.cpp
    src/hacks/misc/autopractice.cpp
    src/hacks/misc/suicide.cpp
    src/hacks/creator/verifyhack.cpp
    src/hacks/creator/copy-hack.cpp
    src/hacks/creator/custom-obj-hack.cpp
    src/hacks/misc/practice-music.cpp
    src/hacks/misc/layout-mode.cpp
    src/hacks/misc/noglow.cpp
    src/hacks/misc/hidepausebutton.cpp
    src/hacks/misc/colorhack.cpp
    src/hacks/misc/show-hitboxes.cpp
    src/hacks/misc/instantcomplete.cpp
    src/hacks/misc/basementbypass.cpp
    src/hacks/misc/level-edit-on-pause-menu.cpp
    src/hacks/creator/nocmark.cpp
    src/hacks/misc/main-levels.cpp
    src/hacks/misc/rainbow-icons.cpp
    src/hacks/misc/nowavepulse.cpp
    
)


if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

target_link_libraries(${PROJECT_NAME} imgui-cocos)

setup_geode_mod(${PROJECT_NAME})
