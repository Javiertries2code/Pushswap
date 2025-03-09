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
