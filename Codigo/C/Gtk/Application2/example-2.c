#include <gtk/gtk.h>

static void print_hello(GtkWidget *widget, gpointer data) {
  g_print ("Hello Gtk");
}

static void activate(GtkApplication *app, gpointer user_data) {
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *button;

  /* Title of the window*/
  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "window");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  /*Where we place the buttons, a container*/
  grid = gtk_grid_new();

  /*Pack the container in the window*/
  gtk_container_add(GTK_CONTAINER(window), grid);

  button = gtk_button_new_with_label("Button 1");
  g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);

  /* Situation of 1º button on grid not spanning the whole thing
  (0,0) the start point on the axis & (1,1) is the end point*/
  gtk_grid_attach(GTK_GRID(grid), button,0,0,1,1);

  button = gtk_button_new_with_label("Button 2");
  g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);

  /*Second button on the grid. (1,0) is the second column!!
  (1,1) end point must be a relative coordinate of his start point*/
  gtk_grid_attach(GTK_GRID(grid), button,1,0,1,1);

  button = gtk_button_new_with_label("Quit");
  g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);

  /*place the "Quit" button which take 2 columns*/
  gtk_grid_attach(GTK_GRID(grid), button,0,1,2,1);

  /*By calling with "gtk_widget_show_all()" we place all 3 buttons in one
  go. This is a recursive call to "gtk_widget_show" (directly/indir..)*/
  gtk_widget_show_all(window);
}

int main(int argc, char  **argv) {
  GtkApplication *app;
  int status;

  app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
