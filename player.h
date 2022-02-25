#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* This file contains the data structure of player
*/

typedef struct Player
{
    int number;
    char player_name[10]; 
    struct Player * next;
} player;

typedef struct Player_List 
{
    player* first;
} player_list;

// initialize the list with n players
player* init_list(int n);

// get the next player who will play next
player* get_next_player(player* p);

// get the player who will play before player p
player* get_previous_player(player* p);

// get the number of players
int get_player_count(player* head);

// destroy the list of players
void destroy_players(player* head);

// get the first player
player* get_first_player(player* head);

// get the last player
player* get_last_player(player* head);

#endif // !PLAYER_H
