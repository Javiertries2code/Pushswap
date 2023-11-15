#include "push.h"

//counting and placing list index in proper order, returning count as to use it in condiciones
int	count_index(t_list **ends, t_data *data)
{
	int count = 0;
	while (ends[0])
	{
		count++;
		if (ends[0]->next)
		{
			ends[0] = ends[0]->next;
			ends[0]->index = count;
		}
		else
			break ;
	}
	return (count);
}