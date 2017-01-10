#include <gtk/gtk.h>

#include "myStyle.h"
#include "myStyleWin.h"
#include "myStylePrefs.h"

struct _MyStyle {
  GtkApplication parent;
};

G_DEFINE_TYPE(MyStyle, my_style, GTK_TYPE_APPLICATION);

static void my_style_init(MyStyle *app) {}

static void preferences_activated(GSimpleAction *action,
                                  GVariant *parameter,
                                  gpointer app) {
  MyStylePrefs *prefs;
  GtkWindow *win;

  win = gtk_application_get_active_window(GTK_APPLICATION(app));
  prefs = my_style_prefs_new(MY_STYLE_WINDOW(win));
  gtk_window_present(GTK_WINDOW(prefs));
}

static void quit_activated(GSimpleAction *action,
                           GVariant *parameter,
                           gpointer app) {

  g_application_quit(GTK_APPLICATION(app));
}

static GActionEntry app_entries[] = {
  { "preferences", preferences_activated, NULL, NULL, NULL },
  { "quit", quit_activated, NULL, NULL, NULL }
};

static void my_style_startup(GApplication *app) {
  GtkBuilder *builder;
  GMenuModel *app_menu;
  const gchar *quit_accels[2] = { "<Ctrl>Q", NULL };

  G_APPLICATION_CLASS(my_style_parent_class)->startup(app);

  g_action_map_add_action_entries(G_ACTION_MAP(app),
                                  app_entries, G_N_ELEMENTS(app_entries),
                                  app);

  gtk_application_set_accels_for_action(GTK_APPLICATION(app),
                                        "app.quit",
                                        quit_accels);

  builder = gtk_builder_new_from_resource("/org/gtk/Example/app-menu.ui");
  app_menu = G_MENU_MODEL(gtk_builder_get_object(builder, "appmenu"));
  gtk_application_set_app_menu(GTK_APPLICATION(app), app_menu);
  g_object_unref(builder);
}



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
  G_APPLICATION_CLASS(class)->startup = my_style_startup;
  G_APPLICATION_CLASS(class)->activate = my_style_activate;
  G_APPLICATION_CLASS(class)->open = my_style_open;
}

MyStyle * my_style_new(void) {
  return g_object_new(MY_STYLE_TYPE,
                      "application-id", "org.gtk.Example",
                      "flags", G_APPLICATION_HANDLES_OPEN,
                      NULL);

}
