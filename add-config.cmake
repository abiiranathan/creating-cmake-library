get_filename_component(SELF_DIR ${CMAKE_CURRENT_LIST_DIR} PATH)

# include(CMakeFindDependencyMacro)
# find_dependency(...)
include(${SELF_DIR}/add/add.cmake)
