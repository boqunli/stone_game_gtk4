#include <gtk/gtk.h>
#include "agent.c"


static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *button_settings, *button_start, *button_exit;
  GtkWidget *box;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "STONE_GAME");
  gtk_window_set_default_size (GTK_WINDOW (window), 1024, 1024);

  box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_widget_set_halign (box, GTK_ALIGN_CENTER);
  gtk_widget_set_valign (box, GTK_ALIGN_CENTER);

  gtk_window_set_child (GTK_WINDOW (window), box);

  button_settings = gtk_button_new_with_label ("SETTINGS");
  button_start = gtk_button_new_with_label ("ENTER GAME");
  button_exit = gtk_button_new_with_label ("EXIT GAME");

  g_signal_connect (button_start, "clicked", G_CALLBACK (print_hello), NULL);
  g_signal_connect_swapped (button_exit, "clicked", G_CALLBACK (gtk_window_destroy), window);

  gtk_box_append (GTK_BOX (box), button_settings);
  gtk_box_append (GTK_BOX (box), button_start);
  gtk_box_append (GTK_BOX (box), button_exit);

  gtk_widget_show (window);
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
