#include <gtk/gtk.h>

#include "myStyle.h"
#include "myStyleWin.h"

struct _MyStyleWindow{
  GtkApplicationWindow parent;
};

G_DEFINE_TYPE(MyStyleWindow, my_style_window, GTK_TYPE_APPLICATION_WINDOW);

static void my_style_window_init(MyStyleWindow *win) {
  gtk_widget_init_template(GTK_WIDGET(win));
}
static void my_style_window_class_init(MyStyleWindowClass *class) {
  gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS(class),
                                              "window.ui");
}

MyStyleWindow * my_style_window_new(MyStyle *app) {
  return g_object_new(MY_STYLE_WINDOW_TYPE, "application", app, NULL);
}

void my_style_window_open(MyStyleWindow *win, GFile *file) {}
