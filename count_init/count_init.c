

#include "../push.h"

void	set_element_stack(t_list *tail, t_list *head);
void	set_stack(t_list *head, t_list *tail, char stack);
void	count_index(t_list *head);

void	count_set(t_list **ends)
{
	if (ends[0])
	{
		reset_stack(ends[0], 'A');
		set_stack(ends[0], ends[1], 'A');
		count_index(ends[0]);
		ends[0]->data_A->head_value = ends[0]->x;
		ends[0]->data_A->tail_value = ends[1]->x;
		{
		}
		if (ends[2])
		{
			reset_stack(ends[2], 'B');
			set_stack(ends[2], ends[3], 'B');
			count_index(ends[2]);
			ends[2]->data_A->head_value = ends[2]->x;
			ends[2]->data_A->tail_value = ends[3]->x;
		}
	}
}

void	count_index(t_list *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		head->index = count;
		if (head->next)
			head = head->next;
		else
			break ;
	}
}