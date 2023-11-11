#include "../push.h"

int	valid(const char *s, char **splitted, t_list **ends)
{
	int	i;

	if (!s)
		exiting("No string", splitted, ends);
	i = 0;                          // i can allways play the i = -1; ++i
	while (*s == ' ' || *s == '\t') // it might eliminate a first -number
		s++;
	while (s[i]) // i gonna try with a previous
	{
		if ((s[i] >= '0' && s[i] <= '9') || (s[i] == '-' && i == 0))
			i++;
		else if (s[i] == ' ' || s[i] == '\t')
			return (SPLIT);
		else
			exiting("Non valid characters in str", splitted, ends);
	}
	return (SUCCESS);
}

void	val_split(char *argv, t_list **ends)
{
	int		i;
	char	**tmp;
	int		j;

	if (valid(argv, NULL, ends) == SPLIT)
	{
		i = 0;
		tmp = ft_split(argv, ' ');
		j = count_split(tmp);
		while (i < j)
		{
			if (valid(tmp[i], tmp, ends) == SUCCESS)
				new_element(ends, tmp[i]);
			else // no need, its gonna exit in the function
				exiting("Non valid, after splitting", tmp, ends);
			i++;
		}
		free_pointer(tmp);
	}
	else
	{
		if (valid(argv, NULL, ends) == SUCCESS)
			new_element(ends, argv);
		else
			exiting("Non valid argv", NULL, ends);
	}
	find_duplicate(ends);
}

void	find_duplicate(t_list **ends)
{
	t_list *head;
	t_list *tail;

	head = ends[0];
	tail = ends[1];
	while (head)
	{
		while (tail)
		{
			if (tail->x == head->x)
				exiting("duplicate number", NULL, ends);
			if (tail->prev)
				tail = tail->prev;
			else
				break ;
		}
		if (head->next)
		{
			head = head->next;
		}
		else
			break ;
	}
}