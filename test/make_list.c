#include "../push.h"

void	make_list(int i, char **numbers, t_list **ends)
{
	t_list *current_a;
	int index;

	current_a = (t_list *)calloc(sizeof(t_list));
	ends = (t_list **)calloc(4 , sizeof(t_list));
	// Calloc will NULL the pointer ->next ans so on.
	if (current_a == NULL || ends == NULL)
	{
		//yeah well, Im saving lines in here.
        free(current_a);
        free(ends[0]);
		exit(1);
	}
	// as i dont find a way not using a global to keep the value
	index = ends[1]->index;
    if ( !(ft_strchr(numbers, ' ') || ft_strchr(numbers, '\t')))
	{
		//In the validation i can go with checkin if theyr are number, 0 9, hear NOTES
		numbers = (char **)ft_split(numbers, ' '); // separadno por espacios
		index = count_split((void *)numbers);
         
	}
	current_a->x = (int)atoi(numbers[0]);
	// this index goes as a counting check, not necessary
    //I need a function here that checks and splits it all, validate, 
    //, then we can build the list, yeah?
	current_a->index = 1;
	current_a->prev = NULL;
	current_a->next = NULL;

	ends[0] = current_a;
	i = 1; // as agrv[1] ya esta

	while (i < j)
	{
		current_a = new_element(current_a, atoi(numbers[i]), i);
		i++;
	}
	ends[1] = current_a;
	ends[2] = NULL;
	ends[3] = NULL;
}