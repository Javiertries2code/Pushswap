#include "../push.h"

void	ra(t_list **ends, void *print_fun)
{
	t_list	*tmp;

	if (!ends[1] || !ends[1]->prev || !print_fun)
		return ;
	tmp = ends[1]->prev;
	ends[0]->prev = ends[1];
	ends[1]->prev->next = NULL;
	ends[1]->prev = NULL;
	ends[1]->next = ends[0];
	ends[0] = ends[1];
	ends[1] = tmp;
}
