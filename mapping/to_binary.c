#include "../push.h"

/**
 * @brief it runs along thestack, ordering to tranform every number into binary
 * NOTICE it converto the mapped index, xmap
 * 
 * @param head 
 */
void     to_binary(t_list *head)
{
    while (head)
    {
        head->xbin = convert_binary(head->x);
        if (head->next)
            head = head->next;
        else
            break;
    }
}

/**
 * @brief it convertes every decimal number into binery, moving bits
 * 
 * @param  
 * @return int 
 */
int convert_binary(int ch)
{
    long long int bin = 0;
    int b = 0;
    long long int  sigdig = 1;
    while (b < 16)
    {
        bin = bin + (sigdig * (ch & 1));
        sigdig *= 10;
        ch >>= 1;
        b++;
    }
    return bin;
}
