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

void	exiting(char *str, char **splitted, t_list **ends)
{
	if (str)
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
	/*while (ends[0])
{
	tmp = ends[0]->next;
	free(ends[0]);
	ends[0] = tmp;
}
	while (ends[2])
{
	tmp = ends[2]->next;
	free(ends[2]);
	ends[2] = tmp;
}*/
	// REDUNDANT< JUST IN CASE
}
/*void	free_backwards(t_list *tail)
{
	t_list	*tmp;

	while (tail)
	{
		tmp = tail->prev;
		free(tail);
		tail = tmp;
	}
}

void	free_ahead(t_list *head)
{
	t_list	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}*/