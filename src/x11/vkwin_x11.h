#ifndef __VKWIN_H__
#define __VKWIN_H__

#include <stdint.h>
#include <xcb/xcb.h>
#include <vkwin/vkwin.h>

#ifdef __cplusplus
extern "C" {
#endif
  vkwininfo_t vkwinCreateWindowX11(uint16_t width,
                                   uint16_t height);

  void vkwinDestroyWindowX11(vkwininfo_t* info);
#ifdef __cplusplus
}
#endif

#endif
