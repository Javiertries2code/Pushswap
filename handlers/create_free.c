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

void	new_element(t_list **ends, char *x)
{
	t_list *new;

	new = calloc(1, sizeof(t_list));
	if (new == NULL)
		exiting("failed to malloc for new element");
			// Gotta do an exit function i see
	if (!ends[0])
		{
	new->prev = NULL;
	new->next = NULL;
	new->index = 1;
	new->x = ft_atoi(x);
	ends[0] = new;
	ends[1] = new;
		}
		
	else
	{new->prev = ends[1];
	ends[1]->next = new;
	new->next = NULL;
	new->index = ends[1]->index + 1;
	new->x = ft_atoi(x);
	ends[1] = new;}
}
