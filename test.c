#include "push.h"


void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*str;

	str = (char *)s;
	i = 0;
	while (i < n)
		str[i++] = '\0';
}
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

static size_t	counter(const char *s, char c)
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
	char	**ptr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	ptr = (char **)ft_calloc(counter(s, c) + 1, sizeof(char *));
	if (!ptr)
		return (NULL);
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

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int main()
{
char **result;
char **result2;
char* text = "Los caracteres de escape '";
    
char* text2 = "Los caracteres de escape cdafvfhdscscgshsfcfshvhchvsfcsfchvfdscsh en ";
result = ft_split(text, ' ');
result2 = ft_split(text2, ' ');
printf("size resutl \t%ld\n",sizeof(result)/sizeof (char *) ) ;
printf("size resutl2 \t%ld\n",sizeof(*result2)/sizeof (char *) );
}
