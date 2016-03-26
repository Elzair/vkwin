#ifndef __VKWIN_H__
#define __VKWIN_H__

#ifdef __cplusplus
extern "C" {
#endif

// Include platform specific headers
#if defined(__linux__)
#include <xcb/xcb.h>
#endif

  /**
   * This structure holds information about the window
   * to which Vulkan will output.
   */
  struct vkwininfo_t {
    int16_t          x;
    int16_t          y;
    uint16_t         width;
    uint16_t         height;

// Linux specific options
#if defined(__linux__)
    xcb_connection_t* conn;
    uint8_t           depth;
    xcb_window_t      winid;
    xcb_window_t      parent;
    uint16_t          bwidth;
    uint16_t          _class;
    xcb_visualid_t    visual;
    uint32_t          vmask;
    uint32_t*         vlist;
#endif

  };

  struct vkwininfo_t vkwinCreateWindow(int16_t x,
                                       int16_t y,
                                       uint16_t width,
                                       uint16_t height);

  void vkwinDestroyWindow(struct vkwininfo_t* info);
#ifdef __cplusplus
}
#endif

#endif
