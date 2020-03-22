#include <gtk/gtk.h>

int main (int argc, char *argv[]) {
    GtkWidget *window, *screen;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "Corona Virus Simulation");
    gtk_window_set_default_size (GTK_WINDOW (window), 500, 500);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}