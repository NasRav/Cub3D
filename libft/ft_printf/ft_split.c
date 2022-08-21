#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	**arr_alloc(char *s, char c)
{
	int		i;
	char	**arr;

	i = 1;
	while (*s)
	{
		if (*s == c && *(s + 1) != c)
			i++;
		s++;
	}
	arr = (char **)malloc(sizeof(char *) * i);
	if (!arr)
		return (0);
	arr[i - 1] = NULL;
	return (arr);
}

int	str_len(char **s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c && *(s + 1) != c)
			break;
		s++;
	}
	while (*s || *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char	*write_line(char **s, char c)
{
	int		i;
	int		l;
	char	*line;

	i = 0;
	l = str_len(&s, c);
	line = (char *)malloc(sizeof(char) * (l + 1));
	if (!line)
		return (0);
	while (i < l)
	{
		line[i] = *(s - l + 1);
		s++;
		i++;
	}
}
/*
char	**ft_split(char const *s, char c)
{
	char	**arr;

	arr = arr_alloc(s, c);
	return (arr);
}
*/
int	main(void)
{
	char	s[14] = "Hello, World!";
	char	c = 'o';

	return (0);
}
