#include "push.h"

//    t_list *ends[2] = {head_a, tail_a, head_b, tail_b};//

// gotta change 3 2  1 0 

void pa(t_list **ends)
{
    t_list *tmp;
   
    if (ends[2] == NULL || ends[3] == NULL)
        return;
    tmp = ends[3];

    if (ends[3]->prev)
    {
        ends[3]->prev->next = NULL;
        ends[3] = ends[3]->prev;
    }
    else
    {
        ends[2] = NULL;
        ends[3] = NULL;
    }
    tmp->prev = NULL;
    if (ends[0])
        ends[0]->prev = tmp;
    tmp->next = ends[0];
    ends[0] = tmp;
    if(!ends[1])
        ends[1] = ends[0];
}