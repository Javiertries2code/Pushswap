#include "../push.h"

void	map_list(t_list **ends, t_list *head)
{
	int	num_elements;

	num_elements = ends[0]->index;
	ends[0]->data_A->stack_size = ends[0]->index;
	head->data_A->map_index = 1;
	find_max(head);
	find_min_abs(head);
	while (num_elements > 0)
	{
		assign_index(ends);
		find_min_rel(ends[0]);
		num_elements--;
	}
}
void	find_max(t_list *head)
{
	int	max;

	max = head->x;
	while (head)
	{
		if (max < head->x)
			max = head->x;
		if (head->next)
			head = head->next;
		else
			break ;
	}
	head->data_A->stack_max = max;
}

void	find_min_rel(t_list *head)
{
	int	min;

	min = head->data_A->stack_max;
	while (head)
	{
		if (min > head->x && head->xmap == 0)
			min = head->x;
		if (head->next)
			head = head->next;
		else
			break ;
	}
	head->data_A->stack_min = min;
}

void	find_min_abs(t_list *head)
{
	int	min;

	min = head->x;
	while (head)
	{
		if (min > head->x)
			min = head->x;
		if (head->next)
			head = head->next;
		else
			break ;
	}
	head->data_A->stack_min = min;
	head->data_A->map_index = 1;
}

void	assign_index(t_list **ends)
{
	t_list *head;

	head = ends[0];
	while (head)
	{
		if (head->x == head->data_A->stack_min)
			head->xmap = head->data_A->map_index++;
		if (head->next)
			head = head->next;
		else
			break ;
	}
}