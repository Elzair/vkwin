
project(vkwin-test)

include_directories(${PACKAGE_VKWIN_INCLUDES})
link_directories(${PACKAGE_VKWIN_LIBS})

add_executable(vkwin-test main.c)

target_link_libraries(vkwin-test -lxcb -lvkwin)
