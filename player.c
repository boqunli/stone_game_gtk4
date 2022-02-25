#include "player.h"

player* init_list(int n) {
    if (n < 1) {
        return NULL;
    }
    // create_players with size n;
    player* head = (player*)malloc(sizeof(player));
    head->number = 1;
    strcpy(head->player_name, "Player1");
    head->next = NULL;
    player* cyclic = head;
    for (int i = 2; i <= n; i++) {
        player* body = (player*)malloc(sizeof(player));
        body->number = i;
        body->next=NULL; 
        sprintf_s(body->player_name, 10, "Player%d", i);
        cyclic->next = body;
        cyclic = cyclic->next;
    }
    cyclic->next = head;
    return head;
}


// get the next player who will play next
player* get_next_player(player* p) {
    if (!p) {
        // if not the current player
        // return NULL;
        return NULL;
    }
    return p->next;
}

// get the player who will play before player p
player* get_previous_player(player* p) {
    if (!p) {
        // if not the current player
        // return NULL;
        return NULL;
    }
    player* pp = p;
    if (p->next == pp) {
        return pp;
    }
    while (pp->next != p) {
        pp = pp->next;
    }
    return pp;
}


// get the number of players
int get_player_count(player* head) {
    if (!head) {
        return 0;
    }
    player* iter = head;
    int rtn = 1;
    while (iter->next != head) {
        iter = iter->next;
        rtn++;
    }
    return rtn;
}


// destroy the list of players
void destroy_players(player* head) {
    if (!head) {
        return ;
    }
    player* iter = head;
    // if (iter->next == head) {
    //     free(iter);
    //     return;
    // }
    iter = head->next;
    while(iter!= head) {
        player* old = iter;
        iter = iter->next;
        free(old);
    }
    free(head);
}

// get the first player
player* get_first_player(player* head) {
    return head;
}

// get the last player
player* get_last_player(player* head) {
    player* iter = head;
    while(iter->next != head) {
        iter = iter->next;
    }
    return iter;
}