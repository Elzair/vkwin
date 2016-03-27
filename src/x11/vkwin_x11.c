#include <stdint.h>
#include <string.h>
#include <xcb/xcb.h>
#include <vkwin/vkwin.h>
#include "vkwin_x11.h"

/**
 * This function creates a window on the X11 desktop.
 * @param width the window's initial width
 * @param height the window's initial height 
 * @return information on newly created window
 */
vkwininfo_t vkwinCreateWindowX11(uint16_t width,
                                 uint16_t height) {
  xcb_connection_t* conn = xcb_connect(NULL, NULL); // Open connection to X server

  // Get first screen
  const xcb_setup_t*    setup  = xcb_get_setup(conn);
  xcb_screen_iterator_t iter   = xcb_setup_roots_iterator(setup);
  xcb_screen_t*         screen = iter.data;
  
  
  xcb_window_t winid = xcb_generate_id(conn); // Get new ID for window
  
  xcb_window_t parent = screen->root;         // Set parent window to root window

  // Set other window properties
  uint8_t        x            = 0;
  uint8_t        y            = 0;
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

  
  xcb_map_window(conn, winid);      // Map window onto screen

  
  xcb_flush(conn);                  // Flush commands

  size_t      idx = 0;
  vkwininfo_t info;
  memset((void*)info.data, 0, 32);  // Zero out storage
  memcpy((void*)&info.data[idx], (void*)&conn, sizeof(xcb_connection_t*));
  idx += sizeof(xcb_connection_t*); 
  memcpy((void*)&info.data[idx], (void*)&winid, sizeof(xcb_window_t));
  return info;
}

/**
 * This function destroys a window created with vkwinCreateWindowX11().
 * @param info object containing information on specified window
 */
void vkwinDestroyWindowX11(vkwininfo_t* info) {
  xcb_connection_t* conn = (xcb_connection_t*)info->data;
  xcb_disconnect(conn);
}
