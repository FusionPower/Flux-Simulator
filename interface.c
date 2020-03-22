#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "interface.h"
/*
Para correr se necesita agregar `pkg-config --cflags --libs gtk+-3.0` al final del commando gcc, ejemplo:
gcc interface.c -o interface `pkg-config --cflags --libs gtk+-3.0`

Nota: NO son comillas, hasta donde se deben ser backticks, lo cual normalmente esta en los teclados americano
*/
int n=10,m=10;

int main (int argc, char *argv[]) {
    GtkWidget *window, *button[n][m], *grid;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    load_css();

    gtk_window_set_title(GTK_WINDOW(window), "Corona Virus Simulation");
    gtk_window_set_default_size (GTK_WINDOW (window), 500, 500);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    grid = gtk_grid_new();
    gtk_container_set_border_width ( GTK_CONTAINER ( grid ), 15 );
    gtk_grid_set_column_spacing ( GTK_GRID ( grid ), 4 );
    gtk_grid_set_row_spacing ( GTK_GRID ( grid ), 4 );
    gtk_container_add(GTK_CONTAINER(window), grid);

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            char label[10] = "";
            strcat(label, i+"0");
            strcat(label, j+"0");
            button[i][j] = gtk_button_new_with_label(label);
            gtk_grid_attach(GTK_GRID(grid), button[i][j], i, j, 1, 1);
        }
    }

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}