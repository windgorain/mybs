INCLUDE(${CMAKE_SOURCE_DIR}/my_cmake_def.txt)

set(SRC "")
aux_source_directory(./fd SRC)
aux_source_directory(./tun SRC)

add_library(unixlike_util ${SRC})
set_property(TARGET unixlike_util PROPERTY POSITION_INDEPENDENT_CODE ON)

#INSTALL(TARGETS unixlike_util ARCHIVE DESTINATION /usr/local/lib/utl/)

