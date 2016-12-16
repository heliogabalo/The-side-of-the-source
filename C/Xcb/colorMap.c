#include <xcb/xcb.h>

int main() {
  // Open the connection to the X server and get the first screen
  xcb_connection_t *connection = xcb_connect(NULL, NULL);
  xcb_screen_t *screen = xcb_setup_roots_iterator(xcb_get_setup(connection)).data;

  // ... asume we create a window here
  xcb_colormap_t colormapId = xcb_generate_id(connection);
  xcb_create_colormap(connection,
  XCB_COLORMAP_ALLOC_NONE,
  colormapId,
  window,
  screen->root_visual);  

  return 0;
}
