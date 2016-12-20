#include <gtk/gtk.h>

#include "miVisor.h"
#include "miVisorWin.h"

struct _MiVisor {
  GtkApplication parent;
};

G_DEFINE_TYPE(MiVisor, mi_visor, GTK_TYPE_APPLICATION);

static void mi_visor_init(MiVisor *app) {}

static void preferences_activated(GSimpleAction *action,
                                  GVariant *parameter,
                                  gpointer app) {}

static void quit_activated(GSimpleAction *action,
                           GVariant *parameter,
                           gpointer app) {
    g_application_quit(G_APPLICATION(app));

  }

static GActionEntry app_entries[] = {
  { "preferences", preferences_activated, NULL, NULL, NULL },
  { "quit", quit_activated, NULL, NULL, NULL }
};

static void mi_visor_startup(GApplication *app) {

  GtkBuilder *builder;
  GMenuModel *app_menu;
  const gchar *quit_accels[2] = { "<Ctrl>Q", NULL };

  G_APPLICATION_CLASS(mi_visor_parent_class)->startup(app);
  g_action_map_add_action_entries(G_ACTION_MAP(app),
                                  app_entries, G_N_ELEMENTS(app_entries),
                                  app);
  gtk_application_set_accels_for_action(GTK_APPLICATION(app),
  "app.quit",
  quit_accels);

  builder = gtk_builder_new_from_resource("/virtual/path/app-menu.ui");
  app_menu = G_MENU_MODEL(gtk_builder_get_object(builder, "appmenu"));
  gtk_application_set_app_menu(GTK_APPLICATION(app), app_menu);
  g_object_unref(builder);
}

static void mi_visor_activate(GApplication *app) {
  MiVisorWindow *win;

  win = mi_visor_window_new(MI_VISOR(app));
  gtk_window_present(GTK_WINDOW(win));
}

static void mi_visor_open(GApplication *app,
                          GFile **files,
                          gint n_files,
                          const gchar *hint) {
  GList *windows;
  MiVisorWindow *win;
  int i;

  windows = gtk_application_get_windows(GTK_APPLICATION(app));
  if(windows){
    win = MI_VISOR_WINDOW (windows->data);
  }
  else{
    win = mi_visor_window_new(MI_VISOR(app));
  }

  for (i = 0; i < n_files; i++) {
    mi_visor_window_open(win, files[i]);
  }

  gtk_window_present(GTK_WINDOW(win));
}

static void mi_visor_class_init(MiVisorClass *class) {
  G_APPLICATION_CLASS(class)->startup = mi_visor_startup;
  G_APPLICATION_CLASS(class)->activate = mi_visor_activate;
  G_APPLICATION_CLASS(class)->open = mi_visor_open;
}

MiVisor * mi_visor_new(void) {
  return g_object_new(MI_VISOR_TYPE,
                      "application-id", "virtual.path",
                      "flags",G_APPLICATION_HANDLES_OPEN,
                      NULL);
}
