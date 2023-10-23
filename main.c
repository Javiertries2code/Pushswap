
#include "push.h"


int main(int argc, char *argv[])
{
    int i;
    t_list *current_a;
    t_list *head_a;
    t_list *tail_a;

    //It would be interesting to condensate 
    //the crating current and head a n b in a funciton
    //t_list *head_b;
    //t_list *tail_b;
    //by declaring the array, there wouldnt be a need of declaring 
    //the others, but it adds clarity;
    //aint sure if it should be ** or *[] or Fucking what
    //t_list *ends[4] = {head_a, tail_a, head_b, tail_b};
    //i dont really need to have initialized the headB and tailb
    //as t it owuld be done, when adding. pop/push function might be handy
    current_a = malloc(sizeof(t_list));
    if(current_a == NULL)
        exit(1);
    current_a->x = atoi(argv[1]);
    //this index goes as a counting check, not necessary
    current_a->index = 1;
    current_a->prev = NULL;
    current_a->next = NULL;
    head_a = current_a;

    i = 2; // as agrv[1] ya esta
    while (i < argc)
    {
        current_a = new_element(current_a, atoi(argv[i]), i);
        i++;
       // printf("addres current_a main %p\n", current_a);

        usleep(500);
    }
    tail_a = current_a;
printf("beforesa\n");
    print(head_a);
    tail_a = sa(tail_a);
   printf("after\n");

    print(head_a);

     rprint(tail_a);

    free_ahead(head_a);

    return (0);
}