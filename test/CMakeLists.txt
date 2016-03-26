
project(vkwin-test)

include_directories(${PACKAGE_VKWIN_INCLUDES})
link_directories(${PACKAGE_VKWIN_LIBS})

add_executable(vkwin-test main.cpp)

target_link_libraries(vkwin-test -lxcb -lvkwin)
set_property(TARGET vkwin-test PROPERTY CXX_STANDARD 11)
set_property(TARGET vkwin-test PROPERTY CXX_STANDARD_REQUIRED ON)
