#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#define __mm_malloc(a, b) malloc(a)

void on_input_button_clicked(GtkButton *button, gpointer user_data) {
    GtkWidget *entry_shock = (GtkWidget*)user_data;
    GtkWidget *entry_acceleration = (GtkWidget*)g_object_get_data(G_OBJECT(button), "entry_acceleration");
    const gchar *shock_str = gtk_entry_get_text(GTK_ENTRY(entry_shock));
    const gchar *acceleration_str = gtk_entry_get_text(GTK_ENTRY(entry_acceleration));
    double shock = atof(shock_str);
    double acceleration = atof(acceleration_str);
}

void on_output_button_clicked(GtkButton *button, gpointer user_data) {
    GtkWidget *entry_shock = (GtkWidget*)g_object_get_data(G_OBJECT(button), "entry_shock");
    GtkWidget *entry_acceleration = (GtkWidget*)user_data;

    const gchar *shock_str = gtk_entry_get_text(GTK_ENTRY(entry_shock));
    const gchar *acceleration_str = gtk_entry_get_text(GTK_ENTRY(entry_acceleration));

    double shock = atof(shock_str);
    double acceleration = atof(acceleration_str);

    FILE *fp = fopen("data.txt", "w");
    fprintf(fp, "Shock: %f\nAcceleration: %f", shock, acceleration);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Shock and Acceleration Data");
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 150);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    GtkWidget *input_button = gtk_button_new_with_label("Input");
    GtkWidget *output_button = gtk_button_new_with_label("Output");
    GtkWidget *entry_shock = gtk_entry_new();
    GtkWidget *entry_acceleration = gtk_entry_new();
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    gtk_container_add(GTK_CONTAINER(vbox), entry_shock);
    gtk_container_add(GTK_CONTAINER(vbox), entry_acceleration);
    gtk_container_add(GTK_CONTAINER(vbox), input_button);
    gtk_container_add(GTK_CONTAINER(vbox), output_button);

    gtk_container_add(GTK_CONTAINER(window), vbox);

    g_object_set_data(G_OBJECT(input_button), "entry_acceleration", entry_acceleration);
    g_signal_connect(input_button, "clicked", G_CALLBACK(on_input_button_clicked), entry_shock);
    g_object_set_data(G_OBJECT(output_button), "entry_shock", entry_shock);
    g_signal_connect(output_button, "clicked", G_CALLBACK(on_output_button_clicked), entry_acceleration);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
