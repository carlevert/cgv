#ifndef ASS2GUI_H
#define ASS2GUI_H

#include <glib.h>
#include <gtk/gtk.h>
#include <stdlib.h>




/* INITIALIZERS */

/* Initialize GTK.
 */
extern void initGuiWindow(const char*);

/* Initializes the glade gui.
   input:
      argc: number of string items in argv.
      argv: command line arguments as a string array.
 */
extern void guiInit(int *, char**);

/* Calls a single GTK main loop iteration to process
 * events (non-blocking).
 */
extern void guiMainIteration(void);

/* GETTERS AND SETTERS */

extern void gui_set_projection_parallel();
extern void gui_set_projection_perspective();
extern void gui_set_option_far(gdouble value);
extern void gui_set_option_top(gdouble value);
extern void gui_set_option_oblique_angle(gdouble value);
extern void gui_set_option_oblique_scale(gdouble value);
extern void gui_set_option_fov(gdouble value);

#endif
