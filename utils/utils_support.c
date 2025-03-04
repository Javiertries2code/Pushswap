 #include "../push.h"
/**
 allocates memory wih initial value 0 for every bit
 * 

 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

/**
 *Counts the lenght of an String, number of characters, excluded
 *  the closing chracter. "HOLA" returns 4

 */

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}