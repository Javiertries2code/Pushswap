#include "../push.h"

void map_list(t_list **ends, t_list *head)
{

    int num_elements = ends[0]->index;
    head->data_A->map_index = 1;
    find_max(head);
    find_min_abs(head);
   

    while (num_elements > 0)
    {
      printf("\nnumelements = %d", num_elements);
          printf("\nmax = %d", head->data_A->stack_max);
     printf("\nmin-rel = %d", head->data_A->stack_min);

        assign_index(ends);
        find_min_rel(ends[0]);
        num_elements--;
    }
   to_binary(head);
}
void find_max(t_list *head)
{
    int max;
    max = head->x;

    while (head)
    {
        if (max < head->x)
            max = head->x;
        if (head->next)
            head = head->next;
        else
            break;
    }

    head->data_A->stack_max = max;
    //printf("\nmax = %d", head->data_A->stack_max);
  
}
void find_min_rel(t_list *head)
{
    int min;
  
    min = head->data_A->stack_max;

    while (head)
    {
       
        if (min > head->x && head->xmap == 0)
            min = head->x;
        if (head->next)
            head = head->next;
        else
            break;
    }
    head->data_A->stack_min = min;
   // head->data_A->map_index++;
   //index++ done in assigned
     //printf("\nmin-rel = %d", head->data_A->stack_min);
        

}

void find_min_abs(t_list *head)
{

    int min;
    min = head->x;

    while (head)
    {
        if (min > head->x)
            min = head->x;
        if (head->next)
            head = head->next;
        else
            break;
    }

    head->data_A->stack_min = min;
    head->data_A->map_index = 1;
    printf("\nmin = %d", head->data_A->stack_min);

}

// asssigs and map index value to the element == to minrel
void assign_index(t_list **ends)
{
    //write(1, "assign_index", 13);
    t_list *head;

    head = ends[0];
    while (head)
    {
        if (head->x == head->data_A->stack_min)
            head->xmap = head->data_A->map_index++;
        if (head->next)
            head = head->next;
        else
            break;
    }
}