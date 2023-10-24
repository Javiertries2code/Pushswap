#include "push.h"

//    t_list *ends[4] = {head_a, tail_a, head_b, tail_b};

void pb(t_list **ends)
{
    t_list *tmp;
    // t_list *tmp_b;

   // printf("addres ends enter\t%p\t%p\t%p\t%p\n", ends[0], ends[1], ends[3], ends[3]);

    // pending t protect for no members
    if (ends[0] == NULL || ends[1] == NULL)
        return;
    tmp = ends[1];

    // if there is more than one lemente, remove head, else
    // null->prev next
    // Else, there was only one elemnt, we null it
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
    // now headb pints to its new head,
    // the new had to next element
    tmp->prev = NULL;
    if (ends[2])
        ends[2]->prev = tmp;
    tmp->next = ends[2];
    ends[2] = tmp;
    if(!ends[3])
        ends[3] = ends[2];


    /*
    ends[3] = tail_a;
    tail_a = tail_a->prev;
    tail_a->next = NULL;
    //here new tail, moved to the previous one, and point to NULL.
    //we only keep access through temp, otherwise memory leak
    tmp-> next = head_b;
    tmp->prev = NULL;
    //gotta point  before losing address
    //
    //head_b = tmp; ccambio por ends[2] = tmp;
    ends[2] = tmp;
    */

    // hence tail-b
   // printf("addres ends leaving\t%p\t%p\t%p\t%p\n", ends[0], ends[1], ends[3], ends[3]);
}