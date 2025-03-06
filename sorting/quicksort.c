#include "../push.h"
// just did it, hope it works, lets do smae with 5, some counters will be added
void sorting_four(t_list **ends)
{

	printf("sorting four\n");
	print_stack(ends);
	int i;

	t_list *head;

	head = ends[1];

	while (head)
	{
		printf("\nSENT higest  i %d\n", head->x);

		i = highest_second(ends[0], head->x);
		printf("\nRETURNED higest  i %d\n", i);
		head = head->prev;
		if (i == 0)
		{
			pb(ends, print_fun("pb"));
			break; 
		}
		else
			ra(ends, print_fun("ra"));


		
		
		
	}
	

	sorting_three(ends);
	pa(ends, print_fun("pa"));
}

void sorting_five(t_list **ends)
{

	printf("sorting five");

	int i;
	int j;
	t_list *head;

	head = ends[0];
	j = 2;
	while (j)
	{
		i = highest_second(ends[0], ends[0]->x);
		if (i == 0)
			pb(ends, print_fun("pb"));
		if (head->next)
			head = head->next;
		j--;
	}
	sorting_three(ends);
	if (ends[3]->x < ends[3]->prev->x)
	{
		pa(ends, print_fun("pa"));
		pa(ends, print_fun("pa"));
	}
	else
	{
		sa(ends, print_fun("sa"));
		pa(ends, print_fun("pa"));
		pa(ends, print_fun("pa"));
	}
}

void sorting_four_five(t_list **ends)
{
	if ((ends[1]->index) == 4)
		{sorting_four(ends);
			print_stack(ends);}
	else if (ends[1]->index == 5)
		{sorting_five(ends);
			print_stack(ends);}

	exiting("YW", NULL, ends);
}

/**going troghthe list, so will add i++ for every larger number found,
 * if i happenst o be 0. will be the higest, if 1 second higest
 *
 */

int highest_second(t_list *head, int value)
{
	printf(" value recived highes   %d  \n", value);

	int i;

	i = 0;
	while (head)
	{
		if (head->x < value)
			i++;

		printf("head->x %d  value i  %d  \t\t\thighest_second\n", head->x, i);

			head = head->next;
		
	}
	return i;
}