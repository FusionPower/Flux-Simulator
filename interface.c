#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "interface.h"

int n=10,m=10;

int main (int argc, char *argv[]) {
    GtkWidget *window, *boxes[n][m], *grid;
    gtk_init(&argc, &argv);

    window = init_window();
    grid = init_grid(window);

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            char label_string[3]=" 0 ";
            GtkWidget *label = gtk_label_new(label_string);
            boxes[i][j] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 30);
            gtk_box_pack_start(GTK_BOX(boxes[i][j]), label, 0, 1, 1);
            gtk_grid_attach(GTK_GRID(grid), boxes[i][j], i, j, 1, 1);
        }
    }

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}