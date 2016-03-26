#include <vkwin/vkwin.h>

/**
 * This function creates a window on the desktop.
 * @param x the desired horizontal position of the window's top-left corner
 * @param y the desired vertical position of the window's top-left corner
 * @param width the window's initial width
 * @param height the window's initial height 
 * @return information on newly created window
 */
struct vkwininfo_t vkwinCreateWindow(int16_t x,
                                     int16_t y,
                                     uint16_t width,
                                     uint16_t height) {
  // Create info struct
  struct vkwininfo_t info;
  info.x = x;
  info.y = y;
  info.width = width;
  info.height = height;

#if defined(__linux__)
  // Open connection to X server
  info.conn   = xcb_connect(NULL, NULL);

  info.depth  = XCB_COPY_FROM_PARENT;

  // Get first screen
  const xcb_setup_t*    setup  = xcb_get_setup(info.conn);
  xcb_screen_iterator_t iter   = xcb_setup_roots_iterator(setup);
  xcb_screen_t*         screen = iter.data;
  
  // Get new ID for window
  info.winid  = xcb_generate_id(info.conn);

  // Set parent window to root window
  info.parent = screen->root;

  // Set other window properties
  info.bwidth = 10;
  info._class = XCB_WINDOW_CLASS_INPUT_OUTPUT;
  info.visual = screen->root_visual;
  info.vmask  = 0;
  info.vlist  = NULL;

  // Create window
  xcb_create_window(info.conn,
                    info.depth,
                    info.winid,
                    info.parent,
                    info.x,
                    info.y,
                    info.width,
                    info.height,
                    info.bwidth,
                    info._class,
                    info.visual,
                    info.vmask,
                    info.vlist);

  // Map window onto screen
  xcb_map_window(info.conn, info.winid);
#endif

  return info;
}

/**
 * This function destroys a window created with vkwinCreateWindow().
 * @param info object containing information on specified window
 */
void vkwinDestroyWindow(struct vkwininfo_t* info) {
#if defined(__linux__)
  xcb_disconnect(info->conn);
#endif
}
