cmake_minimum_required(VERSION 2.8)
project(s32_li6_d_analysis)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "$ENV{ROOTSYS}/etc/cmake")
list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

find_package(ROOT REQUIRED)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ROOT_CXX_FLAGS}")
include_directories(${ROOT_INCLUDE_DIR} ${CMAKE_SOURCE_DIR})
link_directories(${ROOT_LIBRARY_DIR})

set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")

set(headers SMDMAnalysis.h SMDMCalibration.h )
set(sources SMDMAnalysis.C SMDMCalibration.C )

ROOT_GENERATE_DICTIONARY(s32_li6_d_analysis_Dict ${headers} LINKDEF LinkDef.h)
add_library(s32_li6_d_analysis SHARED ${headers} ${sources} s32_li6_d_analysis_Dict.cxx)
