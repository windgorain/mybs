IF (UNIX AND NOT APPLE)
cmake_minimum_required(VERSION 2.8)
ENDIF()
IF (APPLE OR WIN32)
cmake_minimum_required(VERSION 3.2)
ENDIF()

INCLUDE(${CMAKE_SOURCE_DIR}/my_cmake_def.txt)

project (mysys)

include_directories(./h)

# utl
add_subdirectory(./src/lib/util)

IF (UNIX)
add_subdirectory(./src_unixlike/lib/util)
ENDIF()

# base
add_subdirectory(./src/lib/base)

# app
add_subdirectory(./src/app)

IF (WIN32)
add_subdirectory(./src_win/tool)
ENDIF()


