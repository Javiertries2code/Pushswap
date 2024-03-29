#include "../push.h"
//place enough, can make it prettie declaring bits 0;
// void radix(t_list **ends, int bits){
// t_list *tail;
// int decimal = 10;
// int counter ;
// //here it gotta be 16 for int size
// while (bits < 8)
// { //comprueba que no este ya ordenada, por probrar aun
//     print_stack(ends);
//     if (in_order(ends) == 0)
//         tail = ends[1];
//     //toberemoved 
   
//     counter = ends[0]->data_A->stack_size;
//     while(tail && counter-- > 0)
//     {
//        // print_radix( ends, tail, decimal);
//         if(((tail->xbin % decimal) == 0))
//             pb(ends, print_fun("pb"));
//         else
//             ra(ends, print_fun("ra"));
        
//         if (ends[1] != NULL)
//             tail = ends[1];
//         else
//             break;
//     }
//     print_stack(ends);
// write(1,"\nxxxxxxxxxxxx\nxxxxxxxxxxxxxxxxxxxxxx\nxxxxxxxxxxx", 49);
//     back_to_a(ends);
//     decimal *= 10;
// bits++;
// }
// }
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
  
    back_to_a(ends);
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

          
            print_stack(ends);
            printf("SUCCESS");
            exiting("YW", NULL, ends);
            break;
        }
//it is possible i gotta make a break ans a signal to exit
}
 return 1;
}


void back_to_a(t_list **ends)
{
    while(ends[3])
        pa(ends, print_fun("pa"));
}