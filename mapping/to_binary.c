#include "../push.h"

void to_binary(t_list *head)
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
