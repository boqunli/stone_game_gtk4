#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int num_stones = 10;

static void
start_game (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
  GtkApplication *app = GTK_APPLICATION(data);
  GtkWidget* window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "STONE_GAME_GAME 游戏");
  gtk_window_set_default_size (GTK_WINDOW (window), 600, 400);

  GtkWidget* box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
  gtk_widget_set_halign (box, GTK_ALIGN_CENTER);
  gtk_widget_set_valign (box, GTK_ALIGN_CENTER);
  GtkWidget* box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_widget_set_halign (box1, GTK_ALIGN_CENTER);
  gtk_widget_set_valign (box1, GTK_ALIGN_CENTER);
  GtkWidget* box2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
  gtk_widget_set_halign (box2, GTK_ALIGN_CENTER);
  gtk_widget_set_valign (box2, GTK_ALIGN_CENTER);
  GtkWidget* sep = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
  gtk_window_set_child (GTK_WINDOW (window), box);
  gtk_box_append (GTK_BOX(box),box1);
  gtk_box_append (GTK_BOX(box),sep);
  gtk_box_append (GTK_BOX(box),box2);


  GtkWidget* label1 = gtk_label_new("当前石子数量：");
  GtkWidget* entry1 = gtk_entry_new();
  gtk_box_append(GTK_BOX(box1),label1);
  gtk_box_append(GTK_BOX(box1),entry1);

  GtkWidget* button1 = gtk_button_new_with_label("清空");
  g_signal_connect(G_OBJECT(button1),"clicked",G_CALLBACK(on_button_clicked_clear), entry1);
  gtk_box_append(GTK_BOX(box2),button1);
  gtk_widget_show(button1);

  GtkWidget* button2 = gtk_button_new_with_label("确认");
  g_signal_connect(G_OBJECT(button2), "clicked", G_CALLBACK(on_button_clicked_set), entry1);
  g_signal_connect_swapped(G_OBJECT(button2), "clicked", G_CALLBACK(gtk_window_destroy), window);
  gtk_box_append(GTK_BOX(box2),button2);
  gtk_widget_show(button2);

  gtk_widget_show (window);
}

static
void on_button_clicked_clear (GtkWidget* button,gpointer data)
{
  GtkEntryBuffer* buf = gtk_entry_get_buffer((GTK_ENTRY(data)));
  gtk_entry_buffer_set_text ( buf, "", 0 );
}

static
void on_button_clicked_set (GtkWidget* button,gpointer data)
{
  GtkEntryBuffer* buf = gtk_entry_get_buffer((GTK_ENTRY(data)));
  const char* number = gtk_entry_buffer_get_text(buf);
  g_print("%s", number);
  g_print("\n%d\n", atoi(number));
  num_stones = atoi(number);
}

static void
settings (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Setting\n");
  GtkApplication *app = GTK_APPLICATION(data);
  GtkWidget* window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "STONE_GAME_SETTING 设置");
  gtk_window_set_default_size (GTK_WINDOW (window), 400, 300);

  GtkWidget* box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
  gtk_widget_set_halign (box, GTK_ALIGN_CENTER);
  gtk_widget_set_valign (box, GTK_ALIGN_CENTER);
  GtkWidget* box1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_widget_set_halign (box1, GTK_ALIGN_CENTER);
  gtk_widget_set_valign (box1, GTK_ALIGN_CENTER);
  GtkWidget* box2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
  gtk_widget_set_halign (box2, GTK_ALIGN_CENTER);
  gtk_widget_set_valign (box2, GTK_ALIGN_CENTER);
  GtkWidget* sep = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
  gtk_window_set_child (GTK_WINDOW (window), box);
  gtk_box_append (GTK_BOX(box),box1);
  gtk_box_append (GTK_BOX(box),sep);
  gtk_box_append (GTK_BOX(box),box2);

 
  GtkWidget* label1 = gtk_label_new("请输入个数：");
  GtkWidget* entry1 = gtk_entry_new();
  gtk_box_append(GTK_BOX(box1),label1);
  gtk_box_append(GTK_BOX(box1),entry1);

  GtkWidget* button1 = gtk_button_new_with_label("清空");
  g_signal_connect(G_OBJECT(button1),"clicked",G_CALLBACK(on_button_clicked_clear), entry1);
  gtk_box_append(GTK_BOX(box2),button1);
  gtk_widget_show(button1);

  GtkWidget* button2 = gtk_button_new_with_label("确认");
  g_signal_connect(G_OBJECT(button2), "clicked", G_CALLBACK(on_button_clicked_set), entry1);
  g_signal_connect_swapped(G_OBJECT(button2), "clicked", G_CALLBACK(gtk_window_destroy), window);
  gtk_box_append(GTK_BOX(box2),button2);
  gtk_widget_show(button2);

  gtk_widget_show (window);
}

static void
exit_game (GtkWidget *widget,
             gpointer   data)
{
  GtkWindow *win = GTK_WINDOW (data);
  gtk_window_destroy (win);
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *button_settings, *button_start, *button_exit;
  GtkWidget *box;
  GtkWidget *label;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "STONE_GAME");
  gtk_window_set_default_size (GTK_WINDOW (window), 600, 400);

  // box
  box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 20);
  gtk_widget_set_halign (box, GTK_ALIGN_CENTER);
  gtk_widget_set_valign (box, GTK_ALIGN_CENTER);

  gtk_window_set_child (GTK_WINDOW (window), box);

  // button
  button_settings = gtk_button_new_with_label ("SETTINGS 设置");
  button_start = gtk_button_new_with_label ("ENTER GAME 开始游戏");
  button_exit = gtk_button_new_with_label ("EXIT GAME 退出游戏");

  g_signal_connect (button_settings, "clicked", G_CALLBACK (settings), app);
  g_signal_connect (button_start, "clicked", G_CALLBACK (start_game), app);
  g_signal_connect (button_exit, "clicked", G_CALLBACK (exit_game), window);
  // g_signal_connect_swapped (button_exit, "clicked", G_CALLBACK (gtk_window_destroy), window);

  // label for welcome
  label = gtk_label_new ("Welcome to my game.");
  gtk_label_set_markup(GTK_LABEL(label),
   "<span foreground='blue' font_desc='32'>Welcome to my game.</span>");

  gtk_box_append (GTK_BOX (box), label);
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
