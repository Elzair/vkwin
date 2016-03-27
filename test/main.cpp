#include <unistd.h>
#if defined(__linux__)
#include <xcb/xcb.h>
#endif
#include <vkwin/vkwin.hpp>

int main() {
#if defined(__linux__)
  VKWin::LinuxInfo lininfo(150, 150);
  lininfo.flush();
  pause();
#endif

  return 0;
}
