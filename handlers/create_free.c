#include "../push.h"

void	free_backwards(t_list *tail)
{
	t_list	*tmp;

	while (tail)
	{
		tmp = tail->prev;
		free(tail);
		tail = tmp;
	}
}

void	free_ahead(t_list *head)
{
	t_list	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

t_list	*new_element(t_list *current, int x, int index)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		exit(1);
	current->next = new;
	new->prev = current;
	new->x = x;
	new->index = index;
	new->next = NULL;
	return (new);
}
