
#include "push.h"

int	main(int argc, char *argv[])
{
	int i;
	t_list *ends[4];
	t_data *datarr[2];

	i = 0;


	t_data *data_A = 	ft_calloc(1 ,sizeof(t_data));
	t_data *data_B =	ft_calloc(1, sizeof(t_data));
	ends[0] = NULL;
	ends[1] = NULL;
	ends[2] = NULL;
	ends[3] = NULL;
	datarr[0] = data_A;
	datarr[1] = data_B;
	basic_valid(argc, argv, datarr);
	while (++i < argc)
		val_split(argv[i], ends, datarr);
	//PASSING NULLS TO SAVE LINES IN duplicate
	find_duplicate(ends, NULL, NULL);

	map_list(ends, ends[0]);

	sorting(ends);

	//radix(ends, 0);

	free_ahead(ends[0]);
	free_ahead(ends[2]);
	free(data_A);
	free(data_B);
	return (0);
}