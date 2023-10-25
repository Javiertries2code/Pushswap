#include "push.h"

void ra(t_list **ends)
{
    t_list *tmp;
   
    if (ends[0] == NULL || ends[1] == NULL)
        return;
    tmp = ends[1]->prev;
    ends[0]->prev = ends[1];
    ends[1]->prev->next = NULL;
    ends[1]->prev = NULL;
    ends[1]->next = ends[0];
    ends[0] = ends[1];
    ends[1] = tmp;
}
//as for now this one runs,
// though, i used one line less in rra
//still pending to test