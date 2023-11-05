#include "../push.h"

void rb(t_list **ends, void *print)
{
    t_list *tmp;
   
    if (!ends[3] || !ends[3]->prev || !print)
        return;
    tmp = ends[3]->prev;
    ends[2]->prev = ends[3];
    ends[3]->prev->next = NULL;
    ends[3]->prev = NULL;
    ends[3]->next = ends[2];
    ends[2] = ends[3];
    ends[3] = tmp;
}