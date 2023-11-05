#include "push.h"

/*Si no se especifican parámetros, el programa no deberá mostrar nada y deberá
devolver el control al usuario.
• En caso de error, deberá mostrar Error seguido de un “\n” en la salida de er-
rores estándar. Algunos de los posibles errores son: argumentos que no son enteros,
argumentos superiores a un número entero, y/o encontrar números duplicados.*/

find_duplicate(long long int num, char **numbers)
{
    int i;
    i = 1;
    while(numbers[i])
        if(ft_atoi(numbers[i++]) == num)
            return (1);
    return (NULL);
}


val_input(int argc, char *argv[])
{
    long long int num;
     if (argc < 2)
        exit(1);
    //PENDING TO DO THE SPLIT CHAECK FOR  ' ' OR STNG
    
    //not sure in here  if when exiting it does keeps the memory of the caling function somewhere.
    //gotta make sure is not > maxint., may be using long in first place
    //looking for . or , in the string to avoid floats, i can do this in the atoi, char by char
    while (--argc > 0)
    {
        if(ft_strchr(argv[argc], '.') || ft_strchr(argv[argc], '.'))
             print_fun("Error", ERROR);
        if(ft_atoi(argv[argc] > INT_MAX) || ft_atoi(argv[argc] < INT_MIN))
            print_fun("Error", ERROR);
        if (sizeof(argv[argc -1]) != sizeof(int))
            print_fun("Error", ERROR);
        if(find_duplicate(ft_atoi(argv[argc]), argv))
            print_fun("Error", ERROR);
    }
}