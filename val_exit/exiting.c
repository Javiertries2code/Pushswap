#include "../push.h"

int	count_split(char **argv)
{
	int	count;

	count = 0;
	while (argv[count] != NULL)
		count++;
	return (count);
}

void	exiting(char *str, char **splitted, t_list **ends)
{
	//print_stack(ends);
	if (str && str[0] == 'Y' && (int)str[1] == 'W')
	{
		free_list(ends);
		exit(1);
	}
	else
		write(2, "Error\n", 6);
	if (splitted)
		free_pointer(splitted);
	if (ends)
	{
		free_list(ends);
	}
	exit(1);
}

int	free_pointer(char **numbers)
{
	int	i;

	i = count_split(numbers);
	while (--i >= 0)
	{
		free(numbers[i]);
		numbers[i] = NULL;
	}
	return (i);
}

void	free_list(t_list **ends)
{
	t_list	*tmp;

	free(ends[1]->data_a);
	free(ends[1]->data_b);
	while (ends[1])
	{
		tmp = ends[1]->prev;
		free(ends[1]);
		ends[1] = tmp;
	}
	while (ends[3])
	{
		tmp = ends[3]->prev;
		free(ends[3]);
		ends[3] = tmp;
	}
}

void	free_datarr(t_data *datarr[])
{
	free(datarr[0]);
	free(datarr[1]);
	exit(1);
}

