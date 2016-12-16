#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <xcb/xcb.h>

// Print names of modifers present in mask
void print_modifiers(uint32_t mask) {
  const char *MODIFIERS[] = {
    "Shift", "Lock", "Ctrl", "Alt",
    "Mod2", "Mod3", "Mod4", "Mod5",
    "Button1", "Button2", "Button3", "Button4", "Button5"
  };

  // >> Binary right operator. The left operands val is moved right by nº bits
  // on right operand.
  // >>= Right shift AND assignment operator.
  printf("modifier mask: ");
  for (const char **modifier = MODIFIERS; mask; mask >>= 1, ++modifier) {
    if (mask & 1 ) {
      printf(*modifier);
    }
  }
  printf("\n");
}
int main() {
  // Open the connection to the X server
  xcb_connection_t *connection = xcb_connect(NULL, NULL);

  // Get the first screen
  xcb_screen_t *screen = xcb_setup_roots_iterator(xcb_get_setup(connection)).data;

  // Create the window
  xcb_window_t window = xcb_generate_id(connection);

  uint32_t mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
  uint32_t values[2] = {
    screen->white_pixel,
    XCB_EVENT_MASK_EXPOSURE        | XCB_EVENT_MASK_BUTTON_PRESS    |
    XCB_EVENT_MASK_BUTTON_RELEASE  | XCB_EVENT_MASK_POINTER_MOTION  |
    XCB_EVENT_MASK_ENTER_WINDOW    | XCB_EVENT_MASK_LEAVE_WINDOW    |
    XCB_EVENT_MASK_KEY_PRESS       | XCB_EVENT_MASK_KEY_RELEASE
  };

  xcb_create_window(connection,
                    0,                              // Depth
                    window,
                    screen->root,                   // Parent window
                    0,0,                            // x, y
                    150, 150,                        // width, height
                    10,                             // border_width
                    XCB_WINDOW_CLASS_INPUT_OUTPUT,  // Class
                    screen->root_visual,            // visual
                    mask, values                    // masks
                  );

  // Map the window on the screen
  xcb_map_window(connection, window);

  xcb_flush(connection);

  xcb_generic_event_t *event;
  while ((event = xcb_wait_for_event(connection))) {
    switch (event->response_type & ~0x80) {
      case XCB_EXPOSE: {
        xcb_expose_event_t *expose = (xcb_expose_event_t *)event;
        printf("window %"PRIu32" exposed. Region to be redrawn at location (%"PRIu16",%"PRIu16")\n",
               expose->window, expose->x, expose->y, expose->width, expose->height);
        break;
      }
      case XCB_BUTTON_PRESS: {
        xcb_button_press_event_t *bp = (xcb_button_press_event_t *)event;
        print_modifiers(bp->state);

        switch (bp->detail) {
          case 4:
              printf("Wheel Button up in window %"PRIu32", at coordinates (%"PRIu16",%"PRIu16")\n",
                     bp->event, bp->event_x, bp->event_y);
          case 5:
              printf("Wheel Button down in window %"PRIu32", at coordinates (%"PRIu16",%"PRIu16")\n",
                     bp->event, bp->event_x, bp->event_y);
              break;
          default:
              printf("Button %"PRIu8" pressed in window %"PRIu32", at coordinates (%"PRIu16",%"PRIu16")\n",
                     bp->detail, bp->event, bp->event_x, bp->event_y);
              break;
        }
        break;
      }
      case XCB_BUTTON_RELEASE: {
        xcb_button_release_event_t *br = (xcb_button_release_event_t *)event;
        print_modifiers(br->state);

        printf("Button %"PRIu8" released in window %"PRIu32", at coordinates (%"PRIu16", %"PRIu16")\n",
               br->detail, br->event, br->event_x, br->event_y);
        break;
      }
      case XCB_MOTION_NOTIFY: {
        xcb_motion_notify_event_t *motion = (xcb_motion_notify_event_t *)event;

        printf("Mouse moved in window %"PRIu32", at coordinates (%"PRIu16", %"PRIu16")\n",
               motion->event, motion->event_x, motion->event_y);
        break;
      }
      case XCB_ENTER_NOTIFY: {
        xcb_enter_notify_event_t *enter = (xcb_enter_notify_event_t *)event;

        printf("Mouse entered window %"PRIu32", at coordinates (%"PRIu16", %"PRIu16")\n",
               enter->event, enter->event_x, enter->event_y);
        break;
      }
      case XCB_LEAVE_NOTIFY: {
        xcb_leave_notify_event_t *leave = (xcb_leave_notify_event_t *)event;

        printf("Mouse left window %"PRIu32", at coordinates (%"PRIu16", %"PRIu16")\n",
               leave->event, leave->event_x, leave->event_y);
        break;
      }
      case XCB_KEY_PRESS: {
        xcb_key_press_event_t *kp = (xcb_key_press_event_t *)event;
        print_modifiers(kp->state);

        printf("Key pressed in window %"PRIu32"\n", kp->event);
        break;
      }
      case XCB_KEY_RELEASE: {
        xcb_key_release_event_t *kr = (xcb_key_release_event_t *)event;
        print_modifiers(kr->state);

        printf("Key released in window %"PRIu32"\n", kr->event);
        break;
      }
      default:
        // Unknown event type, ignore it
        printf("Unknown event: %"PRIu8"\n", event->response_type);
        break;
    }
    free(event);
  }
  return 0;


}
