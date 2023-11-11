#include "../push.h"

int	valid(const char *s, char **splitted, t_list **ends)
{
	int	i;

	if (!s)
		exiting("No string", tmp, ends);
	i = 0; // i can allways play the i = -1; ++i
	while(*s == ' ' || *s == '\t' || *s == '-')
		s++;
	while (s[i])
	{
		if ((s[i] > 0 && s[i] < 9))
			i++;
		else if (s[i] == ' ' || s[i] == '\t')
			return (SPLIT);
		else
			exiting("Non valid characters in str", tmp, ends); 
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
			if ((valid(tmp[i]), tmp, ends) == SUCCESS)
				new_element(ends, tmp[i]);
			else // no need, its gonna exit in the function
				exiting("Non valid, after splitting", tmp, ends);
			i++;
		}
		free_pointer((void **)tmp);
	}
	else
	{
		if (valid(argv, NULL, ends) == SUCCESS)
			new_element(ends, argv);
		else 
			exiting("Non valid argv", tmp, ends);
	}
}

int	find_duplicate(long long int num, char **numbers)
{
	int	i;

	i = 1;
	while (numbers[i])
		if (ft_atoi(numbers[i++]) == num)
			return (1);
	return (0);
}
