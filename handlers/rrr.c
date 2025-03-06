#include "../push.h"

void	rrr(t_list **ends, void *print_fun)
{
	t_list	*tmp;

	if (!ends[0] || !ends[2] || !ends[0]->next || !ends[2]->next || !print_fun)
		return ;
	tmp = ends[0]->next;
	ends[1]->next = ends[0];
	tmp->prev = NULL;
	ends[0]->next = NULL;
	ends[0]->prev = ends[1];
	ends[1] = ends[0];
	ends[0] = tmp;
	tmp = ends[2]->next;
	ends[3]->next = ends[2];
	tmp->prev = NULL;
	ends[2]->next = NULL;
	ends[2]->prev = ends[3];
	ends[3] = ends[2];
	ends[2] = tmp;
}
