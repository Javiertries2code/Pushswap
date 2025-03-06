#include "../push.h"



// para buscar coma o punto
// int				i;
// i = 0;
// sobraba parece ser
char	*ft_strchr(const char *s, int c)
{
	unsigned int	len;

	len = ft_strlen(s);
	if (!s)
		return (NULL);
	if ((char)c == '\0')
		return ((char *)&s[len]);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

/**
 * @brief Neccesary part for the split function,
	a per my libft i suppose... WAKE up Javier, Wake up
 * it copies into a provided char *dst,
	the dstsize number of characters from src. closes wit '\0'  extra scpace provided
 * it returns the number of copied characters,
	that i bet i didnt controlles the error yet
 *
 * @param dst
 * @param src
 * @param dstsize
 * @return size_t
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	ncopied;
	size_t	i;

	ncopied = ft_strlen(src);
	i = 0;
	if (dstsize)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ncopied);
}

size_t	counter(const char *s, char c)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			counter++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (counter);
}

static char	*new_str(const char *s, char c)
{
	size_t	len;
	char	*ptr;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}

char	**ft_split(const char *s, char c)
{
	char **ptr;
	size_t i;
	size_t j;

	if (!s)
		return (NULL);
	ptr = (char **)ft_calloc(counter(s, c) + 1, sizeof(char *));
	if (!ptr)
		return (NULL);
	while (*s == ' ' || *s == '\t')
		s++;
	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] != c)
		{
			ptr[i++] = new_str(&(s[j]), c);
			while (s[j] && s[j] != c)
				j++;
		}
		else
			j++;
	}
	return (ptr);
}