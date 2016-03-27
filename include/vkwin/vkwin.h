#ifndef __VKWIN_H__
#define __VKWIN_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

  /**
   * This structure holds information about the window
   * to which Vulkan will output.
   */
  typedef struct vkwininfo {
    uint8_t data[32];
  } vkwininfo_t;

  vkwininfo_t vkwinCreateWindow(uint16_t width,
                                uint16_t height);

  void vkwinDestroyWindow(vkwininfo_t* info);
#ifdef __cplusplus
}
#endif

#endif
