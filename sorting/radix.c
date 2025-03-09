#include "../push.h"

void	radix(t_list **ends, int bits)
{
	t_list	*tail;
	int		decimal;
	int		counter;

	decimal = 10;
	while (bits < 16)
	{
		if (in_order(ends) == 0)
			tail = ends[1];
		counter = ends[0]->data_a->stack_size;
		while (tail && counter-- > 0)
		{
			if (((tail->xmap >> bits) & 1) == 1)
				ra(ends, print_fun("ra"));
			else
				pb(ends, print_fun("pb"));
			if (ends[1] != NULL)
				tail = ends[1];
			else
				break ;
		}
		back_to_a(ends);
		decimal *= 10;
		bits++;
	}
}

int	already_ordered(t_list **ends)
{
	t_list	*head;

	head = ends[0];
	while (head)
	{
		if (head->next)
		{
			if (head->x < head->next->x)
				head = head->next;
			else
				return (1);
		}
		else
		{
			exiting("YW", NULL, ends);
		}
	}
	return (1);
}

int	in_order(t_list **ends)
{
	t_list	*head;

	head = ends[0];
	while (head)
	{
		if (head->prev && head->x > head->prev->x)
			return (0);
		if (head->next)
			head = head->next;
		else
		{
			exiting("YW", NULL, ends);
			break ;
		}
	}
	return (1);
}

void	back_to_a(t_list **ends)
{
	while (ends[3])
		pa(ends, print_fun("pa"));
}