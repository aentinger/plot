##########################################################################

cmake_minimum_required (VERSION 2.8)

##########################################################################

project (plot)

##########################################################################

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)

##########################################################################

set(PLOT_LIBRARY_NAME ${PROJECT_NAME})

##########################################################################

include_directories(include)

##########################################################################

set(PLOT_SRCS
  src/Plot2D.cpp
  src/Plot3D.cpp
  src/PlotBase.cpp
)

##########################################################################

add_library(
  ${PLOT_LIBRARY_NAME} 
  STATIC
  ${PLOT_SRCS}
)

target_link_libraries(
  ${PLOT_LIBRARY_NAME}
   
  boost_system 
  boost_iostreams 
  boost_filesystem
)

##########################################################################

add_subdirectory(examples)

##########################################################################
