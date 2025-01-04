cmake_minimum_required(VERSION 3.10)
project(CML VERSION 1.0)

include_directories(include)

file(GLOB SOURCES "src/*.c")

add_library(cml STATIC ${SOURCES})

install(TARGETS cml DESTINATION lib)
install(FILES include/cml.h DESTINATION include)
