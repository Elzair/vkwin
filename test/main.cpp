#include <unistd.h>
#include <xcb/xcb.h>
#include <vkwin/vkwin.h>

int main() {
  vkwininfo_t info = vkwinCreateWindow(150, 150);

  pause();

  vkwinDestroyWindow(&info);

  return 0;
}
