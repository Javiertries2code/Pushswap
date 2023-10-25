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


void tsb(t_list **arr);
void tsa(t_list **arr);

void pb(t_list **ends);
void pa(t_list **ends);
void ra(t_list **ends);
void rb(t_list **ends);
void rra(t_list **ends);
void rrb(t_list **ends);
void rrr(t_list **ends);
void sa(t_list **ends);
void sb(t_list **ends);
void ss(t_list **ends);







#endif