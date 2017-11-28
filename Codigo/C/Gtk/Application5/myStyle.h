#ifndef __MYSTYLE_H
#define __MYSTYLE_H

#include <gtk/gtk.h>


// for some reason i must keep a space betwen function name &
// function signature. Only here!!!!
#define MY_STYLE_TYPE (my_style_get_type())
G_DECLARE_FINAL_TYPE(MyStyle, my_style, MY, STYLE, GtkApplication)

MyStyle *my_style_new(void);

#endif /* __MYSTYLE_H */
