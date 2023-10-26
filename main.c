
#include "push.h"

int main(int argc, char *argv[])
{
    int i;
    t_list *current_a;
    // t_list *head_a = NULL;
    // t_list *tail_a = NULL;
    // t_list *head_b = NULL;
    // t_list *tail_b = NULL;
    t_list *ends[4];

    // It would be interesting to condensate
    // the crating current and head a n b in a funciton

    // by declaring the array, there wouldnt be a need of declaring
    // the others, but it adds clarity;
    current_a = malloc(sizeof(t_list));
    if (current_a == NULL)
        exit(1);
    current_a->x = atoi(argv[1]);
    // this index goes as a counting check, not necessary
    current_a->index = 1;
    current_a->prev = NULL;
    current_a->next = NULL;
    // replacin
    // head_a = current_a;
    ends[0] = current_a;
    i = 2; // as agrv[1] ya esta
    while (i < argc)
    {
        current_a = new_element(current_a, atoi(argv[i]), i);
        i++;
    }
    // replacing
    //   tail_a = current_a;
    ends[1] = current_a;
    // ends[0] = head_a;
    // ends[1] = tail_a;
    ends[2] = NULL;
    ends[3] = NULL;
    // ends[2] = head_b;
    // ends[3] = tail_b;

    //pb(ends);
   // sa(ends);
    pb(ends);
    pb(ends);
    pb(ends);

    //  sb(ends);
    // sb(ends);
    // sb(ends);
    printf("\nBefore SS\n");

    print(ends[0]);
    printf("\n");
    print(ends[2]);
    pa(ends);
    pa(ends);
    sa(ends);
     sb(ends);
 printf("\naftersa te elemnts\n");

    print(ends[0]);
    printf("\n");
    print(ends[2]);

//sa(ends);
  // sa(ends);
  // sa(ends);
    /*pa(ends);
    pa(ends);
    pa(ends);
     pa(ends);
    pa(ends);
    pa(ends);*/
   // pa(ends);

    // sa(ends);
    printf("\nAfter S\n");

    print(ends[0]);
    printf("\n");
    print(ends[2]);
//sa(ends);
  
    free_ahead(ends[0]);
    // no need to free B, as all should be ordered in A
    // free_ahead(ends[2]);
    return (0);
}