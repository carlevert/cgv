#include "guicallback.h"


void on_off_chooser_selection_changed(GtkFileChooser *filechooser, gpointer user_data)
{
    gchar* filename = gtk_file_chooser_get_filename(filechooser);
    printf("File chosen: %s\n",filename);
}

void on_flip_normals_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
    gboolean b =  gtk_toggle_button_get_active(togglebutton);
    printf("flip normals: %i\n",b);
}

void on_light_x_value_changed(GtkAdjustment*o,gpointer user_data)
{
    gdouble value = gtk_adjustment_get_value(o);
    printf("Light x: %f\n", value);
}

void on_light_y_value_changed(GtkAdjustment *o,gpointer user_data)
{
    gdouble value = gtk_adjustment_get_value(o);
    printf("Light y: %f\n", value);
}

void on_light_z_value_changed(GtkAdjustment*o, gpointer user_data)
{
    gdouble value = gtk_adjustment_get_value(o);
    printf("Light z: %f\n", value);
}

void on_I_light_r_value_changed (GtkAdjustment *o, gpointer user_data)
{
    gdouble value = gtk_adjustment_get_value(o);
    printf("Light Ir: %f\n", value);
}

void on_I_light_g_value_changed (GtkAdjustment *o, gpointer user_data)
{
    gdouble value = gtk_adjustment_get_value(o);
    printf("Light Ig: %f\n", value);
}

void on_I_light_b_value_changed (GtkAdjustment *o, gpointer user_data)
{
    gdouble value = gtk_adjustment_get_value(o);
    printf("Light Ib: %f\n", value);
}

void on_I_ambient_r_value_changed(GtkAdjustment *o, gpointer user_data)
{
    gdouble value = gtk_adjustment_get_value(o);
    printf("Ambient Ir: %f\n", value);
}

void on_I_ambient_g_value_changed(GtkAdjustment *o, gpointer user_data)
{
    gdouble value = gtk_adjustment_get_value(o);
    printf("Ambient Ig: %f\n", value);
}

void on_I_ambient_b_value_changed(GtkAdjustment *o, gpointer user_data)
{
    gdouble value = gtk_adjustment_get_value(o);
    printf("Ambient Ib: %f\n", value);
}

void on_k_ambient_r_value_changed(GtkAdjustment *o, gpointer user_data)
{
    gdouble value = gtk_adjustment_get_value(o);
    printf("Ambient kr: %f\n", value);
}

void on_k_ambient_g_value_changed(GtkAdjustment *o, gpointer user_data)
{
    gdouble value = gtk_adjustment_get_value(o);
    printf("Ambient kg: %f\n", value);
}

void on_k_ambient_b_value_changed(GtkAdjustment *o, gpointer user_data)
{
    gdouble value = gtk_adjustment_get_value(o);
    printf("Ambient kb: %f\n", value);
}

void on_k_diffuse_r_value_changed(GtkAdjustment *o, gpointer user_data)
{
    gdouble value = gtk_adjustment_get_value(o);
    printf("Diffuse kr: %f\n", value);
}

void on_k_diffuse_g_value_changed(GtkAdjustment *o, gpointer user_data)
{
    gdouble value = gtk_adjustment_get_value(o);
    printf("Diffuse kg: %f\n", value);
}

void on_k_diffuse_b_value_changed (GtkAdjustment *o, gpointer user_data)
{
    gdouble value = gtk_adjustment_get_value(o);
    printf("Diffuse kb: %f\n", value);
}

void on_k_specular_r_value_changed(GtkAdjustment *o, gpointer user_data)
{
    gdouble value = gtk_adjustment_get_value(o);
    printf("Specular kr: %f\n", value);
}

void on_k_specular_g_value_changed(GtkAdjustment *o, gpointer user_data)
{
    gdouble value = gtk_adjustment_get_value(o);
    printf("Specular kg: %f\n", value);
}

void on_k_specular_b_value_changed(GtkAdjustment *o, gpointer user_data)
{
    gdouble value = gtk_adjustment_get_value(o);
    printf("Specular kb: %f\n", value);
}

void on_phong_value_changed(GtkAdjustment *o, gpointer user_data)
{
    gint32 value = (gint32)lround(gtk_adjustment_get_value(o));
    printf("Phong value %i\n", value);
}

void on_window_hide(GtkWidget *widget, gpointer user_data)
{
    printf("Exits\n");
    exit(0);
}

void on_top_value_changed(GtkAdjustment* o, gpointer user_data)
{
	gdouble dvalue = gtk_adjustment_get_value(o);
    printf("Top: %f\n", dvalue);
}

void on_far_value_changed(GtkAdjustment* o, gpointer user_data)
{
	gdouble dvalue = gtk_adjustment_get_value(o);
    printf("Far %f\n", dvalue);
}

void on_oblique_scale_value_changed(GtkAdjustment* o, gpointer user_data)
{
	gdouble dvalue = gtk_adjustment_get_value(o);
    printf("Oblique scale %f\n", dvalue);
	validate_ui();
}

void on_oblique_angle_value_changed(GtkAdjustment* o, gpointer user_data)
{
	gdouble dvalue = gtk_adjustment_get_value(o);
    printf("Oblique angle %f\n", dvalue);
}

void on_fov_value_changed(GtkAdjustment* o, gpointer user_data)
{
	gdouble dvalue = gtk_adjustment_get_value(o);
    printf("FoV: %f\n", dvalue);
}

void on_parallel_toggled(GtkToggleButton *btn, gpointer user_data)
{
	validate_ui();
    gboolean b = gtk_toggle_button_get_active(btn);
    printf("Parallel: %i\n",b);
}

void on_perspective_toggled(GtkToggleButton *btn, gpointer user_data)
{
	validate_ui();
    gboolean b = gtk_toggle_button_get_active(btn);
    printf("Perspective: %i\n",b);
}

void on_texture_chooser_selection_changed(GtkFileChooser *filechooser, gpointer user_data)
{
    gchar* filename = gtk_file_chooser_get_filename(filechooser);
    printf("Texture file: %s\n",filename);
}

void on_texture_show_toggled(GtkToggleButton *btn, gpointer user_data)
{
    gboolean b = gtk_toggle_button_get_active(btn);
    printf("Show Texture: %i\n",b);
}


void on_win_destroy_event()
{
    printf("Quit\n");
    exit(0);
}


