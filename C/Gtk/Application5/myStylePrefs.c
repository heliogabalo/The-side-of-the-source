#include <gtk/gtk.h>

#include "myStyle.h"
#include "myStyleWin.h"
#include "myStylePrefs.h"

struct _MyStylePrefs {
  GtkDialog parent;
};

typedef struct _MyStylePrefsPrivate MyStylePrefsPrivate;

struct _MyStylePrefsPrivate {
  GSettings *settings;
  GtkWidget *font;
  GtkWidget *transition;
};

G_DEFINE_TYPE_WITH_PRIVATE(MyStylePrefs, my_style_prefs, GTK_TYPE_DIALOG);

static void my_style_prefs_init(MyStylePrefs *prefs) {
  MyStylePrefsPrivate *priv;

  priv = my_style_prefs_get_instance_private(prefs);
  gtk_widget_init_template(GTK_WIDGET(prefs));
  priv->settings = g_settings_new("org.gtk.Example");

  g_settings_bind(priv->settings, "font",
                  priv->font, "font",
                  G_SETTINGS_BIND_DEFAULT);

  g_settings_bind(priv->settings, "transition",
                  priv->transition, "active-id",
                  G_SETTINGS_BIND_DEFAULT);
}

static void my_style_prefs_dispose(GObject *object) {
  MyStylePrefsPrivate *priv;

  priv = my_style_prefs_get_instance_private(MY_STYLE_PREFS(object));
  g_clear_object(&priv->settings);

  G_OBJECT_CLASS(my_style_prefs_parent_class)->dispose(object);
}

static void my_style_prefs_class_init(MyStylePrefsClass *class) {
  G_OBJECT_CLASS(class)->dispose = my_style_prefs_dispose;

  gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS(class),
                                              "/org/gtk/Example/prefs.ui");

  gtk_widget_class_bind_template_child_private(GTK_WIDGET_CLASS(class), MyStylePrefs, font);
  gtk_widget_class_bind_template_child_private(GTK_WIDGET_CLASS(class), MyStylePrefs, transition);
}

MyStylePrefs * my_style_prefs_new(MyStyleWindow *win) {
  return g_object_new(MY_STYLE_PREFS_TYPE, "transient-for", win, "use-header-bar", TRUE, NULL);
}
