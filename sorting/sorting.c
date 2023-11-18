#include "../push.h"

/*void	test_sort(t_list **ends, t_list *tmp)
{
	
}*/
void	sorting(t_list **ends)
{
	count_set(ends);
	//find_pv(ends, NULL); a'ready in count set
	if (ends[1]->index < 2)
		return ;
	else if (ends[1]->index == 2 && ends[0]->x > ends[1]->x)
		sa(ends, print_fun("sa"));
	else if (ends[0]->index == 2 && ends[0]->x < ends[1]->x)
		return ; // or the other way around
	else if (ends[1]->index == 3)
		sorting_three(ends);
	else if (ends[1]->index <= 5)
		sorting_five(ends, ends[0]->data_A->pv); //trying to save lines
	// else
	// 	sort_bulk(ends);
}

void	sorting_three(t_list **ends)
{
	if (ends[1]->x < ends[1]->prev->x && ends[1]->prev->x < ends[0]->x)
		return ; // 123 OK
	if (ends[1]->x > ends[1]->prev->x && ends[1]->prev->x > ends[0]->x)
	{ // 321
		ra(ends, print_fun("ra"));
		sa(ends, print_fun("sa"));
	}
	else if (ends[1]->prev->x > ends[0]->x)
	{
		if (ends[1]->x < ends[0]->x) // 132
		{
			sa(ends, print_fun("sa"));
			ra(ends, print_fun("ra"));
		}
		else if (ends[1]->x < ends[1]->prev->x) // 231
			rra(ends, print_fun("rra"));
	}
	else if (ends[1]->prev->x < ends[0]->x)
	{ // 213
		if (ends[1]->prev->x < ends[1]->x)
			sa(ends, print_fun("sa"));
		else if (ends[1]->prev->x < ends[0]->x) // 312
			rra(ends, print_fun("rra"));
	}
}
