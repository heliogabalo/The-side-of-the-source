#include <gtk/gtk.h>

#include "miVisor.h"

int main(int argc, char *argv[]) {

  return g_application_run(G_APPLICATION(mi_visor_new()), argc, argv);
}
