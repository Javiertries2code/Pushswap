#include "../push.h"
/**
 * @brief it counts the number of elements in with the string with splitted on
 * 
 * @param argv 
 * @return int 
 */
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
 * @brie it prints and error in stderror if required
 * it frees all the content and exits

 */
void	exiting(char *str, char **splitted, t_list **ends)
{	
	if(str && str[0] == 'Y' && (int)str[1] == 'W')
		{
			free_list(ends);
			exit(1);
		}
	else
		write(2, "Error\n", 6);
	if (splitted)
		free_pointer(splitted);
	if (ends)
		free_list(ends);
	exit(1);
}

/**
 freeing the set of numbers

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

	free(ends[1]->data_A);
	free(ends[1]->data_B);
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

void free_datarr(t_data *datarr[])
{
	free(datarr[0]);
	free(datarr[1]);
	exit(1);
}