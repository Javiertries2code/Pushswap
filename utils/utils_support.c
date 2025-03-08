#include "../push.h"

long long int	ft_atoi(const char *str)
{
	int				sign;
	long long int	num;
	int				i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' '
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -sign;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = 10 * num;
		num = num + str[i] - '0';
		i++;
	}
	num *= sign;
	if (num > INT_MAX || num < INT_MIN)
		return (MIN_MAX_ERROR);
	return (num);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*str;

	str = (char *)s;
	i = 0;
	while (i < n)
		str[i++] = '\0';
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
