#include "../push.h"

int	count_split(char **argv)
{
	int	count;

	count = 0;
	while (argv[count] != NULL)
		count++;
	return (count);
}

// i could pass the count as an argument instead,
// FUCK EFFICIENCY

// to fit thing i gotta return smthg,i can t return pointer to local variable,
// as it will be done and gone.


/**
 * @brief 
 * @file exiting.c
 * @param str 
 * @param splitted 
 * @param ends 
 */
void	exiting(char *str, char **splitted, t_list **ends)
{	//in case of crashing is causo
	if(str && str[0] == 'Y' && (int)str[1] == 'W')
		{free_list(ends);
		exit(1);}
	else if (str)
	{
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
	}
	else
		write(1, "Error\n", 7);
	if (splitted)
		free_pointer(splitted);
	if (ends)
		free_list(ends);
	exit(1);
}

/**
 * @brief freeing the set of numbers
 * 
 * @param numbers 
 * @return int 
 */
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