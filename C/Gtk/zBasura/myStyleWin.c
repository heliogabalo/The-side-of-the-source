#include <gtk/gtk.h>

#include "myStyle.h"
#include "myStyleWin.h"

struct _MyStyleWindow{
  GtkApplicationWindow parent;
};

typedef struct _MyStyleWindowPrivate MyStyleWindowPrivate;

struct _MyStyleWindowPrivate {
  GtkWidget *stack;
};

G_DEFINE_TYPE_WITH_PRIVATE(MyStyleWindow, my_style_window, GTK_TYPE_APPLICATION_WINDOW);

static void my_style_window_init(MyStyleWindow *win) {
  gtk_widget_init_template(GTK_WIDGET(win));
}

static void my_style_window_class_init(MyStyleWindowClass *class) {
  gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS(class),
                                              "/home/Helio/Github/The-side-of-the-source/C/Gtk/zBasura/window.ui");

  gtk_widget_class_bind_template_child_private(GTK_WIDGET_CLASS(class), MyStyleWindow, stack);
}


MyStyleWindow * my_style_window_new(MyStyle *app) {
  return g_object_new(MY_STYLE_WINDOW_TYPE, "application", app, NULL);
}

void my_style_window_open(MyStyleWindow *win, GFile *file) {
  MyStyleWindowPrivate *priv;
  gchar *basename;
  GtkWidget *scrolled, *view;
  gchar *contents;
  gsize length;

  priv = my_style_window_get_instance_private(win);
  basename = g_file_get_basename(file);

  scrolled = gtk_scrolled_window_new(NULL, NULL);
  gtk_widget_show(scrolled);
  gtk_widget_set_hexpand(scrolled, TRUE);
  gtk_widget_set_vexpand(scrolled, TRUE);
  view = gtk_text_view_new();
  gtk_text_view_set_editable(GTK_TEXT_VIEW(view), FALSE);
  gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(view), FALSE);
  gtk_widget_show(view);
  gtk_container_add(GTK_CONTAINER(scrolled), view);
  gtk_stack_add_titled(GTK_STACK(priv->stack), scrolled, basename, basename);

  if (g_file_load_contents(file, NULL, &contents, &length, NULL, NULL)) {
    GtkTextBuffer *buffer;

    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
    gtk_text_buffer_set_text(buffer, contents, length);
    g_free(contents);
  }

  g_free(basename);
}
