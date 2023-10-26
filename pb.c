#include "push.h"

//    t_list *ends[4] = {head_a, tail_a, head_b, tail_b};

void pb(t_list **ends)
{
    t_list *tmp;

    if (ends[0] == NULL || ends[1] == NULL)
        return;
    tmp = ends[1];

    if (ends[1]->prev)
    {
        ends[1]->prev->next = NULL;
        ends[1] = ends[1]->prev;
    }
    else
    {
        ends[0] = NULL;
        ends[1] = NULL;
    }

    tmp->prev = NULL;
    if (ends[2])
        ends[2]->prev = tmp;
    tmp->next = ends[2];
    ends[2] = tmp;
    if (!ends[3])
        ends[3] = ends[2];
}