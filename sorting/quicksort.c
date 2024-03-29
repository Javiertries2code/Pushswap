#include "../push.h"

void	sorting_five(t_list **ends, int pv)
// gotta check existance in case of
{
	// i gottapass pt_lit pointers otherwise will fuckup later
	// tail_a = ends[1];
	// tail_b = ends[3];
	// printf("\nends[1]->x\t %d\tends[1]->data_A->head_value\t%d \tpv - %d\n",
	// tail_a->x, tail_a->data_A->head_value, tail_a->data_A->pv);
	// ends[1] should be updated after every handler
	while (ends[1] && ends[1]->x != ends[1]->data_A->head_value)
	{
		printf("ends[1]->x %d\t ends[1] \t%d\n", ends[1]->x,
			ends[1]->data_A->pv);
		usleep(50000);

		if (ends[1]->x < pv)
			pb(ends, print_fun("pb"));
		else if (ends[1]->x > pv)
			ra(ends, print_fun("ra"));
		else if (ends[1]->x == pv)
			sa(ends, print_fun("sa"));
	}
	print_stack(ends);
	usleep(50000);
	count_set(ends);

	if (ends[0]->x < ends[0]->next->x) // ultimo A< penultimo A
	{
		if (ends[3]->x > ends[3]->prev->x)      // ultimo B > penultimo B,
			rr(ends, print_fun("rr"));          // revers both,
		else if (ends[3]->x < ends[3]->prev->x) // as before,not touching B
			ra(ends, print_fun("ra"));
		sa(ends, print_fun("sa"));   // two uppers swithed
		rra(ends, print_fun("rra")); // pv back to place
	}
	else if (ends[0]->x > ends[0]->prev->x) // ultimo A, penultimo A OK
		if (ends[3]->x < ends[3]->prev->x)  // B gotta switch
			sb(ends, print_fun("sb"));
	pa(ends, print_fun("pa"));
	pa(ends, print_fun("pa"));
}
