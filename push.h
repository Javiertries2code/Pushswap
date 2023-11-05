#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_list
{
    int x;
    int index;
    struct s_list *next;
    struct s_list *prev;
} t_list;

enum Calls{
    ERROR,
};

typedef Calls Calls;

void print(t_list *head);
void rprint(t_list *tail);
t_list *new_element(t_list *current, int x, int index);
void free_ahead(t_list *tail);
void free_forward(t_list *head);


void testprint(t_list **ends);
void print_stack(t_list **ends);

//to  print the letters everytime i call a funcion, i send a function printing and
//returning a null, so i just need to handle it in the null check

void pb(t_list **ends, void *print);
void pa(t_list **ends, void *print);
void ra(t_list **ends, void *print);
void rb(t_list **ends, void *print);
void rra(t_list **ends, void *print);
void rrb(t_list **ends, void *print);
void rrr(t_list **ends, void *print);
void sa(t_list **ends, void *print);
void sb(t_list **ends, void *print);
//void ss(t_list **ends);
void	ss(t_list **ends, t_list *tmp, int i, void *print);
void rr(t_list **ends, void *print);
void *print_fun(char *str, int num);
long long int	ft_atoi(const char *str)
val_input(int argc, char *argv[]);
find_duplicate(long long int num, char **numbers);






#endif