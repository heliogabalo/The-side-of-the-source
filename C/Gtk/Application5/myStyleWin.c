#include <gtk/gtk.h>

#include "myStyle.h"
#include "myStyleWin.h"

struct _MyStyleWindow{
  GtkApplicationWindow parent;
};

typedef struct _MyStyleWindowPrivate MyStyleWindowPrivate;

struct _MyStyleWindowPrivate {
  GSettings *settings;
  GtkWidget *stack;
};

G_DEFINE_TYPE_WITH_PRIVATE(MyStyleWindow, my_style_window, GTK_TYPE_APPLICATION_WINDOW);

static void my_style_window_init(MyStyleWindow *win) {

  MyStyleWindowPrivate *priv;

  priv = my_style_window_get_instance_private(win);
  gtk_widget_init_template(GTK_WIDGET(win));
  priv->settings = g_settings_new("org.gtk.Example");

  g_settings_bind(priv->settings, "transition",
                  priv->stack, "transition-type",
                  G_SETTINGS_BIND_DEFAULT);
}

static void my_style_window_dispose(GObject *object) {
  MyStyleWindow *win;
  MyStyleWindowPrivate *priv;

  win = MY_STYLE_WINDOW(object);
  priv = my_style_window_get_instance_private(win);

  g_clear_object(&priv->settings);
  G_OBJECT_CLASS(my_style_window_parent_class)->dispose(object);
}

static void my_style_window_class_init(MyStyleWindowClass *class) {
  G_OBJECT_CLASS(class)->dispose = my_style_window_dispose;

  gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS(class),
                                              "/org/gtk/Example/window.ui");

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
  GtkTextBuffer *buffer;
  GtkTextTag *tag;
  GtkTextIter start_iter, end_iter;

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

  buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));

  if (g_file_load_contents(file, NULL, &contents, &length, NULL, NULL)) {

    gtk_text_buffer_set_text(buffer, contents, length);
    g_free(contents);
  }

  tag = gtk_text_buffer_create_tag(buffer, NULL, NULL);
  g_settings_bind(priv->settings, "font", tag, "font", G_SETTINGS_BIND_DEFAULT);

  gtk_text_buffer_get_start_iter(buffer, &start_iter);
  gtk_text_buffer_get_end_iter(buffer, &end_iter);
  gtk_text_buffer_apply_tag(buffer, tag, &start_iter, &end_iter);

  g_free(basename);
}
