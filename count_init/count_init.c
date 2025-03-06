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
		////PROBABLY UNUSED
		// find_pv(ends, NULL);
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
// PROBABLY UNUSED
// void	find_pv(t_list **ends, t_list *head)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 4)
// 	{
// 		head = ends[i];
// 		if (head)
// 		{
// 			while (head)
// 			{
// 				if ((head->bigger - head->smaller) == 0 && i == 0)
// 				{
// 					head->data_A->pv = head->x;
// 					break ;
// 				}
// 				if ((head->bigger - head->smaller) == 0 && i == 2)
// 				{
// 					head->data_B->pv = head->x;
// 					break ;
// 				}
// 				if ((head->bigger - head->smaller == -1 || head->bigger
// 						- head->smaller == 1) && i == 0)
// 					head->data_A->pv = head->x;
// 				if ((head->bigger - head->smaller == -1 || head->bigger
// 						- head->smaller == 1) && i == 2)
// 					head->data_B->pv = head->x;
// 				head = head->next;
// 			}
// 		}
// 		i += 2;
// 	}
// }
