#include <gtk/gtk.h>

#include "miVisor.h"
#include "miVisorWin.h"

struct _MiVisorWindow {
  GtkApplicationWindow parent;
};

typedef struct _MiVisorWindowPrivate MiVisorWindowPrivate;

struct _MiVisorWindowPrivate {
  GtkWidget *stack;
};

G_DEFINE_TYPE_WITH_PRIVATE(MiVisorWindow, mi_visor_window, GTK_TYPE_APPLICATION_WINDOW);

static void mi_visor_window_init(MiVisorWindow *win) {
  gtk_widget_init_template(GTK_WIDGET(win));
}

static void mi_visor_window_class_init(MiVisorWindowClass *class) {
  gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS(class),
                                              "/virtual/path/window.ui");
gtk_widget_class_bind_template_child_private(GTK_WIDGET_CLASS(class), MiVisorWindow, stack);
}

MiVisorWindow * mi_visor_window_new(MiVisor *app) {
  return g_object_new(MI_VISOR_WINDOW_TYPE, "application", app, NULL);
}

void mi_visor_window_open(MiVisorWindow *win,
                          GFile *file) {
  MiVisorWindowPrivate *priv;
  gchar *basename;
  GtkWidget *scrolled, *view;
  gchar *contents;
  gsize length;

  priv = mi_visor_window_get_instance_private(win);
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
  gtk_stack_add_title(GTK_STACK(priv->stack), scrolled, basename, basename);

  if(g_file_load_contents(file, NULL, &contents, &length, NULL, NULL)) {
    GtkTextBuffer *buffer;

    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
    gtk_text_buffer_set_text(buffer, contents, length);
    g_free(contents);
  }
  g_free(basename);
}
