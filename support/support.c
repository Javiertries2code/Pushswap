#include "../push.h"

void	print(t_list *head)
{
	printf("PRINT\n");
	while (head)
	{
		printf("\nvalue    %d\n ", head->x);
		if (head->next)
			head = head->next;
		else
			break ;
	}
}

void	rprint(t_list *tail)
{
	printf("RPRINT\n");
	while (tail)
	{
		printf("\n       %d\n ", tail->x);
		if (tail->prev)
			tail = tail->prev;
		else
			break ;
	}
	printf("-----------------------\n");
	printf("--------Stack A---------------\n");
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
			printf("\n\tind -%d\t\t%d\t\t\t%d\tind -%d\n ", tail_a->index,
				tail_a->x, tail_b->x, tail_b->index);
		else if (tail_a && !tail_b)
			printf("\n\t\t\t%d\t\t\t-\n\tmapeado - %d\n", tail_a->x,
				tail_a->xmap);
		else if (!tail_a && tail_b)
			printf("\n\t\t\t-\t\t\t%d\tind -%d\n ", tail_b->x, tail_b->index);
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
	printf("\t-------------------------------------------\nStack\t\t\tA\t\t\tB\n ");
}

