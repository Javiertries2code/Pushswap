#include "../push.h"

//counting and placing list index in proper order, returning count as to use it in condiciones
void	count_index(t_list **ends)
{
	int count = 0;
	t_list *head;
	head = ends[0];
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