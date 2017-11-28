#ifndef __MIVISORWIN_H
#define __MIVISORWIN_H

#include <gtk/gtk.h>
#include "miVisor.h"

#define MI_VISOR_WINDOW_TYPE (mi_visor_window_get_type())
G_DECLARE_FINAL_TYPE(MiVisorWindow, mi_visor_window, MI, VISOR_WIN, GtkApplicationWindow)

MiVisorWindow *mi_visor_window_new(MiVisor *app);
void mi_visor_window_open(MiVisorWindow *win,
                          GFile *file);

#endif /* __MIVISORWIN_H */
