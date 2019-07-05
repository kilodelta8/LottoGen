#include <gtk/gtk.h>

//Handler function to exit the program
void end_program(GtkWidget *wid, gpointer ptr)
{
	gtk_main_quit();
}

//TODO - 1. add all gtk handler functions here, then defs to lgGtkFuncs.h