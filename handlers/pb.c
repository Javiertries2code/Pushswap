#include "../push.h"

void	pb(t_list **ends, void *print_fun)
{
	t_list *tmp;

	if (ends[0] == NULL || ends[1] == NULL || !print_fun)
		return ;
	tmp = ends[1];
	if (ends[1]->prev)
	{
		ends[1]->prev->next = NULL;
		ends[1] = ends[1]->prev;
	}
	else
	{
		ends[0] = NULL;
		ends[1] = NULL;
	}
	tmp->next = NULL;
	if (ends[3])
		ends[3]->next = tmp;
	tmp->prev = ends[3];
	ends[3] = tmp;
	if (!ends[2])
		ends[2] = ends[3];
}


void	pass_b(t_list **ends)
{
	t_list *tmp;

	if (ends[0] == NULL || ends[1] == NULL )
		return ;
	tmp = ends[1];
	if (ends[1]->prev)
	{
		ends[1]->prev->next = NULL;
		ends[1] = ends[1]->prev;
	}
	else
	{
		ends[0] = NULL;
		ends[1] = NULL;
	}
	tmp->next = NULL;
	if (ends[3])
		ends[3]->next = tmp;
	tmp->prev = ends[3];
	ends[3] = tmp;
	if (!ends[2])
		ends[2] = ends[3];
}