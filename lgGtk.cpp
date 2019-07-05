#include <iostream>
#include <gtk/gtk.h>
#include "lgGtkFuncs.h"
#include "lottogen.h"


int main(int argc, char *argv[])
{
    //TODO - 1. Organzise code so it is manageable and easy to read
    //init gtk
    gtk_init(&argc, &argv);

    //create the main window
    GtkWidget *mainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    //Create a button
	GtkWidget *btn = gtk_button_new_with_label("Show Numbers");

    //create a label and a vbox
	GtkWidget *lbl = gtk_label_new("Winning Numbers");

    //when X is clicked
	g_signal_connect(mainWindow, "delete_event", G_CALLBACK(end_program), NULL);



    //make a gtk vbox
	GtkWidget *box = gtk_vbox_new(FALSE, 5);

    //place the widgets into the box(es)
	gtk_box_pack_start(GTK_BOX(box), btn, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(box), lbl, TRUE, TRUE, 0);

	//add the box(es) to the main window
	gtk_container_add(GTK_CONTAINER(mainWindow), box);



    //run and show the main window
    gtk_widget_show_all(mainWindow);

    //run the main window loop
    gtk_main();

    return 0;
}