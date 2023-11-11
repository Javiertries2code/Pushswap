#include "../push.h"
#include <ctype.h>
/*#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

argv[1] is got as beginint of the set
ends,
	as to set heads and tail (new elemnt should work just giving it a NULL values)
We check existance of spaces (posible to  use break ; in the strchr to shorten process)
if so we split it up
We loop the tmp, and make validation (characters, float etc, we could extend
strchr with signal for such a thing)


*/

void	exiting(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}
// I gotta place FT_is digit is alpha
int	valid(const char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (!isdigit(*s) || !isalpha(*s) || s[0] == '.' || s[0] == ',')
			return (1);
		s++;
	}
	return (0);
}

void	val_split(char *argv, t_list **ends)
{
	int		i;
	char	**tmp;
	int		j;

	if (ft_strchr(argv, ' '))
	{
		i = 0;
		tmp = ft_split(argv, ' ');
		if (!tmp)
			exiting("exiting");
		j = sizeof(tmp) / sizeof(char **);
		printf("%d", j);
		while (i < j)
		{
			if (valid(tmp[i]))
				new_element(ends, tmp[i]);
			else
				exiting("Non valid argumen in split looop");
			i++;
		}
		free(tmp);
	}
	else
	{
		if (valid(argv))
			new_element(ends, argv);
		else
			exiting("Non valid argument");
	}
}
// hope i am creating a new elemnt, or starting the list if NULLED,
//	 I might have to calloc in main, instead of
// declaring size-t ends[4]
/*void	new_element(t_list **ends, char *x)
{
	t_list *new;

	new = calloc(1, sizeof(t_list));
	if (new == NULL)
		exiting("failed to malloc for new element");
			// Gotta do an exit function i see
	if (!ends[0] || !ends[1])
	{
		ends[0] = calloc(1, sizeof(t_list));
		ends[1] = calloc(1, sizeof(t_list));
		
	}

	new->prev = ends[1];
	new->next = NULL;
	new->index = ends[1]->index + 1;
	new->x = ft_atoi(x);
	ends[1] = new;
}*/