#include "../push.h"


void	print(t_list *head)
{
	while (head)
	{
		printf("FORWARD\nvalue\t%d\tindex\t%d\n ", head->x, head->index);
		printf("Address - %p\tPREV - %p\t NEXT - %p \n", head, head->prev,
			head->next);
		if (head->next)
			head = head->next;
		else
			break ;
	}
}

void	rprint(t_list *tail)
{
	while (tail)
	{
		printf("BACKWARDS\nvalue\t%d\tindex\t%d\n ", tail->x, tail->index);
		printf("Address - %p\tNEXT - %p\t PREV - %p \n", tail, tail->next,
			tail->prev);
		if (tail->prev)
			tail = tail->prev;
		else
			break ;
	}
}


void	print_stack(t_list **ends)
{
	t_list	*tail_a;
	t_list	*tail_b;

	if (!ends[1] && !ends[3])
		return ;
	tail_a = ends[1];
	tail_b = ends[3];
	while (tail_a || tail_b)
	{
		if (tail_a && tail_b)
			printf("\n\t%d\t%d\n ", tail_a->x, tail_b->x);
		else if (tail_a && !tail_b)
			printf("\n\t%d\t-\n ", tail_a->x);
		else if (!tail_a && tail_b)
			printf("\n\t-\t%d\n ", tail_b->x);
		else
			return ;
		if (tail_a)
		{
			if (tail_a->prev)
				tail_a = tail_a->prev;
			else
				tail_a = NULL;
		}
		if (tail_b)
		{
			if (tail_b->prev)
				tail_b = tail_b->prev;
			else
				tail_b = NULL;
		}
	}
	printf("\t---------\nStack\tA\tB\n ");
}
