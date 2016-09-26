cmake_minimum_required(VERSION 3.0)

if(MSVC)
	add_definitions(/DYY_NO_UNISTD_H)
endif()

unset(BUILD_PLATFORM)
if(MINGW OR MSYS)
    message(STATUS "MinGW or MSYS build")
    set(BUILD_PLATFORM msys_mingw)
    add_definitions(-std=gnu++0x)
elseif(EMSCRIPTEN)
    message(STATUS "Emscripten build")
    set(BUILD_PLATFORM emscripten)
elseif(ANDROID)
    message(STATUS "Android build")
    set(BUILD_PLATFORM android)
elseif(APPLE)
    message(STATUS "MacOS build")
    set(BUILD_PLATFORM macos)
    add_definitions(-std=c++11)
else()
    message(STATUS "Linux build")
    set(BUILD_PLATFORM linux)
    add_definitions(-std=c++11)
endif()

set(SYSROOT ${CMAKE_SOURCE_DIR}/3rdparty/sysroot-${BUILD_PLATFORM})

set(3RDPARTY_INSTALL ${SYSROOT})

add_subdirectory(3rdparty)

include_directories(
    SubtleTire
    ${CMAKE_BINARY_DIR}/fun
    ${SYSROOT}/include
)
link_directories(
        ${SYSROOT}/lib
)

option(ENABLE_LOST_ALPHA "Enable LostAlpha" ON)
if(ENABLE_LOST_ALPHA)
    add_subdirectory(LostAlpha)
endif()

option(ENABLE_SUBTLE_TIRE "Enable SubtleTire" ON)
if(ENABLE_SUBTLE_TIRE)
    # add_subdirectory(SubtleTire)
endif()

option(ENABLE_BOILING_TIRE "Enable BoilingTire" ON)
if(ENABLE_BOILING_TIRE)
    add_subdirectory(BoilingTire)
endif()

