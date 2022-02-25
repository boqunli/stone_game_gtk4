#ifndef DIALOG_H
#define DIALOG_H 
#include <gtk/gtk.h>

void show_info(GtkWidget *widget, gpointer window);

void show_error(GtkWidget *widget, gpointer window);

void show_question(GtkWidget *widget, gpointer window);

void show_warning(GtkWidget *widget, gpointer window);

GtkWidget *create_window(const gint w, const gint h);

#endif // !DIALOG_H