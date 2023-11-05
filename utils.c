#include "push.h"

void *print_fun(char *str, int num)
{
    write(1, str, num);
    write(1, "\n", 1);
    return (NULL);
}