#include <unistd.h>
#include <xcb/xcb.h>
#include <vkwin/vkwin.h>

int main() {
  vkwininfo_t info = vkwinCreateWindow(0, 0, 150, 150);

  xcb_flush(info.conn);

  pause();

  vkwinDestroyWindow(&info);

  return 0;
}
