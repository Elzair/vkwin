#include <vkwin/vkwin.h>

#if defined(__linux__)
#include "x11/vkwin_x11.h"
extern vkwininfo_t vkwinCreateWindowX11(uint16_t width,
                                        uint16_t height);
extern void vkwinDestroyWindowX11(vkwininfo_t* info);
#endif

/**
 * This function creates a window on the desktop.
 * @param width the window's initial width
 * @param height the window's initial height 
 * @return information on newly created window
 */
vkwininfo_t vkwinCreateWindow(uint16_t width,
                              uint16_t height) {
#if defined(__linux__)
  vkwininfo_t info = vkwinCreateWindowX11(width, height);
  return info;
#endif
}

/**
 * This function destroys a window created with vkwinCreateWindow().
 * @param info object containing information on specified window
 */
void vkwinDestroyWindow(vkwininfo_t* info) {
#if defined(__linux__)
  vkwinDestroyWindowX11(info);
#endif
}
