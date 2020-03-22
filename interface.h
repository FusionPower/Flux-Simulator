void load_css ( void )
{
    GtkCssProvider *provider;
    GdkDisplay     *display;
    GdkScreen      *screen;
    /// ***
    const gchar *css_style_file = "style.css";
    GFile *css_fp               = g_file_new_for_path ( css_style_file );
    GError *error               = 0;
    /// ***
    provider = gtk_css_provider_new ();
    display  = gdk_display_get_default ();
    screen   = gdk_display_get_default_screen ( display );
    /// ***
    gtk_style_context_add_provider_for_screen   ( screen, GTK_STYLE_PROVIDER ( provider ), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION );
    gtk_css_provider_load_from_file             ( provider, css_fp, &error );
    /// ***
    g_object_unref ( provider );
}

GtkWidget *init_window(void){
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    load_css();

    gtk_window_set_title(GTK_WINDOW(window), "Corona Virus Simulation");
    gtk_window_set_default_size (GTK_WINDOW (window), 0, 0);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    return window;
}

GtkWidget *init_grid(GtkWidget *window){
    GtkWidget *grid = gtk_grid_new();
    gtk_container_set_border_width ( GTK_CONTAINER ( grid ), 15 );
    gtk_grid_set_column_spacing ( GTK_GRID ( grid ), 3 );
    gtk_grid_set_row_spacing ( GTK_GRID ( grid ), 3 );
    gtk_container_add(GTK_CONTAINER(window), grid);
    return grid;
}