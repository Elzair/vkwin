#ifndef __VKWIN_HPP__
#define __VKWIN_HPP__

#include <stdint.h>

// Include platform specific headers
#if defined(__linux__)
#include <xcb/xcb.h>
#endif

namespace VKWin {

  /**
   * This class holds information about the window
   * to which Vulkan will output.
   */
  class Info {
  protected:
    uint16_t          width;
    uint16_t          height;
    int16_t           x;
    int16_t           y;
  };

#if defined(__linux__)
  class LinuxInfo: public Info {
  public:
    LinuxInfo(uint16_t width,
              uint16_t height,
              int16_t  x=0,
              int16_t  y=0,
              uint16_t bwidth=10);
    ~LinuxInfo();
    void flush();

  protected:
    uint16_t          bwidth;
    xcb_connection_t* conn;
    uint8_t           depth;
    xcb_window_t      winid;
    xcb_window_t      parent;
  };
#endif

}
 
#endif
