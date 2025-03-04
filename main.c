
#include "push.h"

int	main(int argc, char *argv[])
{
	int i;
	t_list *ends[4];
	t_data *datarr[2];

	i = 0;
	if (argc == 1)
		return 0;

	if (argc < 2 || (argc == 2 && counter(argv[1], ' ') == 1 ))
		exiting(NULL, NULL, NULL);

	t_data *data_A = 	ft_calloc(1 ,sizeof(t_data));
	t_data *data_B =	ft_calloc(1, sizeof(t_data));
	ends[0] = NULL;
	ends[1] = NULL;
	ends[2] = NULL;
	ends[3] = NULL;
	datarr[0] = data_A;
	datarr[1] = data_B;
	while (++i < argc)
		val_split(argv[i], ends, datarr);
	//PASSING NULLS TO SAVE LINES IN duplicate
	find_duplicate(ends, NULL, NULL);

	map_list(ends, ends[0]);
	radix(ends, 0);

	free_ahead(ends[0]);
	free_ahead(ends[2]);
	free(data_A);
	free(data_B);
	return (0);
}