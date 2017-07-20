##########################################################################

cmake_minimum_required (VERSION 2.8)

##########################################################################

project (plot)

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

