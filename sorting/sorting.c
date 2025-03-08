#include "../push.h"
void testing(t_list **ends){
	print_stack(ends);
//rev_stack(ends);
sleep(4);
	
pb(ends, print_fun("pb"));
pb(ends, print_fun("pb"));
print_stack(ends);


sleep(4);
sb(ends, print_fun("sb"));
pa(ends, print_fun("pa"));
pa(ends, print_fun("pa"));
print_stack(ends);


}


void	sorting(t_list **ends)
{
	print_stack(ends);
	rev_stack(ends);
	count_set(ends);
	sleep(4);
	already_ordered(ends);
	if (ends[1]->index < 2)
		exiting("YW", NULL, ends);
	if (ends[1]->index == 2 && ends[0]->x > ends[1]->x)
	{
		sa(ends, print_fun("sa"));
		exiting("YW", NULL, ends);
	}
	else if (ends[1]->index == 2 && ends[0]->x < ends[1]->x)
		exiting("YW", NULL, ends);
	else if (ends[1]->index == 3)
	{
		sorting_three(ends);
		exiting("YW", NULL, ends);
	}
	else if (ends[1]->index <= 5)
		sorting_four_five(ends);
	else
		radix(ends, 0);
}


void sorting_three(t_list **ends)
{
	if (ends[1]->x < ends[1]->prev->x && ends[1]->prev->x < ends[0]->x)
		return;
	if (ends[1]->x > ends[1]->prev->x && ends[1]->prev->x > ends[0]->x)
	{
		ra(ends, print_fun("ra"));
		sa(ends, print_fun("sa"));
	}
	else if (ends[1]->prev->x > ends[0]->x)
	{
		if (ends[1]->x < ends[0]->x)
		{
			sa(ends, print_fun("sa"));
			ra(ends, print_fun("ra"));
		}
		else if (ends[1]->x < ends[1]->prev->x)
			rra(ends, print_fun("rra"));
	}
	else if (ends[1]->prev->x < ends[0]->x)
		solve_one_middle(ends);

	
}

void solve_one_middle(t_list **ends)
{

	if (ends[1]->x < ends[0]->x)
	{
		sa(ends, print_fun("sa"));
	}
	else if (ends[1]->x > ends[0]->x)
	{
		ra(ends, print_fun("ra"));
	}
	else if (ends[1]->prev->x < ends[0]->x)
	{
		rra(ends, print_fun("rra"));
	}
}

// void	sorting_three(t_list **ends)
// {
// 	if (ends[1]->x > ends[1]->prev->x && ends[1]->prev->x > ends[0]->x)
// 		// 1 2 3 ok
// 		return ;
// 	if (ends[1]->x < ends[1]->prev->x && ends[1]->prev->x < ends[0]->x)
// 		// 3 2 1ok
// 	{
// 		ra(ends, print_fun("ra"));
// 		sa(ends, print_fun("sa"));
// 	}
// 	else if (ends[1]->prev->x > ends[0]->x)
// 	{
// 		if (ends[1]->x < ends[0]->x) 
// 			ra(ends, print_fun("ra"));
		
// 		else if (ends[1]->x < ends[1]->prev->x)
// 			sa(ends, print_fun("sa"));
	
// 	}
// 	else if (ends[1]->prev->x < ends[0]->x)
// 		solve_one_middle(ends);
// }

// void	solve_one_middle(t_list **ends)
// {
	
// 	if (ends[1]->x < ends[0]->x)
// 		rra(ends, print_fun("rra"));
// 	else if (ends[1]->x > ends[0]->x)
// 	{
// 		rra(ends, print_fun("rra"));
// 		sa(ends, print_fun("sa"));

// 	}

// }