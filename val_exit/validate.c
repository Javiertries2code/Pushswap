#include "../push.h"

void set_element(t_list *tail, t_list *head)
{
	if(tail->x > head->x)
		tail->smaller++;
	if(tail->x < head->x)
		tail->bigger++;
}


int	valid(const char *s, char **splitted, t_list **ends)
{
	int	i;

	if (!s)
		exiting("Error", splitted, ends);
	i = 0;
	while (*s == ' ' || *s == '\t')
		s++;
	while (s[i])
	{
		if (((s[i] >= '0' && s[i] <= '9') || (s[i] == '-' && i == 0)))
			i++;
		else if (s[i] == ' ' || s[i] == '\t')
			return (SPLIT);
		else
			exiting("Error", splitted, ends);
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
				exiting("Error", tmp, ends);
			i++;
		}
		free_pointer(tmp);
	}
	else
	{
		if (valid(argv, NULL, ends) == SUCCESS)
			new_element(ends, argv);
		else
			exiting("Error", NULL, ends);
	}
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
			set_element(tail, head);
			if (tail->x == head->x && head != tail)
				exiting("Error\n", NULL, ends);
			if (tail->prev)
				tail = tail->prev;
			else
			{
				tail = ends[1];
				break ;
			}
		}
		if (head->next)
			head = head->next;
		else
			break ;
	}
}

