#include "../push.h"

// WHEN PLACING THE CURSOUR OVER THE FUNCION, IT SPARES THE
	//* FROM THE NAME OF THE POINTER

// chosingwhat stack to order in here, sending stack letter,
	//and may be INITIAL_SET
void	set_element_stack(t_list *tail, t_list *head, int init_stack, char stack);
void	set_stack(t_list *head, t_list *tail, int init_stack, char stack);


void	count_set(t_list **ends, int init_stack)
{
	set_stack(ends[0], ends[1], init_stack, 'A');
	set_stack(ends[2], ends[3], init_stack, 'B');
	// set_stack(ends, init_stack, 'A');
	// set_stack(ends, init_stack, 'B');
}

// looping in loop, sending init or set signal, stack letter,
//	and calling set elemtns

void	set_stack(t_list *head, t_list *tail, int init_stack, char stack)
{//creating end to fit in., it owuld make problems with free and so
	
	if (!head)
		return ;
		
	while (head)
	{
		while (tail)
		{
			set_element_stack(tail, head, init_stack, stack);
			if (tail->x == head->x && head != tail)
				exiting("Error\n", NULL, NULL);
			if (tail->prev)
				tail = tail->prev;
			else
			{
				//tail = ends[1];
				break ;
			}
		}
		if (head->next)
			head = head->next;
		else
			break ;
	}
}

void	set_element_stack(t_list *tail, t_list *head, int init_stack __attribute__((unused)), char stack __attribute__((unused)))
{
	// init_stack = (void)init_stack;
	// stack = (void)stack;

	 if (init_stack == INITIAL_SET)
	{
		if (tail->x > head->x)
			tail->smaller++;
		if (tail->x < head->x) // not else cuuse the == would fuck up
			tail->bigger++;
	}
	else
	{
		if (tail->x > head->x)
			tail->smaller_stack++;
		if (tail->x < head->x) // not else cuuse the == would fuck up
			tail->bigger_stack++;
	}
}
