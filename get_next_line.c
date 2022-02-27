#include "so_long.h"

int BUFFER_SIZE = 1337;

char	*ft_strdup(char *s);
char *get_next_line(int fd)
{
	char	line[5000000] = {0};
	int		i = 0;
	while (read(fd, &line[i], 1) > 0)
		if (line[i++] == '\n')
			break ;
	return ((line[0] != 0 && BUFFER_SIZE > 0)? ft_strdup(line) : NULL);
}

char	*ft_strdup(char *s)
{
	char	*s1;
	int		i = 0;
	while (s[i])
		i++;
	s1 = malloc(i + 1);
	i = 0;
	while (s[i])
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = 0;
	return (s1);
}