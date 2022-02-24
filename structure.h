#ifndef STRUCTURE_H
#define STRUCTURE_H


struct player
{
    int num;
    struct player* next;
};

struct stone
{
    struct play* owner;
};

struct stone_heap
{
    struct stone* heap;
    int heap_size;
    int current_index;
};

struct player_list
{
    int player_num;
    struct player* first;
};


typedef struct player player;
typedef struct stone stone;
typedef struct player_list player_list;
typedef struct stone_heap stone_heap;

#endif // STRUCTURE_H
