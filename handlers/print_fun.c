#include "../push.h"

void	*print_fun(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	return ((void *)str);
}

