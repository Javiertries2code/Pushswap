#include "push.h"

void ss(t_list **ends)
{
    t_list *tmp;
    t_list *tmp_b;
    t_list *tail_a = ends[1];
    t_list *tail_b = ends[3];
    //    t_list *ends[4] = {head_a, tail_a, head_b, tail_b};
    tmp = tail_a->prev;
    if (tail_a->prev->prev)
    {

        tail_a->prev->prev->next = tail_a;
        tail_a->prev = tail_a->prev->prev;
        tail_a->next = tmp;
        tmp->prev = tail_a;
        tmp->next = NULL;
    }
    else if (tail_a->prev)
    {
        tail_a->prev = NULL;
        tmp->prev = tail_a;
        tail_a->next = tmp;
        tmp->next = NULL;
    }
    // I eliminated the returns as the changes are either done or not.
    tmp_b = tail_b->prev;
    if (tail_b->prev->prev)
    {

        tail_b->prev->prev->next = tail_b;
        tail_b->prev = tail_b->prev->prev;
        tail_b->next = tmp_b;
        tmp_b->prev = tail_b;
        tmp_b->next = NULL;
    }
    else if (tail_b->prev)
    {
        tail_b->prev = NULL;
        tmp_b->prev = tail_b;
        tail_b->next = tmp_b;
        tmp_b->next = NULL;
    }
}
