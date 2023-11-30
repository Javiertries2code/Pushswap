#include "../push.h"

void	set_element_stack(t_list *tail, t_list *head);
void	set_stack(t_list *head, t_list *tail, char stack);
void	count_index(t_list *head);

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
		// count_index(ends);
		find_pv(ends, NULL);
	}
}
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

void	set_element_stack(t_list *tail, t_list *head)
{
	if (tail->x > head->x)
		tail->smaller++;
	if (tail->x < head->x)
		tail->bigger++;
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

// void	count_index(t_list **ends)
// {
// 	int count = 0;
// 	int i = 0;
// 	while (i != 2)
// 	{
// 		count = 0;
// 		if (ends[i])
// 		{
// 			while (ends[i])
// 			{
// 				count++;
// 				if (ends[i]->stack == 'A')
// 					if (ends[i]->x == ends[i]->data_A->pv)
// 						ends[i]->data_A->index = count;
// 				if (ends[i]->stack == 'B')
// 					if (ends[i]->x == ends[i]->data_B->pv)
// 						ends[i]->data_A->index = count;
// 				ends[i]->index = count;
// 				if (ends[i]->next)
// 					ends[i] = ends[i]->next;
// 				else
// 					break ;
// 			}
// 			i = i + 2;
// 		}
// 	}
// }