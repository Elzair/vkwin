project(vkwin)

include_directories(${PACKAGE_VKWIN_INCLUDES})

add_library(vkwin x11/vkwin_x11.h x11/vkwin_x11.c vkwin.c)

set(PACKAGE_VKWIN_LIBS ${CMAKE_CURRENT_BINARY_DIR} CACHE PATH "Path of vkwin library code")
