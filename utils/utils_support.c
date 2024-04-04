 #include "../push.h"
/**
 * @brief  allocates memory wih initial value 0 for every bit
 * 
 * @param count number of elements
 * @param size size of the type of data (sizeof)
 * @return void* to the newly reserved slot of memory, else NULL.
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
 * @brief Counts the lenght of an String, number of characters, excluded
 *  the closing chracter. "HOLA" returns 4
 * 
 * @param s 
 * @return size_t  the number of caracters
 */

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}