#include <vkwin/vkwin.hpp>

namespace VKWin {
#if defined(__linux__)
  LinuxInfo::LinuxInfo(uint16_t width,
                       uint16_t height,
                       int16_t  x,
                       int16_t  y,
                       uint16_t bwidth) {
    this->x      = x;
    this->y      = y;
    this->width  = width;
    this->height = height;

    // Open connection to X server
    this->conn = xcb_connect(NULL, NULL);

    // Get first screen
    const xcb_setup_t*    setup  = xcb_get_setup(this->conn);
    xcb_screen_iterator_t iter   = xcb_setup_roots_iterator(setup);
    xcb_screen_t*         screen = iter.data;
    
    // Get new ID for window
    this->winid = xcb_generate_id(this->conn);

    // Set parent window to root window
    this->parent = screen->root;

    // Set other window properties
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
    xcb_create_window(this->conn,
                      depth,
                      this->winid,
                      this->parent,
                      this->x,
                      this->y,
                      this->width,
                      this->height,
                      this->bwidth,
                      _class,
                      visual,
                      value_mask,
                      value_list);

    // Map window onto screen
    xcb_map_window(this->conn, this->winid);
  }

  LinuxInfo::~LinuxInfo() {
    xcb_disconnect(this->conn);
  }

  void LinuxInfo::flush() {
    xcb_flush(this->conn);
  }
#endif
}
