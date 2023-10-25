#include "push.h"

void rra(t_list **ends)
{
    t_list *tmp;
   
    if (ends[0] == NULL || ends[1] == NULL)
        return;
    tmp = ends[0]->next;
    ends[1]->next = ends[0];
    tmp->prev = NULL;
    ends[0]->next = NULL;
    ends[0]->prev = ends[1];
    ends[1] = ends[0];
    ends[0] = tmp;

}
// looking good, though in ra i used onemore line