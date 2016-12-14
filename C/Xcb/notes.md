## Basic knowledge

- An X app first needs to open the connection to the X server using:

  `xcb_connect()`

      // if NULL, uses the Display enviroment variable!!
      // return the screen number of connection; can provide NULL if don'r care.
      `xcb_connection_t *xcb_connect(const char *displayname, int *screenp);`

- To close a connection, it suffices to use:
    `void xcb_disconnect(xcb_connection_t *c);` ejem: `xcb_disconnect(connection)`

#### Checking basic info about connection
This are such data to know the kind of screen we are working on. We get that
info from a `struct` like this:

    `typede struct{
        xcb_window_t    root;
        xcb_colormap_t  default_colormap;
        uint32_t        white_pixel;
        uint32_t        black_pixel;
        uint32_t        current_input_masks;
        uint16_t        width_in_pixels;
        uint16_t        height_in_pixels;
        uint16_t        width_in_millimeters;
        uint16_t        height_in_millimeters;
        uint16_t        min_installed_maps;
        uint16_t        max_installed_maps
        xcb_visual_t    root_visual;
        uint8_t         backing_stores;
        uint8_t         save_unders;
        uint8_t         root_depth;
        uint8_t         allowed_depths_len;
      } xcb_screen_t`

We could retrieve the first screen of the connection by using:

  `xcb_screen_iterator_t xcb_setup_roots_iterator(xcb_setup_t *R);`
> see retrieve_screen on .
