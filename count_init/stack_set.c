#include "../push.h"

void	set_stack(t_list *head, t_list *tail, char stack)
{
	t_list	*aux;

	if (!head)
		return ;
	aux = tail;
	while (head)
	{
		head->index++;
		head->stack = stack;
		while (tail)
		{
			set_element_stack(tail, head);
			if (tail->x == head->x && head != tail)
				exiting("Error\n", NULL, NULL);
			if (tail->prev)
				tail = tail->prev;
			else
			{
				tail = aux;
				break ;
			}
		}
		if (head->next)
			head = head->next;
		else
			break ;
	}
}
void	reset_stack(t_list *head, char stack)
{
	while (head)
	{
		head->smaller = 0;
		head->bigger = 0;
		head->bigger_stack = 0;
		head->smaller_stack = 0;
		head->stack = stack;
		if (head->next)
			head = head->next;
		else
			break ;
	}
}
void	set_element_stack(t_list *tail, t_list *head)
{
	if (tail->x > head->x)
		tail->smaller++;
	if (tail->x < head->x)
		tail->bigger++;
}