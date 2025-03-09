#include "../push.h"

void	basic_valid(int argc, char *argv[], t_data *datarr[])
{
	if (argc == 1)
		free_datarr(datarr);
	if (argv[1][0] == '\0')
	{
		free_datarr(datarr);
		exiting(NULL, NULL, NULL);
	}
	if (argc < 2 || (argc == 2 && counter(argv[1], ' ') == 1))
	{
		free_datarr(datarr);
		exiting(NULL, NULL, NULL);
	}
}

void	set_element(t_list *tail, t_list *head)
{
	if (tail->x > head->x)
		tail->smaller--;
	if (tail->x < head->x)
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

void	val_split(char *argv, t_list **ends, t_data **datarr)
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
				new_element(ends, tmp[i], datarr);
			i++;
		}
		free_pointer(tmp);
	}
	else
	{
		if (valid(argv, NULL, ends) == SUCCESS)
			new_element(ends, argv, datarr);
		else
			exiting("Error", NULL, ends);
	}
}

void	find_duplicate(t_list **ends, t_list *head, t_list *tail)
{
	head = ends[0];
	tail = ends[1];
	while (head)
	{
		while (tail)
		{
			if (tail->x == head->x && head != tail)
				exiting("Error", NULL, ends);
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
