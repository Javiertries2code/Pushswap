#include "../push.h"

void	pa(t_list **ends, void *print_fun)
{
	t_list	*tmp;

	if (ends[2] == NULL || !ends[3] || !print_fun)
		return ;
	tmp = ends[3];
	if (ends[3]->prev)
	{
		ends[3]->prev->next = NULL;
		ends[3] = ends[3]->prev;
	}
	else
	{
		ends[2] = NULL;
		ends[3] = NULL;
	}
	tmp->next = NULL;
	if (ends[1])
		ends[1]->next = tmp;
	tmp->prev = ends[1];
	ends[1] = tmp;
	if (!ends[0])
		ends[0] = ends[1];
}
