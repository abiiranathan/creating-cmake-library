cmake_minimum_required(VERSION 3.0)

# set a debug postfix
set(CMAKE_DEBUG_POSTFIX "-dbg")

# define library version (update: apparently you can also do it in project()!)
set(ADD_VERSION_MAJOR 1 CACHE STRING "major version" FORCE)
set(ADD_VERSION_MINOR 0 CACHE STRING "minor version" FORCE)
set(ADD_VERSION ${ADD_VERSION_MAJOR}.${ADD_VERSION_MINOR} CACHE STRING "version" FORCE)

project(add LANGUAGES CXX)

add_library(add STATIC src/add.cpp)

target_include_directories(add
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE add)

# Generate the export file
install(TARGETS add
  EXPORT add
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

# Export the project
install(EXPORT add
  FILE add.cmake
  NAMESPACE add::
  DESTINATION lib/cmake/add
)

# Install the header files to the installation directory
# Destinations are relative to CMAKE_INSTALL_PREFIX.
install(DIRECTORY 
    ${PROJECT_SOURCE_DIR}/include/ 
DESTINATION
    include
)

# Install config file
install(FILES add-config.cmake DESTINATION lib/cmake/add)