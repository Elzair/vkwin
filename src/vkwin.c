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

#if defined(__linux__)
  // Open connection to X server
  xcb_connection_t* conn = xcb_connect(NULL, NULL);

  // Get first screen
  const xcb_setup_t*    setup  = xcb_get_setup(conn);
  xcb_screen_iterator_t iter   = xcb_setup_roots_iterator(setup);
  xcb_screen_t*         screen = iter.data;
  
  // Get new ID for window
  xcb_window_t winid = xcb_generate_id(conn);

  // Set parent window to root window
  xcb_window_t parent = screen->root;

  // Set other window properties
  uint16_t       border_width = 10;
  uint8_t        depth        = XCB_COPY_FROM_PARENT;
  uint16_t       _class       = XCB_WINDOW_CLASS_INPUT_OUTPUT;
  xcb_visualid_t visual       = screen->root_visual;
  uint32_t       value_mask   = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
  uint32_t       value_list[32];
  value_list[0] = screen->black_pixel;
  value_list[1] = XCB_EVENT_MASK_KEY_RELEASE      |
                  XCB_EVENT_MASK_EXPOSURE         |
                  XCB_EVENT_MASK_STRUCTURE_NOTIFY |
                  XCB_EVENT_MASK_POINTER_MOTION   |
                  XCB_EVENT_MASK_BUTTON_PRESS     |
                  XCB_EVENT_MASK_BUTTON_RELEASE;

  // Create window
  xcb_create_window(conn,
                    depth,
                    winid,
                    parent,
                    x,
                    y,
                    width,
                    height,
                    border_width,
                    _class,
                    visual,
                    value_mask,
                    value_list);

  // Map window onto screen
  xcb_map_window(conn, winid);
#endif

  struct vkwininfo_t info = {
    x, y, width, height
#if defined(__linux__)
    , border_width, conn, depth, winid, parent
#endif
  };

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
