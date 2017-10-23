#ifndef __MYSTYLEWIN_H
#define __MYSTYLEWIN_H

#include <gtk/gtk.h>
#include "myStyle.h"

#define MY_STYLE_WINDOW_TYPE (my_style_window_get_type())
G_DECLARE_FINAL_TYPE(MyStyleWindow, my_style_window, MY, STYLE_WINDOW, GtkApplicationWindow)

MyStyleWindow *my_style_window_new(MyStyle *app);
void my_style_window_open(MyStyleWindow *win, GFile *file);


#endif /* __MYSTYLEWIN_H */
