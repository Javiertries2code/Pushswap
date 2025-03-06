#include "../push.h"

void	sorting_four(t_list **ends)
{
	int		i;
	t_list	*head;

	head = ends[1];
	while (head)
	{
		i = highest_second(ends[0], head->x);
		head = head->prev;
		if (i == 0)
		{
			pb(ends, print_fun("pb"));
			break ;
		}
		else
			ra(ends, print_fun("ra"));
	}
	sorting_three(ends);
	pa(ends, print_fun("pa"));
}

void	sorting_five(t_list **ends)
{
	int		i;
	int		j;
	t_list	*head;

	head = ends[1];
	j = 2;
	while (head && j != 0)
	{
		i = highest_second(ends[0], head->x);
		head = head->prev;
		if (i == 0)
		{
			pb(ends, print_fun("pb"));
			j--;
		}
		else
			ra(ends, print_fun("ra"));
	}
	sorting_three(ends);
	if (ends[3]->x < ends[3]->prev->x)
		sb(ends, print_fun("sb"));
	pa(ends, print_fun("pa"));
	pa(ends, print_fun("pa"));
}

void	sorting_four_five(t_list **ends)
{
	if ((ends[1]->index) == 4)
	{
		sorting_four(ends);
		print_stack(ends);
	}
	else if (ends[1]->index == 5)
	{
		sorting_five(ends);
		print_stack(ends);
	}
	exiting("YW", NULL, ends);
}

int	highest_second(t_list *head, int value)
{
	int i;

	i = 0;
	while (head)
	{
		if (head->x < value)
			i++;
		head = head->next;
	}
	return (i);
}