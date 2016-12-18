#include <gtk/gtk.h>

#include "myStyle.h"
#include "myStyleWin.h"



int main(int argc, char *argv[]) {

  return g_application_run(G_APPLICATION(my_style_new()), argc, argv);
}
