#include "push.h"

void	*print_fun(char *str, int num)
{
	if (num == ERROR)
	{
		write(1, "Error\n", 7);
		exit(1);
	}
	write(1, str, num);
	write(1, "\n", 1);
	return (NULL);
}

long long int	ft_atoi(const char *str)
{
	int	            sign;
	long long int	num;
	int	            i;

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
	return (num);
}

//para buscar coma o punto
char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned int	len;

	len = ft_strlen(s);
	i = 0;
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