
#ifndef _GUICONTROL_H_
#define _GUICONTROL_H_

#include <gtk/gtk.h>
#include <stdlib.h>
#include <math.h>
#include <glib.h>

#include "guicallback.h"

typedef unsigned short guint16;

/* HELP FUNCTIONS */

void     validate_ui();

/* GETTERS AND SETTERS */

gchar*   gui_get_off_file(void);
void     gui_set_off_file(gchar*);
void     gui_set_flip_normals(gboolean );
gboolean gui_get_flip_normals(void);
void     gui_set_I_light(gdouble [3]);
void     gui_set_I_ambient(gdouble [3]);
void     gui_set_k_ambient(gdouble [3]);
void     gui_get_k_ambient(gdouble [3]);
void     gui_set_k_diffuse(gdouble [3]);
void     gui_get_k_diffuse(gdouble [3]);
void     gui_set_k_specular(gdouble [3]);
void     gui_get_k_specular(gdouble [3]);
void     gui_set_light_pos(gdouble [3]);
void     gui_get_light_pos(gdouble [3]);
void     gui_set_phong(guint16);
gdouble  gui_get_phong(void);
void     gui_set_projection_parallel(void);
void     gui_set_projection_perspective(void);
void     gui_set_option_far(gdouble);
void     gui_set_option_top(gdouble);
void     gui_set_option_oblique_angle(gdouble);
void     gui_set_option_oblique_scale(gdouble);
void     gui_set_option_fov(gdouble);

/* INITIALIZERS */

/* Initializes the glade gui.
   input:
      argc: number of string items in argv.
      argv: command line arguments as a string array.
 */
extern void guiInitWindow(const char*);

/* Initialize GTK.
 */
extern void guiInit(int *, char**);

/* Calls a single GTK main loop iteration to process
 * events (non-blocking).
 */
extern void guiMainIteration();

#endif
