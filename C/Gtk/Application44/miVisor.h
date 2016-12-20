#ifndef __MIVISOR_H
#define __MIVISOR_H

#include <gtk/gtk.h>

#define MI_VISOR_TYPE (mi_visor_get_type())
G_DECLARE_FINAL_TYPE(MiVisor, mi_visor, MI, VISOR, GtkApplication)

MiVisor *mi_visor_new(void);

#endif /* __MIVISOR_H */
