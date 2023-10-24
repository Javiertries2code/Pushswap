#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    int x;
    int index;
    struct s_list *next;
    struct s_list *prev;
} t_list;


void print(t_list *head);
void rprint(t_list *tail);
t_list *new_element(t_list *current, int x, int index);
void free_ahead(t_list *tail);
void free_forward(t_list *head);
t_list *sa(t_list *tail);
t_list *sb(t_list *head);

void tsb(t_list **arr);
void tsa(t_list **arr);
void pb(t_list **ends);
void pa(t_list **ends);



#endif