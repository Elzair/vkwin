project(vkwin)

include_directories(${PACKAGE_VKWIN_INCLUDES})

add_library(vkwin vkwin.c)

set(PACKAGE_VKWIN_LIBS ${CMAKE_CURRENT_BINARY_DIR} CACHE PATH "Path of vkwin library code")
