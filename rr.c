#include "push.h"

void rr(t_list **ends)
{
    t_list *tmp;
   
    if (!ends[1] || !ends[3] || !ends[3]->prev || !ends[1]->prev)
        return;

    tmp = ends[3]->prev;
    ends[2]->prev = ends[3];
    ends[3]->prev->next = NULL;
    ends[3]->prev = NULL;
    ends[3]->next = ends[2];
    ends[2] = ends[3];
    ends[3] = tmp;
//-----------------------------------------
    tmp = ends[1]->prev;
    ends[0]->prev = ends[1];
    ends[1]->prev->next = NULL;
    ends[1]->prev = NULL;
    ends[1]->next = ends[0];
    ends[0] = ends[1];
    ends[1] = tmp;
}