#include <malloc.h>
#include <xcb/xcb.h>

int main() {
  // Open the connection to the X server ang get the first screen
  xcb_connection_t *connection = xcb_connect(NULL, NULL);
  xcb_screen_t *screen =xcb_setup_roots_iterator(xcb_get_setup(connection)).data;

  // ... assume dwindow created here
  xcb_colormap_t colormapId = xcb_generate_id(connection);
  xcb_create_colormap(connection, XCB_COLORMAP_ALLOC_NONE, colormapId, window,
                      screen->root_visual);
  xcb_alloc_color_reply_t *reply = xcb_alloc_color_reply(connection,
                                                         xcb_alloc_color(connection,
                                                                         colormapId,
                                                                         65535,
                                                                         0,
                                                                         0),
                                                          NULL);
  if (!reply) {
    return 0;
  }

  // ... do something with reply->pixel.

  return 0;
}
