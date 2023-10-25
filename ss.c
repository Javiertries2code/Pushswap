#include "push.h"
// if it doesnt fit by lines, i can be sent as a parameter. less pretty though.
void ss(t_list **ends)
{
    t_list *tmp;
    int i;

    i = 1;
    while (i != 5)
    {
        tmp = ends[i]->prev;
        if (ends[i]->prev->prev)
    {
         ends[i]->prev->prev->next =  ends[i];
         ends[i]->prev =  ends[i]->prev->prev;
         ends[i]->next = tmp;
        tmp->prev =  ends[i];
        tmp->next = NULL;
    }
    else if( ends[i]->prev)
    {
         ends[i]->prev = NULL;
          ends[i]->prev->next =  ends[i];
        tmp->prev =  ends[i];
         ends[i]->next = tmp;
        tmp->next = NULL;
    }
        i = i + 2;
    }
}