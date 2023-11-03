#include "push.h"

// If there are at least two previos elementes, if not
// the second conditioin will check if at least there is two elemnts
// it would do nothing in third case
// when having only two members, it should also be changed the head *
void	sa(t_list **ends)
{
	t_list	*tmp;

	if ( ends[1] == NULL || ends[1]->prev == NULL)
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

void	sb(t_list **ends)
{
	t_list	*tmp;
printf("\naddress ends[3] sb  - %p\n", ends[3]);
	if (ends[3] == NULL || ends[3]->prev == NULL )
	{
	
		return ;
	}
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
