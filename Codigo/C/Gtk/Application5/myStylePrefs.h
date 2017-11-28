#ifndef __MYSTYLEPREFS_H
#define __MYSTYLEPREFS_H

#include <gtk/gtk.h>
#include "myStyleWin.h"

#define MY_STYLE_PREFS_TYPE (my_style_prefs_get_type())
G_DECLARE_FINAL_TYPE (MyStylePrefs, my_style_prefs, MY, STYLE_PREFS, GtkDialog)

MyStylePrefs *my_style_prefs_new(MyStyleWindow *win);


#endif /* __MYSTYLEPREFS_H */
