
#include "push.h"

int	main(int argc, char *argv[])
{
	int i;
	t_list *current_a;

	t_list *ends[4];
	if (argc < 2)
		exit(1);
	current_a = malloc(sizeof(t_list));
	if (current_a == NULL)
		exit(1);
	current_a->x = atoi(argv[1]);
	// this index goes as a counting check, not necessary
	current_a->index = 1;
	current_a->prev = NULL;
	current_a->next = NULL;

	ends[0] = current_a;
	i = 2; // as agrv[1] ya esta
	while (i < argc)
	{
		current_a = new_element(current_a, atoi(argv[i]), i);
		i++;
	}
	ends[1] = current_a;
	ends[2] = NULL;
	ends[3] = NULL;
	//
	//

	print_stack(ends);
	free_ahead(ends[0]);
	
	return (0);
}