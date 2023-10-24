#include "push.h"

// when having only two members, it should also be changed the head *
t_list *sa(t_list *tail)
{
    t_list *tmp;
    tmp = tail->prev;
    //If there are at least two previos elementes, if not
    //the second conditioin will check if at least there is two elemnts
    //it would do nothing in third case
    if (tail->prev->prev)
    {
        tail->prev->prev->next = tail;
        tail->prev = tail->prev->prev;
        tail->next = tmp;
        tmp->prev = tail;
        tmp->next = NULL;
    
    }
    else if(tail->prev)
    {
        tail->prev = NULL;
        tmp->prev = tail;
        tail->next = tmp;
        tmp->next = NULL;
    }
    else
        return tail;
    return tmp;
}

t_list *sb(t_list *tail)
{
    t_list *tmp;
    tmp = tail->prev;
    if (tail->prev->prev)
    {

        tail->prev->prev->next = tail;
        tail->prev = tail->prev->prev;
        tail->next = tmp;
        tmp->prev = tail;
        tmp->next = NULL;
    }
    else if(tail->prev)
    {
        tail->prev = NULL;
        tmp->prev = tail;
        tail->next = tmp;
        tmp->next = NULL;
    }
    else
        return tail;
    return tmp;
}