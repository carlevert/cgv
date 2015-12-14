#include "guicontrol.h"

static GtkBuilder *builder;
static GtkWidget *window;

gchar* gui_get_off_file(void) {
    return gtk_file_chooser_get_filename((GtkFileChooser*)gtk_builder_get_object(builder,"off_chooser"));
}

void gui_set_projection_parallel(void)
{
   gtk_toggle_button_set_active((GtkToggleButton*)gtk_builder_get_object(builder,"btn_parallel"), TRUE);
}

void gui_set_projection_perspective(void)
{
   gtk_toggle_button_set_active((GtkToggleButton*)gtk_builder_get_object(builder,"btn_perspective"), TRUE);
}

void gui_set_option_far(gdouble value)
{
   gtk_adjustment_set_value ((GtkAdjustment*)gtk_builder_get_object(builder,"adj_far"), value);
}

void gui_set_option_top(gdouble value)
{
   gtk_adjustment_set_value ((GtkAdjustment*)gtk_builder_get_object(builder,"adj_top"), value);
}

void gui_set_option_oblique_scale(gdouble value)
{
   gtk_adjustment_set_value ((GtkAdjustment*)gtk_builder_get_object(builder,"adj_oblscale"), value);
}

void gui_set_option_oblique_angle(gdouble value)
{
   gtk_adjustment_set_value ((GtkAdjustment*)gtk_builder_get_object(builder,"adj_oblangle"), value);
}

void gui_set_option_fov(gdouble value)
{
   gtk_adjustment_set_value ((GtkAdjustment*)gtk_builder_get_object(builder,"adj_fov"), value);
}

void gui_set_off_file(gchar* filename) {
    gtk_file_chooser_set_filename((GtkFileChooser*)gtk_builder_get_object(builder, "off_chooser"), filename);
}

void gui_set_flip_normals(gboolean b)
{
   gtk_toggle_button_set_active((GtkToggleButton*)gtk_builder_get_object(builder,"flip_normals"), b);
}


gboolean gui_get_flip_normals(void)
{
    return gtk_toggle_button_get_active((GtkToggleButton*)gtk_builder_get_object(builder,"flip_normals"));
}

void gui_set_I_light(gdouble color[3])
{
    gtk_adjustment_set_value((GtkAdjustment*)gtk_builder_get_object(builder,"I_light_r"),color[0]);
    gtk_adjustment_set_value((GtkAdjustment*)gtk_builder_get_object(builder,"I_light_g"),color[1]);
    gtk_adjustment_set_value((GtkAdjustment*)gtk_builder_get_object(builder,"I_light_b"),color[2]);
}

void gui_set_light_pos(gdouble p[3])
{
    gtk_adjustment_set_value((GtkAdjustment*)gtk_builder_get_object(builder,"light_x"),p[0]);
    gtk_adjustment_set_value((GtkAdjustment*)gtk_builder_get_object(builder,"light_y"),p[1]);
    gtk_adjustment_set_value((GtkAdjustment*)gtk_builder_get_object(builder,"light_z"),p[2]);
}

void gui_get_light_pos(gdouble p[3])
{

    p[0] = gtk_adjustment_get_value((GtkAdjustment*)gtk_builder_get_object(builder,"light_x"));
    p[1] = gtk_adjustment_get_value((GtkAdjustment*)gtk_builder_get_object(builder,"light_y"));
    p[2] = gtk_adjustment_get_value((GtkAdjustment*)gtk_builder_get_object(builder,"light_z"));
}

void gui_set_I_ambient(gdouble color[3])
{
    gtk_adjustment_set_value((GtkAdjustment*)gtk_builder_get_object(builder,"I_ambient_r"),color[0]);
    gtk_adjustment_set_value((GtkAdjustment*)gtk_builder_get_object(builder,"I_ambient_g"),color[1]);
    gtk_adjustment_set_value((GtkAdjustment*)gtk_builder_get_object(builder,"I_ambient_b"),color[2]);
}

void gui_set_k_ambient(gdouble k[3])
{
    gtk_adjustment_set_value((GtkAdjustment*)gtk_builder_get_object(builder,"k_ambient_r"), k[0]);
    gtk_adjustment_set_value((GtkAdjustment*)gtk_builder_get_object(builder,"k_ambient_g"), k[1]);
    gtk_adjustment_set_value((GtkAdjustment*)gtk_builder_get_object(builder,"k_ambient_b"), k[2]);
}

void gui_get_k_ambient(gdouble k[3])
{
    k[0] = gtk_adjustment_get_value((GtkAdjustment*)gtk_builder_get_object(builder,"k_ambient_r"));
    k[1] = gtk_adjustment_get_value((GtkAdjustment*)gtk_builder_get_object(builder,"k_ambient_g"));
    k[2] = gtk_adjustment_get_value((GtkAdjustment*)gtk_builder_get_object(builder,"k_ambient_b"));
}

void gui_set_k_diffuse(gdouble k[3])
{
    gtk_adjustment_set_value((GtkAdjustment*)gtk_builder_get_object(builder,"k_diffuse_r"), k[0]);
    gtk_adjustment_set_value((GtkAdjustment*)gtk_builder_get_object(builder,"k_diffuse_g"), k[1]);
    gtk_adjustment_set_value((GtkAdjustment*)gtk_builder_get_object(builder,"k_diffuse_b"), k[2]);
}

void gui_get_k_diffuse(gdouble k[3])
{
    k[0] = gtk_adjustment_get_value((GtkAdjustment*)gtk_builder_get_object(builder,"k_diffuse_r"));
    k[1] = gtk_adjustment_get_value((GtkAdjustment*)gtk_builder_get_object(builder,"k_diffuse_g"));
    k[2] = gtk_adjustment_get_value((GtkAdjustment*)gtk_builder_get_object(builder,"k_diffuse_b"));
}


void gui_set_k_specular(gdouble k[3])
{
    gtk_adjustment_set_value((GtkAdjustment*)gtk_builder_get_object(builder,"k_specular_r"), k[0]);
    gtk_adjustment_set_value((GtkAdjustment*)gtk_builder_get_object(builder,"k_specular_g"), k[1]);
    gtk_adjustment_set_value((GtkAdjustment*)gtk_builder_get_object(builder,"k_specular_b"), k[2]);
}


void gui_get_k_specular(gdouble k[3])
{
    k[0] = gtk_adjustment_get_value((GtkAdjustment*)gtk_builder_get_object(builder,"k_specular_r"));
    k[1] = gtk_adjustment_get_value((GtkAdjustment*)gtk_builder_get_object(builder,"k_specular_g"));
    k[2] = gtk_adjustment_get_value((GtkAdjustment*)gtk_builder_get_object(builder,"k_specular_b"));
}

void gui_set_phong(guint16 phong)
{
    gtk_adjustment_set_value((GtkAdjustment*)gtk_builder_get_object(builder,"phong"), 1 > phong ? 1 : phong);
}

gdouble gui_get_phong(void)
{
    return gtk_adjustment_get_value((GtkAdjustment*)gtk_builder_get_object(builder,"phong"));
}

void guiInitWindow(const char* name)
{
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, name, (GError**)NULL);
    window = (GtkWidget *)(gtk_builder_get_object (builder, "window"));
    gtk_builder_connect_signals (builder, NULL);

    validate_ui();
}

void validate_ui(void)
{
	GtkWidget *widget;

	gfloat oblscale = gtk_adjustment_get_value((GtkAdjustment*)gtk_builder_get_object(builder,"adj_oblscale"));
	gboolean parallel = gtk_toggle_button_get_active((GtkToggleButton*)gtk_builder_get_object(builder,"btn_parallel"));

	gboolean on = !parallel;

	widget = GTK_WIDGET (gtk_builder_get_object (builder, "lbl_fov"));
	gtk_widget_set_sensitive(widget, on);
	widget = GTK_WIDGET (gtk_builder_get_object (builder, "spin_fov"));
	gtk_widget_set_sensitive(widget, on);
	widget = GTK_WIDGET (gtk_builder_get_object (builder, "lbl_pefar"));
	gtk_widget_set_sensitive(widget, on);
	widget = GTK_WIDGET (gtk_builder_get_object (builder, "spin_pefar"));
	gtk_widget_set_sensitive(widget, on);
	widget = GTK_WIDGET (gtk_builder_get_object (builder, "lbl_oblangle"));
	gtk_widget_set_sensitive(widget, !on);
	widget = GTK_WIDGET (gtk_builder_get_object (builder, "spin_oblangle"));
	gtk_widget_set_sensitive(widget, !on);
	widget = GTK_WIDGET (gtk_builder_get_object (builder, "lbl_oblscale"));
	gtk_widget_set_sensitive(widget, !on);
	widget = GTK_WIDGET (gtk_builder_get_object (builder, "spin_oblscale"));
	gtk_widget_set_sensitive(widget, !on);
	widget = GTK_WIDGET (gtk_builder_get_object (builder, "lbl_plfar"));
	gtk_widget_set_sensitive(widget, !on);
	widget = GTK_WIDGET (gtk_builder_get_object (builder, "spin_plfar"));
	gtk_widget_set_sensitive(widget, !on);
	widget = GTK_WIDGET (gtk_builder_get_object (builder, "lbl_top"));
	gtk_widget_set_sensitive(widget, !on);
	widget = GTK_WIDGET (gtk_builder_get_object (builder, "spin_top"));
	gtk_widget_set_sensitive(widget, !on);

	if (parallel && oblscale < 0.01) {
		widget = GTK_WIDGET (gtk_builder_get_object (builder, "lbl_oblangle"));
		gtk_widget_set_sensitive(widget, FALSE);
		widget = GTK_WIDGET (gtk_builder_get_object (builder, "spin_oblangle"));
		gtk_widget_set_sensitive(widget, FALSE);
	}
}

/* Initialize GTK.
 */
void guiInit(int *argc, char** argv)
{
    gtk_init(argc, &argv);
}

/* Calls a single GTK main loop iteration to process
 * events (non-blocking).
 */
void guiMainIteration(void)
{
    gtk_main_iteration_do(0);
}


