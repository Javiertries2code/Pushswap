#include "../push.h"


/**
 * @brief
 *  i  check if the list is already ordered.
 * if not it reassings the pointer to the last element to the current last element.
 * @see in_order
 *  it goes moving the elements of the list to the stackB (pb) 
 * or to the botton of the stackA (ra)
 * it does  this for 16 bits, as for integer size.
 *after  all the 16 bits are evaluated, ir returns all the elements  from Stack B to Stack A
 @see back_to_a
 * 
 * @param ends array pointers to the  first and last element of the stack
 * @param bits it gets a 0, to shorten lines avoiding declaration and initializacion
 */
void radix(t_list **ends, int bits){
t_list *tail;
int decimal = 10;
int counter ;
//here it gotta be 16 for int size
while (bits < 16)
{ //comprueba que no este ya ordenada, por probrar aun
   
    if (in_order(ends) == 0)
        tail = ends[1];
    //toberemoved 
   
    counter = ends[0]->data_A->stack_size;
 
    while(tail && counter-- > 0)
    {
       // print_radix( ends, tail, decimal);
        if(((tail->xmap >> bits)& 1) == 0)
            ra(ends, print_fun("ra"));
        else
            pb(ends, print_fun("pb"));
        
        if (ends[1] != NULL)
            tail = ends[1];
        else
            break;
    }
  	//print_stack(ends);

    back_to_a(ends);
    //	print_stack(ends);

    decimal *= 10;
bits++;
}

}


int in_order(t_list **ends)
{
     t_list *head;

     head = ends[0];
while(head)
{
    if (head->prev && head->x < head->prev->x)
        return 0;
    if (head->next)
        head = head->next;
    else
        {
        // print_stack(ends);
        //   printf("\nSUCCESS\n");
            exiting("YW", NULL, ends);
            break;
        }
//it is possible i gotta make a break ans a signal to exit
}
 return 1;
}

/**
 * @brief returns all the elements from stack A to stack B (pa)
 * 
 * @param ends 
 */
void back_to_a(t_list **ends)
{
    while(ends[3])
        pa(ends, print_fun("pa"));
}