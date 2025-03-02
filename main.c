
#include "push.h"

int	main(int argc, char *argv[])
{
	int i;
	t_list *tmp; // additional lines could be saved by adding tmp to ends[5]
	t_list *ends[4];
	i = 0;

	if (argc < 2)
		exit(1);

	// tmp = ft_calloc(4, sizeof(t_list));
	tmp = ft_calloc(1, sizeof(t_list));
	if (!tmp)
		exit(1);
	//to save one line of needed
	// 	i = -1;
	// while(++i < 4)
	// 	ends[i] = NULL;

	ends[0] = NULL;
	ends[1] = NULL;
	ends[2] = NULL;
	ends[3] = NULL;
	while (++i< argc)
		new_element(ends, argv[i]);
	
	pb(ends, print_fun("pb", 2, NULL));
	sb(ends, print_fun("sb", 2, NULL));
	rrr(ends, print_fun("rrr", 2, NULL));
	ss(ends, tmp, 1, print_fun("ss", 2, NULL));

	print_stack(ends);
	free_ahead(ends[0]);
	free_ahead(ends[2]);
	free(tmp);

	return (0);
}