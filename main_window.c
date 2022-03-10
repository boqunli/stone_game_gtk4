#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "player.h"

// the total number of stones in the heap
int num_stones = 10;
int current_stone_num = 10;
// the current player
player *current_player = NULL;

GtkWidget* label2;
GtkWidget* label4;

static void
change_heap1(GtkWidget *widget,
             gpointer   window)
{
  // call back function of choosing to take 1 stone;
  g_print ("Taking 1 stone\n");
  current_stone_num--;
  if (current_stone_num > 0) {
    current_player = current_player->next;
    char buff[33];
    itoa(current_stone_num, buff, 10);
    gtk_label_set_text (GTK_LABEL (label2), buff);
    gtk_label_set_text (GTK_LABEL (label4), current_player->player_name);
  }
  else if (current_stone_num <= 0) {
    g_print("player : %s lose!", current_player->player_name);
    char buff[100];
    sprintf_s(buff, 
              100, 
              "<span foreground='blue' font_desc='32'>%s lose !</span>", 
              current_player->player_name
    );
    // GtkWidget* window;
    // window = gtk_window_new();
    // gtk_window_set_title (GTK_WINDOW (window), "winner !");
    // gtk_window_set_default_size (GTK_WINDOW (window), 400, 300);
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(window,
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_INFO,
            GTK_BUTTONS_CLOSE,
            buff, "title"
    );
    gtk_window_set_title(GTK_WINDOW(dialog), "We have a loser!");
    gtk_message_dialog_set_markup (
      GTK_MESSAGE_DIALOG (dialog),
      buff
    );
    gtk_widget_show(dialog);
    

  }

}

static void
change_heap2(GtkWidget *widget,
             gpointer   window)
{
  // call back function of choosing to take 1 stone;
  g_print ("Taking 2 stones\n");
  current_stone_num -= 2;
  if (current_stone_num > 0) {
    current_player = current_player->next;
    char buff[33];
    itoa(current_stone_num, buff, 10);
    gtk_label_set_text (GTK_LABEL (label2), buff);
    gtk_label_set_text (GTK_LABEL (label4), current_player->player_name);
  }
  else if (current_stone_num <= 0) {
    g_print("player : %s lose!", current_player->player_name);
    char buff[100];
    sprintf_s(buff, 
              100, 
              "<span foreground='blue' font_desc='32'>%s lose !</span>", 
              current_player->player_name
    );
    // GtkWidget* window;
    // window = gtk_window_new();
    // gtk_window_set_title (GTK_WINDOW (window), "winner !");
    // gtk_window_set_default_size (GTK_WINDOW (window), 400, 300);
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(window,
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_INFO,
            GTK_BUTTONS_CLOSE,
            buff, "title"
    );
    gtk_window_set_title(GTK_WINDOW(dialog), "We have a loser!");
    gtk_message_dialog_set_markup (
      GTK_MESSAGE_DIALOG (dialog),
      buff
    );
    gtk_widget_show(dialog);
  }
}

static void
change_heap3(GtkWidget *widget,
             gpointer   window)
{
  // call back function of choosing to take 1 stone;
  g_print ("Taking 3 stones\n");
  current_stone_num -= 3;
  if (current_stone_num > 0) {
    current_player = current_player->next;
    char buff[33];
    itoa(current_stone_num, buff, 10);
    gtk_label_set_text (GTK_LABEL (label2), buff);
    gtk_label_set_text (GTK_LABEL (label4), current_player->player_name);
  }
  if (current_stone_num <= 0) {
    g_print("player : %s lose!", current_player->player_name);
    char buff[100];
    sprintf_s(buff, 
              100, 
              "<span foreground='blue' font_desc='32'>%s lose !</span>", 
              current_player->player_name
    );
    // GtkWidget* window;
    // window = gtk_window_new();
    // gtk_window_set_title (GTK_WINDOW (window), "winner !");
    // gtk_window_set_default_size (GTK_WINDOW (window), 400, 300);
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(window,
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_INFO,
            GTK_BUTTONS_CLOSE,
            buff, "title"
    );
    gtk_window_set_title(GTK_WINDOW(dialog), "We have a loser!");
    gtk_message_dialog_set_markup (
      GTK_MESSAGE_DIALOG (dialog),
      buff
    );
    gtk_widget_show(dialog);
  }
}


static
void on_button_clicked_clear (GtkWidget* button, gpointer data)
{
  // callback function for clearing
  GtkEntryBuffer* buf = gtk_entry_get_buffer((GTK_ENTRY(data)));
  gtk_entry_buffer_set_text ( buf, "", 0 );
}

static
void on_button_clicked_set (GtkWidget* button,gpointer data)
{
  // callback function of setting heap num_stones
  GtkEntryBuffer* buf = gtk_entry_get_buffer((GTK_ENTRY(data)));
  const char* number = gtk_entry_buffer_get_text(buf);
  g_print("%s", number);
  g_print("\n%d\n", atoi(number));
  num_stones = atoi(number);
}

static void
exit_game (GtkWidget *widget,
             gpointer   data)
{
  GtkWindow *win = GTK_WINDOW (data);
  gtk_window_destroy (win);
  if (current_player) {
    destroy_players(current_player);
  }
}

static void 
exit_current_game (GtkWidget *widget,
                    gpointer data)
{
  GtkWindow *win = GTK_WINDOW (data);
  gtk_window_destroy (win);
}

static void
start_game (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
  // set the global variables
  if (!current_player)  {
    current_player = init_list(2);
  }
  while (current_player->number != 1) {
    current_player = current_player->next;
  }
  current_stone_num = num_stones;

  GtkApplication *app = GTK_APPLICATION(data);
  GtkWidget* window = gtk_window_new();
  // GtkWidget* window = gtk_application_window_new (app);

  gtk_window_set_title (GTK_WINDOW (window), "STONE_GAME_GAME 游戏");
  gtk_window_set_default_size (GTK_WINDOW (window), 600, 400);

  GtkWidget* box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
  gtk_widget_set_halign (box, GTK_ALIGN_CENTER);
  gtk_widget_set_valign (box, GTK_ALIGN_CENTER);
  GtkWidget* box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
  gtk_widget_set_halign (box1, GTK_ALIGN_CENTER);
  gtk_widget_set_valign (box1, GTK_ALIGN_CENTER);
  GtkWidget* box11 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
  gtk_widget_set_halign (box1, GTK_ALIGN_CENTER);
  gtk_widget_set_valign (box1, GTK_ALIGN_CENTER);
  GtkWidget* box12 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
  gtk_widget_set_halign (box1, GTK_ALIGN_CENTER);
  gtk_widget_set_valign (box1, GTK_ALIGN_CENTER);
  gtk_box_append (GTK_BOX(box1),box11);
  gtk_box_append (GTK_BOX(box1),box12);
  GtkWidget* box2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
  gtk_widget_set_halign (box2, GTK_ALIGN_CENTER);
  gtk_widget_set_valign (box2, GTK_ALIGN_CENTER);
  GtkWidget* sep = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
  gtk_window_set_child (GTK_WINDOW (window), box);
  gtk_box_append (GTK_BOX(box),box1);
  gtk_box_append (GTK_BOX(box),sep);
  gtk_box_append (GTK_BOX(box),box2);

  // stones
  GtkWidget* label1 = gtk_label_new("当前石子数量: ");
  char buff[33];
  itoa(num_stones, buff, 10);
  // GtkWidget* label2 = gtk_label_new(buff);
  // gtk_label_set_text (label2, buff);
  label2 = gtk_label_new(buff);
  gtk_box_append(GTK_BOX(box11),label1);
  gtk_box_append(GTK_BOX(box11),label2);

  // players
  GtkWidget* label3 = gtk_label_new("当前玩家: ");
  // gtk_label_set_text (label4, current_player->player_name);
  label4 = gtk_label_new(current_player->player_name);
  // GtkWidget* label4 = gtk_label_new(current_player->player_name);
  gtk_box_append(GTK_BOX(box11),label3);
  gtk_box_append(GTK_BOX(box11),label4);

  GtkWidget* button1 = gtk_button_new_with_label("拿1个");
  g_signal_connect(G_OBJECT(button1),"clicked",G_CALLBACK(change_heap1), window);
  gtk_box_append(GTK_BOX(box2),button1);
  gtk_widget_show(button1);
  GtkWidget* button2 = gtk_button_new_with_label("拿2个");
  g_signal_connect(G_OBJECT(button2),"clicked",G_CALLBACK(change_heap2), window);
  gtk_box_append(GTK_BOX(box2),button2);
  gtk_widget_show(button2);
  GtkWidget* button3 = gtk_button_new_with_label("拿3个");
  g_signal_connect(G_OBJECT(button3),"clicked",G_CALLBACK(change_heap3), window);
  gtk_box_append(GTK_BOX(box2),button3);
  gtk_widget_show(button3);

  GtkWidget* button4 = gtk_button_new_with_label("退出此游戏");
  g_signal_connect(G_OBJECT(button4), "clicked", G_CALLBACK(exit_current_game), window);
  // g_signal_connect_swapped (button4, "clicked", G_CALLBACK (gtk_window_destroy), window);
  
  gtk_box_append(GTK_BOX(box2),button4);
  gtk_widget_show(button4);

  gtk_widget_show (window);
}

static void
settings (GtkWidget *widget,
             gpointer   data)
{
  GError *err = NULL;
  // the callback function of settings
  g_print ("Setting\n");
  // GtkApplication *app = GTK_APPLICATION(data);
  GtkBuilder* builder = gtk_builder_new();
  gboolean built = gtk_builder_add_from_file(builder, "settings.ui", &err);
  // https://docs.gtk.org/gtk4/method.Builder.add_from_file.html
  // TRUE on success, FALSE if an error occurred.
  // g_assert (built == TRUE);
  if (err) {
    fprintf (stderr, "Unable to read file: %s\n", err->message);
    g_error_free(err);
    return;
  }
  GObject* window = gtk_builder_get_object(builder, "dialog_settings");

  // gtk_window_set_title (GTK_WINDOW (window), "STONE_GAME_SETTING 设置");
  // gtk_window_set_default_size (GTK_WINDOW (window), 400, 300);
  // GtkDialog mapped without a transient parent. This is discouraged.
  gtk_window_set_transient_for (GTK_WINDOW (window), GTK_WINDOW (data));

  // GObject* label1 = gtk_builder_get_object(builder, "number_label");
  GObject* entry1 = gtk_builder_get_object(builder, "number_entry");

  GObject* button1 = gtk_builder_get_object(builder, "clear_button");
  g_signal_connect(GTK_WIDGET (button1), "clicked", G_CALLBACK(on_button_clicked_clear), entry1);
  gtk_widget_show (GTK_WIDGET (button1));

  GObject* button2 = gtk_builder_get_object(builder, "confirm_button");
  g_signal_connect(GTK_WIDGET (button2), "clicked", G_CALLBACK(on_button_clicked_set), GTK_WIDGET (entry1));
  g_signal_connect_swapped(GTK_WIDGET (button2), "clicked", G_CALLBACK(gtk_window_destroy), GTK_WINDOW (window));
  gtk_widget_show (GTK_WIDGET (button2));

  gtk_widget_show (GTK_WIDGET (window));
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

  g_signal_connect (button_settings, "clicked", G_CALLBACK (settings), window);
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
