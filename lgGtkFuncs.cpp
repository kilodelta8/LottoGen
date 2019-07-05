#include <gtk/gtk.h>

//Handler function to exit the program
void end_program(GtkWidget *wid, gpointer ptr)
{
	gtk_main_quit();
}

//handler to set numbers to window
void copyText(GtkWidget *wid, gpointer ptr)
{
    const char *input = gtk_entry_get_text(GTK_ENTRY(txt));
    gtk_label_set_text(GTK_LABEL(ptr), input);
}
