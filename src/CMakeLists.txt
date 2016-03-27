project(vkwin)

include_directories(${PACKAGE_VKWIN_INCLUDES})

add_library(vkwin vkwin.cpp)

set(PACKAGE_VKWIN_LIBS ${CMAKE_CURRENT_BINARY_DIR} CACHE PATH "Path of vkwin library code")

set_property(TARGET vkwin PROPERTY CXX_STANDARD 11)
set_property(TARGET vkwin PROPERTY CXX_STANDARD_REQUIRED ON)
