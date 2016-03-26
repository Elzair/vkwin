if(APPLE)
  cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)
else()
  cmake_minimum_required(VERSION 2.8.7 FATAL_ERROR)
endif()

# First build dependencies

#add_subdirectory(contrib)

# Next build library

set(PACKAGE_VKWIN_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE PATH "Path of vkwin headers")
add_subdirectory(src)

# Now build utilities and test code

add_subdirectory(test)
