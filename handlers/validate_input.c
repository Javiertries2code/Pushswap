#include "../push.h"

int	count_split(char **argv)
{
	int	count;

	count = 0;
	while (argv[count] != NULL)
		count++;
	return (count);
}
/*Si no se especifican parámetros, el programa no deberá mostrar nada y deberá
devolver el control al usuario.
• En caso de error, deberá mostrar Error seguido de un “\n” en la salida de er-
rores estándar. Algunos de los posibles errores son: argumentos que no son enteros,
argumentos superiores a un número entero, y/o encontrar números duplicados.*/

int	find_duplicate(long long int num, char **numbers)
{
	int	i;

	i = 1;
	while (numbers[i])
		if (ft_atoi(numbers[i++]) == num)
			return (1);
	return (0);
}

void val_input(int argc, char *argv[], int eval)
{
	//long long int num;
	char **numbers;
	if (argc < 2)
		exit(1);
	else if (argc == 2 && !(ft_strchr(argv[1], ' ') || ft_strchr(argv[1], '\t')))
		print_fun("Error one number", ERROR, NULL);
	else if (argc == 2 && (ft_strchr(argv[1], ' ') || ft_strchr(argv[1], '\t')))
	{
		numbers = (char **)ft_split(argv[1], ' '); // separadno por espacios
		argc = count_split(numbers);
        eval = ND_EVAL;
	}
	// not sure in here  if when exiting it does keeps the memory of the caling function somewhere.
	// gotta make sure is not > maxint., may be using long in first place
	// looking for . or , in the string to avoid floats,
		//i can do this in the atoi, char by char
	// THE IF TEST DOWN ERE, SHOULD BE CHAIND WITH ELSE IF FOR RELIABILITY,
		//WITH ERR SIGN
	// THEN FREE ARGV IF WE HAVE CRETED IT IN SOME IF FUNCION WITH SPLIT. changin eval from st to nd
	// in such a case, no need to call the funcion again
	while (--argc > eval) // HERE the eval thing, in case we splitted
	{
		if (ft_strchr(argv[argc], '.') || ft_strchr(argv[argc], '.'))
			print_fun("Error floats", ERROR, NULL);
		//else if ((ft_atoi(argv[argc]) > (long long int)INT_MAX)) || (ft_atoi(argv[argc]) < (long long int)INT_MIN)
			//print_fun("Error out of MAX MIN int range", ERROR, NULL);
		else if (find_duplicate(ft_atoi(argv[argc]), argv))
			print_fun("Error", ERROR, NULL);
	}
}