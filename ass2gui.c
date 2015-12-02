#include "ass2gui.h"

static GtkBuilder *builder;
static GtkWidget *window;

extern void* app;

struct Application;
void call_SetFov(struct Application*, float);
void call_OpenOffFile(struct Application*, char* filename);
void call_SetFov(struct Application*, float fov);
void call_OpenOffFile(struct Application*, char* filename);
void call_SetParallellProjection(struct Application*);
void call_SetTop(struct Application*, float top);
void call_SetFar(struct Application*, float far);
void call_SetObliqueScale(struct Application*, float oblique_scale);
void call_SetObliqueAngle(struct Application*, float oblique_angle);
void call_SetPerspectiveProjection(struct Application*);

void OpenOffFile(char* filename) {
	call_OpenOffFile((struct Application*) app, filename);
}

void validate_ui()
{
	GtkWidget *widget;

	gfloat oblscale = gtk_adjustment_get_value(
			(GtkAdjustment*) gtk_builder_get_object(builder, "adj_oblscale"));
	gboolean parallel = gtk_toggle_button_get_active(
			(GtkToggleButton*) gtk_builder_get_object(builder, "btn_parallel"));

	gboolean on = !parallel;

	widget = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_fov"));
	gtk_widget_set_sensitive(widget, on);
	widget = GTK_WIDGET(gtk_builder_get_object(builder, "spin_fov"));
	gtk_widget_set_sensitive(widget, on);
	widget = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_pefar"));
	gtk_widget_set_sensitive(widget, on);
	widget = GTK_WIDGET(gtk_builder_get_object(builder, "spin_pefar"));
	gtk_widget_set_sensitive(widget, on);
	widget = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_oblangle"));
	gtk_widget_set_sensitive(widget, !on);
	widget = GTK_WIDGET(gtk_builder_get_object(builder, "spin_oblangle"));
	gtk_widget_set_sensitive(widget, !on);
	widget = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_oblscale"));
	gtk_widget_set_sensitive(widget, !on);
	widget = GTK_WIDGET(gtk_builder_get_object(builder, "spin_oblscale"));
	gtk_widget_set_sensitive(widget, !on);
	widget = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_plfar"));
	gtk_widget_set_sensitive(widget, !on);
	widget = GTK_WIDGET(gtk_builder_get_object(builder, "spin_plfar"));
	gtk_widget_set_sensitive(widget, !on);
	widget = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_top"));
	gtk_widget_set_sensitive(widget, !on);
	widget = GTK_WIDGET(gtk_builder_get_object(builder, "spin_top"));
	gtk_widget_set_sensitive(widget, !on);

	if (parallel && oblscale < 0.01) {
		widget = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_oblangle"));
		gtk_widget_set_sensitive(widget, FALSE);
		widget = GTK_WIDGET(gtk_builder_get_object(builder, "spin_oblangle"));
		gtk_widget_set_sensitive(widget, FALSE);
	}
}

/*  Set projection to orthographic
 */
void gui_set_projection_parallel()
{
	gtk_toggle_button_set_active((GtkToggleButton*) gtk_builder_get_object(builder, "btn_parallel"),
			TRUE);
}

/*  Set projection to perspective
 */
void gui_set_projection_perspective()
{
	gtk_toggle_button_set_active(
			(GtkToggleButton*) gtk_builder_get_object(builder, "btn_perspective"), TRUE);
}

/*  Set option value of far
 *  inputs:
 *      value: new value
 */
void gui_set_option_far(gdouble value)
{
	gtk_adjustment_set_value((GtkAdjustment*) gtk_builder_get_object(builder, "adj_far"), value);
}

/*  Set option value of top
 *  inputs:
 *      value: new value
 */
void gui_set_option_top(gdouble value)
{
	gtk_adjustment_set_value((GtkAdjustment*) gtk_builder_get_object(builder, "adj_top"), value);
}

/*  Set option value of oblique ratio
 *  inputs:
 *      value: new value
 */
void gui_set_option_oblique_scale(gdouble value)
{
	gtk_adjustment_set_value((GtkAdjustment*) gtk_builder_get_object(builder, "adj_oblscale"),
			value);
}

/*  Set option value of oblique angle
 *  inputs:
 *      value: new value
 */
void gui_set_option_oblique_angle(gdouble value)
{
	gtk_adjustment_set_value((GtkAdjustment*) gtk_builder_get_object(builder, "adj_oblangle"),
			value);
}

/*  Set option value of angle ov view
 *  inputs:
 *      value: new value
 */
void gui_set_option_fov(gdouble value)
{
	gtk_adjustment_set_value((GtkAdjustment*) gtk_builder_get_object(builder, "adj_fov"), value);
}

/*  Called when a file is chosen.
 *  inputs:
 *    btn: pointer to the button widget.
 *    user_data: unknown or null.
 */
void on_file_chooser_file_set(GtkFileChooser *filechooser, gpointer user_data)
{
	gchar* filename = gtk_file_chooser_get_filename(filechooser);
	printf("File chosen: %s\n", filename);
	call_OpenOffFile((struct Application*) app, (char*) filename);
}

/*  Called when window closes.
 *  inputs:
 *    btn: pointer to the button widget.
 *    user_data: unknown or null.
 */
void on_window_hide(GtkWidget *widget, gpointer user_data)
{
	printf("Exits\n");
	exit(0);
}

/*  Called when top value changes value
 *  inputs:
 *    btn: pointer to the adjustment object.
 *    user_data: unknown or null.
 */
void on_top_value_changed(GtkAdjustment* o, gpointer user_data)
{
	gdouble dvalue = gtk_adjustment_get_value(o);
	printf("Top: %f\n", dvalue);
	call_SetTop((struct Application*) app, (float) dvalue);
}

/*  Called when aov value changes value
 *  inputs:
 *    btn: pointer to the adjustment object.
 *    user_data: unknown or null.
 */
void on_far_value_changed(GtkAdjustment* o, gpointer user_data)
{
	gdouble dvalue = gtk_adjustment_get_value(o);
	printf("Far %f\n", dvalue);
	call_SetFar((struct Application*) app, (float) dvalue);
}

/*  Called when oblique scale value changes value
 *  inputs:
 *    btn: pointer to the adjustment object.
 *    user_data: unknown or null.
 */
void on_oblique_scale_value_changed(GtkAdjustment* o, gpointer user_data)
{
	gdouble dvalue = gtk_adjustment_get_value(o);
	printf("Oblique scale %f\n", dvalue);
	validate_ui();
	call_SetObliqueScale((struct Application*) app, (float) dvalue);
}

/*  Called when oblique angle value changes value
 *  inputs:
 *    btn: pointer to the adjustment object.
 *    user_data: unknown or null.
 */
void on_oblique_angle_value_changed(GtkAdjustment* o, gpointer user_data)
{
	gdouble dvalue = gtk_adjustment_get_value(o);
	printf("Oblique angle %f\n", dvalue);
	call_SetObliqueAngle((struct Application*) app, (float) dvalue);
}

/*  Called when aov value changes value
 *  inputs:
 *    btn: pointer to the adjustment object.
 *    user_data: unknown or null.
 */
void on_fov_value_changed(GtkAdjustment* o, gpointer user_data)
{
	gdouble dvalue = gtk_adjustment_get_value(o);
	printf("FoV: %f\n", dvalue);
	call_SetFov((struct Application*) app, (float) dvalue);
}

/*  Called when orthographic-button is clicked.
 *  inputs:
 *    btn: pointer to the button widget.
 *    user_data: unknown or null.
 */
void on_parallel_toggled(GtkToggleButton *btn, gpointer user_data)
{
	validate_ui();
	gboolean b = gtk_toggle_button_get_active(btn);
	printf("Parallel: %i\n", b);
	call_SetParallellProjection((struct Application*) app);
}

/*  Called when perspective-button is clicked.
 *  inputs:
 *    btn: pointer to the button widget.
 *    user_data: unknown or null.
 */
void on_perspective_toggled(GtkToggleButton *btn, gpointer user_data)
{
	validate_ui();
	gboolean b = gtk_toggle_button_get_active(btn);
	printf("Perspective: %i\n", b);
	call_SetPerspectiveProjection((struct Application*) app);
}

/* Initialize GTK.
 */
void initGuiWindow(const char* name)
{
	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, name, (GError**) NULL);
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
	gtk_builder_connect_signals(builder, NULL);

	validate_ui();

	gtk_widget_show(window);
}

/* Initializes the glade gui.
 input:
 argc: number of string items in argv.
 argv: command line arguments as a string array.
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

