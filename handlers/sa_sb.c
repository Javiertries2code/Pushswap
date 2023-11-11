#include "../push.h"

void	sa(t_list **ends, void *print_fun)
{
	t_list	*tmp;

	if (ends[1] == NULL || !ends[1]->prev || !print_fun)
		return ;
	tmp = ends[1]->prev;
	if (ends[1]->prev->prev)
	{
		ends[1]->prev->prev->next = ends[1];
		ends[1]->prev = ends[1]->prev->prev;
		ends[1]->next = tmp;
		tmp->prev = ends[1];
		tmp->next = NULL;
		ends[1] = tmp;
	}
	else if (ends[1]->prev && !ends[1]->prev->prev)
	{
		ends[0] = ends[1];
		ends[1] = tmp;
		ends[0]->prev = NULL;
		ends[0]->next = ends[1];
		ends[1]->prev = ends[0];
		ends[1]->next = NULL;
	}
}

void	sb(t_list **ends, void *print)
{
	t_list	*tmp;

	if (ends[3] == NULL || !ends[3]->prev || !print)
		return ;
	tmp = ends[3]->prev;
	if (ends[3]->prev->prev)
	{
		ends[3]->prev->prev->next = ends[3];
		ends[3]->prev = ends[3]->prev->prev;
		ends[3]->next = tmp;
		tmp->prev = ends[3];
		tmp->next = NULL;
		ends[3] = tmp;
	}
	else if (ends[3]->prev && !ends[3]->prev->prev)
	{
		ends[2] = ends[3];
		ends[3] = tmp;
		ends[2]->prev = NULL;
		ends[2]->next = ends[3];
		ends[3]->prev = ends[2];
		ends[3]->next = NULL;
	}
}
