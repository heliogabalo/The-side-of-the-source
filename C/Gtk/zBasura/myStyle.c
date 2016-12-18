#include <gtk/gtk.h>

#include "myStyle.h"
#include "myStyleWin.h"

struct _MyStyle {
  GtkApplication parent;
};

G_DEFINE_TYPE(MyStyle, my_style, GTK_TYPE_APPLICATION);

static void my_style_init(MyStyle *app) {}

static void my_style_activate(GApplication *app) {
  MyStyleWindow *win;
  win = my_style_window_new(MY_STYLE(app));
  gtk_window_present(GTK_WINDOW(win));
}

static void my_style_open(GApplication *app,
                          GFile **files,
                          gint n_files,
                          const gchar *hint) {

  GList *windows;
  MyStyleWindow *win;
  int i;

  windows = gtk_application_get_windows(GTK_APPLICATION(app));
  if(windows){
    win = my_style_window_new(windows->data);
  }
  else{
    win = my_style_window_new(MY_STYLE(app));
  }

  for (i = 0; i < n_files; i++) {
    my_style_window_open(win, files[i]);
  }
  gtk_window_present(GTK_WINDOW(win));
}

static void my_style_class_init(MyStyleClass *class) {
  G_APPLICATION_CLASS(class)->activate = my_style_activate;
  G_APPLICATION_CLASS(class)->open = my_style_open;
}

MyStyle * my_style_new(void) {
  return g_object_new(MY_STYLE_TYPE,
                      "application-id", "org.gtk.myStyle",
                      "flags", G_APPLICATION_HANDLES_OPEN,
                      NULL);

}
