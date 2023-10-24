#include "push.h"

void free_backwards( t_list *tail)
{
t_list *tmp;
while (tail)
{
   // printf("freeing index %d", tail->index);
    tmp = tail->prev;
    free(tail);
    tail = tmp;
}
}

void free_ahead( t_list *head)
{
t_list *tmp;
while (head)
{
  //  printf("freeing index %d", head->index);
    tmp = head->next;
    free(head);
    head = tmp;
}

}

t_list *new_element(t_list *current, int x, int index)
    {
    t_list *new;
   // printf("addres current %p\n", current);

    new = malloc(sizeof(t_list));
    if(new == NULL)
        exit(1);
    current->next = new;
    new->prev = current;
    new->x = x;
    new->index = index;
    new->next = NULL;
  //  printf("tindex %d, address new\t%p\n", index, new);
    return new;
}

void print(t_list *head)
{

    while (head)
    {
        printf("forward\nvalue\t%d\tindex\t%d\n ", head->x, head->index);
        if (head->next)
            head = head->next;
        else
            break;
    }
}

void rprint(t_list *tail)
{

    while (tail)
    {
        printf("Backwards\nvalue\t%d\tindex\t%d\n ", tail->x, tail->index);
        if (tail->prev)
            tail = tail->prev;
        else
            break;
    }
}