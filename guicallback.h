#ifndef _GUICALLBACK_H_
#define _GUICALLBACK_H_

#include <gtk/gtk.h>
#include <stdlib.h>
#include <math.h>

#include "guicontrol.h"

/* CALLBACKS FROM GUI */

void     on_off_chooser_selection_changed(GtkFileChooser*, gpointer);
void     on_flip_normals_toggled(GtkToggleButton*, gpointer);
void     on_light_x_value_changed(GtkAdjustment*, gpointer);
void     on_light_y_value_changed(GtkAdjustment*, gpointer);
void     on_light_z_value_changed(GtkAdjustment*, gpointer);
void     on_I_light_r_value_changed(GtkAdjustment*,gpointer);
void     on_I_light_g_value_changed(GtkAdjustment*, gpointer);
void     on_I_light_b_value_changed(GtkAdjustment*, gpointer);
void     on_I_ambient_r_value_changed(GtkAdjustment*, gpointer);
void     on_I_ambient_g_value_changed(GtkAdjustment*, gpointer);
void     on_I_ambient_b_value_changed(GtkAdjustment*, gpointer);
void     on_k_ambient_r_value_changed(GtkAdjustment*, gpointer);
void     on_k_ambient_g_value_changed(GtkAdjustment*, gpointer);
void     on_k_ambient_b_value_changed(GtkAdjustment*, gpointer);
void     on_k_diffuse_r_value_changed(GtkAdjustment*, gpointer);
void     on_k_diffuse_g_value_changed(GtkAdjustment*, gpointer);
void     on_k_diffuse_b_value_changed(GtkAdjustment*, gpointer);
void     on_k_specular_r_value_changed(GtkAdjustment*, gpointer);
void     on_k_specular_g_value_changed(GtkAdjustment*, gpointer);
void     on_k_specular_b_value_changed(GtkAdjustment*, gpointer);
void     on_phong_value_changed(GtkAdjustment*, gpointer);
void     on_top_value_changed(GtkAdjustment*, gpointer);
void     on_far_value_changed(GtkAdjustment*, gpointer);
void     on_oblique_scale_value_changed(GtkAdjustment*, gpointer);
void     on_oblique_angle_value_changed(GtkAdjustment*, gpointer);
void     on_fov_value_changed(GtkAdjustment*, gpointer);
void     on_parallel_toggled(GtkToggleButton*, gpointer);
void     on_perspective_toggled(GtkToggleButton*, gpointer);
void     on_texture_chooser_selection_changed(GtkFileChooser*, gpointer);
void     on_texture_show_toggled(GtkToggleButton*, gpointer);
void     on_win_destroy_event();

#endif
