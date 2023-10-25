#include "push.h"

void rrr(t_list **ends)
{
    t_list *tmp;
   
    if (ends[0] == NULL || ends[1] == NULL || ends[2] == NULL || ends[3] == NULL )
        return;
    tmp = ends[0]->next;
    ends[1]->next = ends[0];
    tmp->prev = NULL;
    ends[0]->next = NULL;
    ends[0]->prev = ends[1];
    ends[1] = ends[0];
    ends[0] = tmp;
//-------
    tmp = ends[2]->next;
    ends[3]->next = ends[2];
    tmp->prev = NULL;
    ends[2]->next = NULL;
    ends[2]->prev = ends[3];
    ends[3] = ends[2];
    ends[2] = tmp;
}
