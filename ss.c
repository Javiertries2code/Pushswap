#include "push.h"

// if it doesnt fit by lines, i can be sent i and temp as a parameter. perfect fit
//void	ss(t_list **ends);
void	ss(t_list **ends, t_list *tmp, int i,  void *print)
{
	//t_list *tmp;

	//int i;
	if (!ends[1] || !ends[3] || !ends[1]->prev || !ends[3]->prev || !print)
		return ;
	//i = 1;
	while (i != 5)
	{
		tmp = ends[i]->prev;
		if (ends[i]->prev->prev)
	{
		ends[i]->prev->prev->next = ends[i];
		ends[i]->prev = ends[i]->prev->prev;
		ends[i]->next = tmp;
		tmp->prev = ends[i];
		tmp->next = NULL;
		ends[i] = tmp;
	}
	else if (ends[i]->prev && !ends[i]->prev->prev)
	{
		ends[1 - i] = ends[i];
		ends[i] = tmp;
		ends[1 - i]->prev = NULL;
		ends[1 - i]->next = ends[i];
		ends[i]->prev = ends[1 - i];
		ends[i]->next = NULL;
	}
		i = i + 2;
	}
}