#include "../push.h"

void rrb(t_list **ends, void *print)
{
    t_list *tmp;
   
    if (!ends[2] || !ends[2]->next || !print)
        return;
    tmp = ends[2]->next;
    ends[3]->next = ends[2];
    tmp->prev = NULL;
    ends[2]->next = NULL;
    ends[2]->prev = ends[3];
    ends[3] = ends[2];
    ends[2] = tmp;



}
// looking good, though in ra i used onemore line