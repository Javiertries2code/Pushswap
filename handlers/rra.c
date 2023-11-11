#include "../push.h"

void rra(t_list **ends, void *print_fun)
{
    t_list *tmp;
   
    if (!ends[0] || !ends[0]->next || !print_fun)
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