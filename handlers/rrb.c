#include "../push.h"

void	rrb(t_list **ends, void *print_fun)
{
	t_list	*tmp;

	if (!ends[2] || !ends[2]->next || !print_fun)
		return ;
	tmp = ends[2]->next;
	ends[3]->next = ends[2];
	tmp->prev = NULL;
	ends[2]->next = NULL;
	ends[2]->prev = ends[3];
	ends[3] = ends[2];
	ends[2] = tmp;
}
void	turn(t_list **ends)
{
	t_list	*tmp;

	if (!ends[2] || !ends[2]->next )
		return ;
	tmp = ends[2]->next;
	ends[3]->next = ends[2];
	tmp->prev = NULL;
	ends[2]->next = NULL;
	ends[2]->prev = ends[3];
	ends[3] = ends[2];
	ends[2] = tmp;
}