
#include "push.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_list	*ends[4];
	t_data	*datarr[2];
	t_data	*data_A;
	t_data	*data_B;

	i = 0;
	data_A = ft_calloc(1, sizeof(t_data));
	data_B = ft_calloc(1, sizeof(t_data));
	ends[0] = NULL;
	ends[1] = NULL;
	ends[2] = NULL;
	ends[3] = NULL;
	datarr[0] = data_A;
	datarr[1] = data_B;
	basic_valid(argc, argv, datarr);
	while (++i < argc)
		val_split(argv[i], ends, datarr);
	find_duplicate(ends, NULL, NULL);
	map_list(ends, ends[0]);
	sorting(ends);
	extrafree(ends, data_A, data_B);
	return (0);
}
void extrafree(t_list **ends, t_data *data_A, t_data *data_B)
{
	free_ahead(ends[0]);
	free_ahead(ends[2]);
	free(data_A);
	free(data_B);
}
