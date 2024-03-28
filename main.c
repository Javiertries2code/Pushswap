
#include "push.h"
/**
 * @brief Creating begining and ends of list, sama as dataarr that will store
 * necessary info in an struct inside the t_list struct.
 * tmp is not clear why i used it for, will chaeck later
 * @file main.c
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main(int argc, char *argv[])
{
	int i;
	t_list *tmp; // additional lines could be saved by adding tmp to ends[5]
	t_list *ends[4];
	t_data *datarr[2];
	i = 0;

	if (argc < 2)
		exit(1);

	
	tmp = ft_calloc(1, sizeof(t_list));
	if (!tmp)
		exit(1);
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


	
	 print_stack(ends);

	free_ahead(ends[0]);
	free_ahead(ends[2]);
	free(tmp);

	return (0);
}